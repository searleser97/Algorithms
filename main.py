from os import listdir
from os.path import isfile, join
import os
directories = [name for name in os.listdir(".") if os.path.isdir(name)]
print '\n'
limit = len(directories) - 1
for i in range(limit):
    if (directories[i] == '.cache'):
        continue
    print '\section{' + directories[i] + '}'
    onlyfiles = [f for f in listdir(directories[i] + '/') if isfile(join(directories[i] + '/', f))]
    for file in onlyfiles:
        name, extension = file.split('.')
        print '\subsection{' + name + '}'
        print '\inputminted[breaklines]{' + extension + '}{' + directories[i] + '/' + file + '}'

