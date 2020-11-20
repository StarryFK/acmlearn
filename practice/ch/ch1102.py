import math
def fac(cnt, num):
	for i in range(2, math.ceil(math.sqrt(num))+1):
		while num%i==0:
			cnt[i] += 1
			num //= i
	if num:
		cnt[num] += 1


n = int(input())
cnt1 = [0 for i in range(2*n+5)]
cnt2 = [0 for i in range(2*n+5)]


'''
fac(cnt1, 2)
for i in range(2,120005):
	if cnt1[i]!=0:
		print(i, cnt1[i])
'''


for i in range(n+2, 2*n+1):
	fac(cnt1, i)
for i in range(2, n+1):
	fac(cnt2, i)

for i in range(2, 2*n+5):
	cnt1[i] -= cnt2[i]

ans = 1
for i in range(2, 2*n+5):
	if cnt1[i]!=0:
		ans *= i**cnt1[i]
print(ans)
