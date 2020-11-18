class Man:
	def __init__(self, a, b):
		self.a = a
		self.b = b
	def __lt__(self, other):
		return self.a*self.b < other.a*other.b

n = int(input())
arr = []
ka, kb = map(int, input().strip().split())
for i in range(n):
	a,b = map(int, input().strip().split())
	arr.append(Man(a,b))
arr.sort()
pd = ka
ans = 0
for i in arr:
	ans = max(ans, pd//i.b)
	#print(i.a, i.b, pd, pd//i.b)
	pd *= i.a
print(ans)

