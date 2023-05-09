from collections import deque

N, M = map(int, input().split())
g = [[] for _ in range(N)]
for _ in range(M):
    u, v = map(int, input().split())
    u -= 1; v -= 1
    g[u].append(v)
    g[v].append(u)
s = int(input())
s -= 1
K = int(input())
t = list(map(int, input().split()))
t = [e-1 for e in t]
t = t + [s]
# dist = [[] for _ in range(K+1)]
dist = []

# BFSがバグってる
# print(dist)
for i in t:
    q = deque()
    d = [-1]*N
    d[i] = 0
    q.append((i, 0))
    
    while len(q)>0:
        pos, cost = q.popleft()
        for nex in g[pos]:
            if d[nex] == -1:
                d[nex] = cost + 1
                q.append((nex, cost + 1))
    # print(i, d)
    res = []
    for i in t:
        res.append(d[i])
    dist.append(res)
    
# print(t)
# print(dist)

dp = [[10**18]*K for _ in range(1<<(K))]
for i in range(K):
    dp[1<<i][i] = dist[K][i]
# dp[1<<s][s] = 1
# print(dp)
for i in range(1<<(K)):
    for j in range(K):
        for k in range(K):
            if (i & (1<<k) > 0) or j==k:
                continue
            dp[i|(1<<k)][k] = min(dp[i|(1<<k)][k], dp[i][j]+dist[j][k])
     

print(min(dp[(1<<K)-1]))
