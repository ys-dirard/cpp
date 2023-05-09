import sys
sys.setrecursionlimit(1000000)

N = int(input())
B = [int(input())-1 for _ in range(N-1)]

g = [[] for _ in range(N)]
for i in range(1, N):
    g[B[i-1]].append(i)
# print(g)

dp = [0]*N

def dfs(pos):
    if len(g[pos])==0:
        dp[pos] = 1
        return 1
    m = 1e9
    M = 0
    
    salary = 1
    for sub in g[pos]:
        m = min(m, dfs(sub))
        M = max(M, dfs(sub))
    dp[pos] = M + m + 1
    return dp[pos]

dfs(0)

print(dp[0])
