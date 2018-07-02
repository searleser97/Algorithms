from os import listdir
from os.path import isfile, isdir, join

PATH = '/home/san/CODE/Algorithms/CompetitiveReusableCode/'
excluded = ['ReferenceBook', '.vscode']

def printSectionType(sectionName, depth, isFile):
    sectionType = ''
    if depth == 4:
        sectionType = 'paragraph'
    if depth == 5:
        sectionType = 'subparagraph'
    else:
        for i in range(depth - 1):
            sectionType += 'sub'
        sectionType += 'section'

    if (isFile):
        print('\\' + sectionType + 'font{\\sffamily\\underline}')
    print('\\' + sectionType + '{' + sectionName + '}')
    if (isFile):
        print('\\' + sectionType + 'font{\\sffamily}')


def main(currPath, currDir, depth):

    if currDir in excluded :
        return

    printSectionType(currDir, depth, False)

    for dirOrFile in listdir(currPath):
        f = join(currPath, dirOrFile)
        if isdir(f):
            main(f, dirOrFile, depth + 1)
        if isfile(f):
            file = dirOrFile
            aux = file.split('.')
            if len(aux) == 1:
                continue
            name, extension = aux
            printSectionType(str(name), depth + 1, True)
            if extension == 'tex':
                print('\\cfinput{' + str(f) + '}')
            else:
                if extension == 'h':
                    extension = 'cpp'
                print('\\inputminted{' + extension + '}{"' + str(f) + '"}')


for directory in listdir(PATH):
    if isdir(join(PATH, directory)):
        main(join(PATH, directory), directory, 1)
