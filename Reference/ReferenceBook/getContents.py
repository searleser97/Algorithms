from os import listdir
from os.path import isfile, isdir, join
import re

PATH = '/home/san/Algorithms/Reference'
excluded = set(['ReferenceBook', '.vscode'])


def printSectionType(sectionName, depth, isFile):
    vspace = 0
    style = '\\bfseries\\sffamily'
    if depth == 1:
        sectionType = 'section'
        style += '\\Huge'
        vspace = 2
    elif depth == 2:
        sectionType = 'subsection'
        style += '\\LARGE\\bfseries\\sffamily'
    elif depth == 3:
        sectionType = 'subsubsection'
        style += '\\Large\\bfseries\\sffamily'
    elif depth == 4:
        sectionType = 'paragraph'
        style = '\\large\\bfseries\\sffamily'
    elif depth == 5:
        sectionType = 'subparagraph'
        style = '\\large\\bfseries\\sffamily'
    if isFile:
        style += '\\underline\\normalsize'
    else:
        style += '\\centering'
    print('\\' + sectionType + 'font{' + style + '}')
    if vspace:
        print('\\vspace{' + str(vspace - 1) + 'em}')
    print('\\' + sectionType + '*{' + sectionName + '}')
    print('\\addcontentsline{toc}{' + sectionType + '}{' + sectionName + '}')
    if vspace:
        print('\\vspace{' + str(vspace) + 'em}')


def printFile(path, extension):
    if extension == 'tex':
        print('\\cfinput{' + path + '}')
    elif extension == 'h':
        extension = 'cpp'
    with open(path, 'r') as f:
        content = str('\\begin{minted}{' + extension + '}\n' + f.read())
    needspaces = re.findall('(?:#|(?://)) ?[1-9][0-9]*', content)
    for needspace in needspaces:
        news = ''\
            '\\end{minted}\n'\
            '\\vspace{-1em}\n'\
            '\\needspace{' + needspace[2:].strip() + '\\baselineskip}\n'\
            '\\begin{minted}{' + extension + '}'
        content = content.replace(needspace, news)
    content += '\n\\end{minted}\n'
    print(content)


def main(currPath, currDir, depth):
    if currDir in excluded:
        return
    printSectionType(currDir, depth, 0)
    i = 1
    for dirOrFile in sorted(listdir(currPath), key=lambda x: x.split('.')[0].lower()):
        f = join(currPath, dirOrFile)
        if isdir(f):
            main(f, dirOrFile, depth + 1)
        elif isfile(f):
            fileName = dirOrFile
            if re.fullmatch('.+\\.(cpp|c|py|java|tex)', fileName):
                name, extension = fileName.split('.')
                printSectionType(str(name), depth + 1, i)
                printFile(str(f), extension)
        i += 1


for directory in sorted(listdir(PATH), key=lambda x: x.split('.')[0].lower()):
    f = join(PATH, directory)
    if isdir(f):
        main(f, directory, 1)
