from os import listdir
from os.path import isfile, isdir, join
import re

PATH = '/home/san/Algorithms/ReferenceExplained'
excluded = set(['ReferenceExplainedBook', '.vscode', '__pycache__'])
numberOfColumns = 2


def printSectionType(sectionName, depth, isFile):
    vspace = 0
    style = '\\bfseries\\sffamily\\centering'
    if depth == 1:
        sectionType = 'section'
        style += '\\Huge'
        vspace = 2
    elif depth == 2:
        sectionType = 'subsection'
        style += '\\LARGE'
        vspace = 1
    elif depth == 3:
        sectionType = 'subsubsection'
        style += '\\Large'
        vspace = 1
    else:
        sectionType = 'paragraph'
        style += '\\large'
        vspace = 1
    if isFile:
        sectionName = sectionName[:sectionName.rfind('.')]
        style = '\\large\\bfseries\\sffamily\\underline'
        vspace = 0
    print('\\' + sectionType + 'font{' + style + '}')
    if vspace:
        print('\\vspace{' + str(vspace - 1) + 'em}')
    print('\\' + sectionType + '*{' + sectionName + '}')
    if depth == 1:
        print('\\markboth{' + sectionName.upper() + '}{}')
    print('\\addcontentsline{toc}{' + sectionType + '}{' + sectionName + '}')
    if vspace:
        print('\\vspace{' + str(vspace + 1) + 'em}')


def needspaceForDepth(depth):
    if depth == 1:
        needspace = 4
    elif depth == 2:
        needspace = 3
    elif depth == 3:
        needspace = 2
    else:
        needspace = 1
    return needspace


def printFile(path, depth, sections):
    extension = sections[-1][sections[-1].rfind('.') + 1:]
    if extension == 'tex':
        print('\\end{multicols*}')
        for i in range(len(sections)):
            printSectionType(sections[i], depth -
                             len(sections) + i + 1, i == len(sections) - 1)
        print('\\input{"' + path + '"}')
        print('\\begin{multicols*}{' + str(numberOfColumns) + '}')
        return
    if extension == 'h':
        extension = 'cpp'
    with open(path, 'r') as f:
        content = f.read()
    firstLine = content[:content.find('\n') + 1]
    needspace = 0
    if re.fullmatch(' *(?:#|(?://)) ?[1-9][0-9]*\\n', firstLine):
        content = content[len(firstLine):]
        needspace = int(firstLine.strip()[2:].strip())
    for i in range(len(sections)):
        needspace += needspaceForDepth(depth - i)
    print('\\needspace{' + str(needspace) + '\\baselineskip}')
    for i in range(len(sections)):
        printSectionType(sections[i], depth -
                         len(sections) + i + 1, i == len(sections) - 1)
    content = '\\begin{minted}{' + extension + '}\n' + content
    needspaces = set(re.findall(' *(?:#|(?://)) ?[1-9][0-9]*\\n', content))
    for needspace in needspaces:
        news = ''\
            '\\end{minted}\n'\
            '\\vspace{-12pt}\n'\
            '\\needspace{' + needspace.strip()[2:].strip() + '\\baselineskip}\n'\
            '\\begin{minted}{' + extension + '}\n'
        content = content.replace(needspace, news)
    content += '\n\\end{minted}\n'
    print(content)

def main(currPath, depth, sections):
    if len(sections) and sections[-1] in excluded:
        return
    sortedDirs = sorted(
        listdir(currPath),
        key=lambda x: (
            x == 'Extras',
            x == 'Problems Solved',
            x != 'Coding Resources',
            x != 'Data Structures',
            isdir(join(currPath, x)),
            x.split('.')[0].lower()
        )
    )
    isFirst = True
    for dirOrFile in sortedDirs:
        f = join(currPath, dirOrFile)
        if isdir(f):
            if isFirst:
                isFirst = False
                sections.append(dirOrFile)
                main(f, depth + 1, sections)
            else:
                main(f, depth + 1, [dirOrFile])
        elif isfile(f) and re.fullmatch('.+\\.(cpp|c|py|java|tex)', dirOrFile):
            if isFirst:
                isFirst = False
                sections.append(dirOrFile)
                printFile(f, depth + 1, sections)
            else:
                printFile(f, depth + 1, [dirOrFile])


sections = []
# PATH += '/Extras'
main(PATH, 0, sections)
