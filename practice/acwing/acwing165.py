def dfs(cur):
    global cat,cab,ans,n,w
    if(len(cab) >= ans):
        return
    if(cur==n):
        ans = min(ans, len(cab))
        return
    for i in range(len(cab)):
        if cab[i]+cat[cur]<=w:
            cab[i] += cat[cur]
            dfs(cur+1)
            cab[i] -= cat[cur]
    cab.append(cat[cur])
    dfs(cur+1)
    cab.pop()


n,w = map(int, input().
        strip().
        split())
cat = []
for i in range(n):
    cat.append(int(input()))
cat.sort(reverse=True)
ans=int(1e10)
cab=[]
dfs(0)
print(ans)
