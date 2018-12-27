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


def main(currPath, currDir, depth):
    if currDir in excluded:
        return
    printSectionType(currDir, depth, False)
    for dirOrFile in sorted(listdir(currPath), key=lambda x: x.split('.')[0]):
        f = join(currPath, dirOrFile)
        if isdir(f):
            main(f, dirOrFile, depth + 1)
        elif isfile(f):
            fileName = dirOrFile
            if re.fullmatch('.+\\.(cpp|c|py|java|tex)', fileName):
                name, extension = fileName.split('.')
                printSectionType(str(name), depth + 1, True)
                if extension == 'tex':
                    print('\\cfinput{' + str(f) + '}')
                else:
                    if extension == 'h':
                        extension = 'cpp'
                    print('\\inputminted{' + extension + '}{"' + str(f) + '"}')


for directory in sorted(listdir(PATH), key=lambda x: x.split('.')[0]):
    f = join(PATH, directory)
    if isdir(f):
        main(f, directory, 1)
