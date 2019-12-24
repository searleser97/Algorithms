while True:
	n = list(raw_input())
	if n[0] == 'E':
		break
	for i in range(len(n) - 1, -1, -1):
		if n[i] != '0':
			n[i] = chr(ord(n[i]) - 1)
			if n[0] == '0':
				print 0
			else:
				print "".join(n) 
			break