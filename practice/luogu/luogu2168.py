from heapq import heappush, heappop, heapify

class Node:
	val = 0
	dep = 0 
	def __init__(self, v, d):
		self.val = v
		self.dep = d
	def __lt__(self, obj):
		if self.val != obj.val:
			return self.val < obj.val
		else:
			return self.dep < obj.dep

li = []

if __name__ == "__main__":
	n,k = map(int, input().strip().split())
	for i in range(n):
		heappush(li, Node(int(input().strip()), 0))
	while ((len(li)-1) % (k-1)) != 0 :
		heappush(li, Node(0,0))
	ans = 0
	while(len(li)>1):
		newval = 0
		newdep = 0
		for i in range(k):
			
			#print(len(li))

			newval += li[0].val
			newdep = max(newdep, li[0].dep)

			#print(li[0].val, li[0].dep)

			heappop(li)
		ans += newval
		heappush(li, Node(newval, newdep+1))
	print(ans, li[0].dep, sep='\n')
