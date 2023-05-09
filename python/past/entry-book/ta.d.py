import heapq

N, M = map(int, input().split())
u, v, c = [], [], []
g = [[] for _ in range(N)]
dist = [-1] * N

for i in range(M):
    uu, vv, cc = map(int, input().split())
    u.append(uu)
    v.append(vv)
    c.append(cc)
    g[uu].append([vv, cc])
    
pq = []
heapq.heappush(pq, [0, 0])

while len(pq) > 0:
    tc, tp = heapq.heappop(pq)
    if dist[tp] != -1:
        continue
    dist[tp] = tc
    
    for np, nc in g[tp]:
        if dist[np] == -1 or dist[np] > tc + nc:
            heapq.heappush(pq, [tc+nc, np])

# print(dist)            
print(dist[N-1])
