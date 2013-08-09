import math

def factorial(number):
	counter = 0
	total = 1
	while counter < number:
		total = total * (counter+1)
		counter += 1
	return total
def pb(alpha, m):
	fact = factorial(m)
	e = math.exp(-1 * alpha)
	count = 0
	power = alpha
	while count < m:
		power = power * alpha
		count += 1
	return (e * power) / fact

def pc(m):
	p_c = 2 / (500 * (1 + m))
	return p_c


def pd(m):
	fact = factorial(m)
	return (1 / (math.exp(1) * fact))

m = 1
n = 120
alpha = 3.57
value = 0
while m < n:
	p_b = pb(alpha, m+1)
	p_c = pc(m+1)
	p_d = pd(m+1)
	print(p_b)
	print(p_c)
	print(p_d)
	value += ( (1- p_b) * (1 - p_c) * (1 - p_d) )
	value += ( p_b * p_c)
	value += ( p_b * p_d)
	value -= p_b
	value -= p_d
	value -= p_c
	value -= (p_b * p_c * p_d)
	m += 1
print(value)