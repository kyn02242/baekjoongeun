import math
n1, n2 = map(int, input().split())

a = math.factorial(n1)
b = (math.factorial(n1-n2)) * (math.factorial(n2))

print(a//b)