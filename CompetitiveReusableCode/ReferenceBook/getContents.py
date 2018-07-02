from os import listdir
from os.path import isfile, isdir, join

PATH = '/home/san/CODE/Algorithms/CompetitiveReusableCode/'
excluded = ['ReferenceBook', '.vscode']

def printSectionType(sectionName, depth):
    if depth == 4:
        print('\\paragraph{' + sectionName + '}')
    if depth == 5:
        print('\\subparagraph{' + sectionName + '}')
    else:
        subs = ''
        for i in range(depth - 1):
            subs += 'sub'
        print('\\' + subs + 'section{' + sectionName + '}')


def main(currPath, currDir, depth):

    if currDir in excluded :
        return

    printSectionType(currDir, depth)

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
            printSectionType(str(name), depth + 1)
            if extension == 'tex':
                print('\\cfinput{' + str(f) + '}')
            else:
                if extension == 'h':
                    extension = 'cpp'
                print('\\inputminted[breaklines]{' + extension + '}{"' + str(f) + '"}')


for directory in listdir(PATH):
    if isdir(join(PATH, directory)):
        main(join(PATH, directory), directory, 1)
