from os import listdir
from os.path import isfile, isdir, join
import re

PATH = '/home/san/Algorithms/Reference'
excluded = set(['ReferenceBook', '.vscode'])


def printSectionType(sectionName, depth, isFile):
    sectionType = ''
    if depth == 4:
        sectionType = 'paragraph'
    if depth == 5:
        sectionType = 'subparagraph'
    else:
        for _ in range(depth - 1):
            sectionType += 'sub'
        sectionType += 'section'

    if (isFile):
        print('\\' + sectionType + 'font{\\sffamily\\underline}')
    print('\\' + sectionType + '{' + sectionName + '}')
    if (isFile):
        print('\\' + sectionType + 'font{\\sffamily}')


def printFile(path, extension):
    if extension == 'tex':
        print('\\cfinput{' + path + '}')
    elif extension == 'h':
        extension = 'cpp'
    # print('\\inputminted{' + extension + '}{"' + path + '"}')
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
    printSectionType(currDir, depth, False)
    for dirOrFile in sorted(listdir(currPath), key=lambda x: x.split('.')[0].lower()):
        f = join(currPath, dirOrFile)
        if isdir(f):
            main(f, dirOrFile, depth + 1)
        elif isfile(f):
            fileName = dirOrFile
            if re.fullmatch('.+\\.(cpp|c|py|java|tex)', fileName):
                name, extension = fileName.split('.')
                printSectionType(str(name), depth + 1, True)
                printFile(str(f), extension)


for directory in sorted(listdir(PATH), key=lambda x: x.split('.')[0].lower()):
    f = join(PATH, directory)
    if isdir(f):
        main(f, directory, 1)
