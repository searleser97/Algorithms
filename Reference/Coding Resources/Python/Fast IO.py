from sys import stdin, stdout

N = 10
#Reads N chars from stdin(it counts '\n' as char)
stdin.read(N)
#Reads until '\n' or EOF
line = stdin.readline()
#Reads all lines in stdin until EOF
lines = stdin.readlines()
#Writes a string to stdout, it doesn't add '\n'
stdout.write(line)
#Writes a list of strings to stdout
stdout.writelines(lines)
#Reads numbers separated by space in a line
numbers = list(map(int, stdin.readline().split()))
