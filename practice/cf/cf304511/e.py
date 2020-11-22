arr = [0,62]
for i in range(2, 100):
	arr.append(arr[i-1]*62%998244353)	
for i in arr:
	print(i)
