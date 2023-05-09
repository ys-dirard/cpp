N, M, Q = map(int, input().split())
g = [[] for _ in range(N)]
for i in range(M):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)
    
c = list(map(int, input().split()))
s = list(input() for _ in range(Q))

for q in s:
    q = list(map(int, q.split()))
    q[1] -= 1
    print(c[q[1]])
    if q[0]==1:
        for p in g[q[1]]:
            c[p] = c[q[1]]
    else:
        c[q[1]] = q[2]
