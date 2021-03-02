n = int(input())
li = []
li = map(int, input().split())
cnt = [0,0,0,0,0]
for i in li:
    cnt[i] += 1
ans = cnt[4]
cnt[1] -= min(cnt[3], cnt[1])
ans += cnt[3]
ans += cnt[2]//2
if cnt[2]%2:
    cnt[1] -= min(2, cnt[1])
    ans += 1
ans += cnt[1]//4
if cnt[1]%4:
    ans += 1
print(ans)
