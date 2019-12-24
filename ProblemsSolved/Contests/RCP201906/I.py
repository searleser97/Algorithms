from sys import stdin, stdout

def divisorCriteria(n, lim):
	results = []
	tenElevated = 1
	for i in range(lim):
		remainder = tenElevated % n
		negremainder = remainder - n
		if (remainder <= abs(negremainder)):
			results.append(remainder)
		else:
			results.append(negremainder)
		tenElevated *= 10
	return results

def testDivisibility(dividend, divisor, divisor_criteria):
	dividend = str(dividend)
	addition = 0
	dividendSize = len(dividend)
	i = dividendSize - 1
	j = 0
	while j < dividendSize:
		addition += int(dividend[i]) * divisor_criteria[j]
		i -= 1
		j += 1
	return addition % divisor == 0

if __name__ == '__main__':
	
	lines = stdin.readlines()
	for divisor in lines:
		divisor = int(divisor)
		divisor_criteria = divisorCriteria(divisor, 510)
		dividend = '1' * len(str(divisor))
		while True:
			try:
				if testDivisibility(dividend, divisor, divisor_criteria) == True:
					print(len(dividend))
					break
				dividend += '1'
			except:
				print(-1)
				break