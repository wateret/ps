n = int(raw_input())

a = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
b = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
c = ["", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

if n < 10:
	print a[n]
elif n < 20:
	print b[n-10]
else:
	if n%10 == 0:
		print '%s' % c[n//10]
	else:
		print '%s-%s' % (c[n//10], a[n%10])
