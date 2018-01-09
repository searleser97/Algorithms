from os import listdir
from os.path import isfile, join
import os
directories = [name for name in os.listdir(".") if os.path.isdir(name)]
limit = len(directories)
for i in range(limit):
    if directories[i] == '.cache' or directories[i] == '_minted-main' or directories[i] == '_minted-output':
        continue
    print('\\section{' + directories[i] + '}')
    if directories[i] == 'Graphs':
        print('\\subsection{GraphAPI}')
        print('\\inputminted[breaklines]{cpp}{Graphs/graphAPI.h}')
    onlyfiles = [f for f in listdir(directories[i] + '/') if isfile(join(directories[i] + '/', f))]
    for file in onlyfiles:
        aux = file.split('.')
        if len(aux) == 1:
            continue
        name, extension = aux
        if extension == 'txt' or name == 'graphAPI':
            continue
        if extension == 'h':
            extension = 'cpp';
        print('\\subsection{' + str(name) + '}')
        print('\\inputminted[breaklines]{' + extension + '}{' + directories[i] + '/' + file + '}')