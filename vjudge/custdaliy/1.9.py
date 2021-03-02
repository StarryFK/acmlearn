MOD = int(1e9+7)
def f(n):
    global MOD
    li = [1,2,0]
    for i in range(2,n):
        li[i%3] = li[(i-1)%3] + li[(i-2)%3] % MOD
    return li[(n-1)%3]


n,m = map(int, input().split())
print(2*(f(n)+f(m)-1) % MOD)
