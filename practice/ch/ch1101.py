stack = []
out = []
n = 0
cnt = 0
def dfs(cur):
	global n
	global stack
	global out
	global cnt
	if cnt >= 20:
		return
	if len(out)==n:
		#print(cnt, end=' ')
		for i in out:
			print(i,end='')
		print('')
		cnt += 1
		return

	if len(stack):
		out.append(stack.pop())
		dfs(cur)
		stack.append(out.pop())

	if cur<=n:
		stack.append(cur)
		dfs(cur+1)
		stack.pop()
	

n = int(input())
dfs(1)
