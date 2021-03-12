from heapq import heappush, heappop, heapify

if __name__ == "__main__":
	n = int(input().strip())
	ha = list(map(int, input().strip().split()))
	heapify(ha)

	#print(ha)

	ans = 0
	while(len(ha)>1):
		a,b = heappop(ha), heappop(ha)
		ans += a+b
		heappush(ha, a+b)
	print(ans)
