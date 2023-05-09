import heapq

N, M = map(int, input().split())
g = [[] for _ in range(N)]
for _ in range(M):
    u, v, c = map(int, input().split())
    g[u].append((v, c))
    g[v].append((u, c))
    
marked = [False]*N
marked_count = 0
ans = 0

pq = []
heapq.heappush(pq, (0, 0))
while marked_count<N:
    cost, pos = heapq.heappop(pq)
    if marked[pos]:
        continue
    marked[pos] = True
    marked_count += 1
    ans += cost
    
    for npos, ncost in g[pos]:
        if marked[npos]:
            continue
        heapq.heappush(pq, (ncost, npos))
        
print(ans)
