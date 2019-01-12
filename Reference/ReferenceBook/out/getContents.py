from os import listdir
from os.path import isfile, isdir, join
import re

PATH = '/home/san/Algorithms/Reference'
excluded = set(['ReferenceBook', '.vscode'])


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
    elif depth == 3:
        sectionType = 'subsubsection'
        style += '\\Large'
    if isFile:
        style = '\\large\\bfseries\\sffamily\\underline'
    print('\\' + sectionType + 'font{' + style + '}')
    if vspace:
        print('\\vspace{' + str(vspace - 1) + 'em}')
    print('\\' + sectionType + '*{' + sectionName + '}')
    if depth == 1:
        print('\\markboth{' + sectionName.upper() + '}{}')
    print('\\addcontentsline{toc}{' + sectionType + '}{' + sectionName + '}')
    if vspace:
        print('\\vspace{' + str(vspace) + 'em}')


def printFile(path, extension, name, depth):
    if extension == 'tex':
        print('\\cfinput{' + path + '}')
    elif extension == 'h':
        extension = 'cpp'
    with open(path, 'r') as f:
        content = f.read()
    firstLine = content[:content.find('\n') + 1]
    print('% ------------------------------------------------------' + firstLine)
    if re.fullmatch('(?:#|(?://)) ?[1-9][0-9]*\\n', firstLine):
        content = content.replace(firstLine, '')
        print(
            '\\needspace{' + str(int(firstLine[2:].strip()) + 1) + '\\baselineskip}')
    printSectionType(name, depth, True)
    content = '\\begin{minted}{' + extension + '}\n' + content
    needspaces = re.findall('(?:#|(?://)) ?[1-9][0-9]*\\n', content)
    for needspace in needspaces:
        news = '\n'\
            '\\end{minted}\n'\
            '\\vspace{-1em}\n'\
            '\\needspace{' + needspace[2:].strip() + '\\baselineskip}\n'\
            '\\begin{minted}{' + extension + '}\n'
        content = content.replace(needspace, news)
    content += '\n\\end{minted}\n'
    print(content)


def main(currPath, currDir, depth):
    if currDir in excluded:
        return
    printSectionType(currDir, depth, False)
    for dirOrFile in sorted(listdir(currPath), key=lambda x: x.split('.')[0].lower()):
        f = join(currPath, dirOrFile)
        if isdir(f):
            main(f, dirOrFile, depth + 1)
        elif isfile(f):
            fileName = dirOrFile
            if re.fullmatch('.+\\.(cpp|c|py|java|tex)', fileName):
                name, extension = fileName.split('.')
                printFile(f, extension, name, depth + 1)


for directory in sorted(listdir(PATH), key=lambda x: x.split('.')[0].lower()):
    f = join(PATH, directory)
    if isdir(f):
        main(f, directory, 1)
