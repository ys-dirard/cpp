import sys
sys.setrecursionlimit(1000000)

N, M = map(int, input().split())
x, y = [], []
g = [[] for _ in range(N)]
for i in range(M):
    xx, yy = map(int, input().split())
    xx -= 1
    yy -= 1
    x.append(xx)
    y.append(yy)
    g[xx].append(yy)
    
dp = [-1] * N

def dfs(pos):
    if dp[pos]>=0:
        return dp[pos]
    elif len(g[pos])==0:
        dp[pos] = 0
        return 0
    
    d = 0
    for nex in g[pos]:
        d = max(d, dfs(nex))
        
    dp[pos] = d + 1
    return d + 1

for i in range(N):
    dfs(i)
    
ans = 0
for i in range(N):
    ans = max(ans, dp[i])
    
print(ans)
# print(g)
# print(dp)