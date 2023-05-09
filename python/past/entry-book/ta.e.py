N, M = map(int, input().split())
u, v, c = [], [], []
dist = [[10**18]*N for _ in range(N)]

for i in range(M):
    uu, vv, cc = map(int, input().split())
    u.append(uu); v.append(vv); c.append(cc)
    dist[uu][vv] = cc
    
for i in range(N):
    dist[i][i] = 0    

for k in range(N):
    for i in range(N):
        for j in range(N):
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])
            
ans = 0
for i in range(N):
    for j in range(N):
        ans += dist[i][j]
        
print(ans)
