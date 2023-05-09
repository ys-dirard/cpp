from collections import deque
import heapq

H, W = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]

def dijkstra(si, sj):
    dist = [[10**18]*W for _ in range(H)]
    visited = [[False]*W for _ in range(H)]
    
    pq = [] # (dist, pos)
    heapq.heappush(pq, (0, (si, sj)))
    while len(pq)>0:
        d, (i, j) = heapq.heappop(pq)
        if visited[i][j] or dist[i][j] < d:
            continue
        visited[i][j] = True
        dist[i][j] = d
        
        for ni, nj in [[i+1, j], [i, j+1], [i-1, j], [i, j-1]]:
            if not (0<=ni<=H-1 and 0<=nj<=W-1):
                continue
            if visited[ni][nj]:
                continue
            if dist[ni][nj] > d+A[ni][nj]:
                heapq.heappush(pq, (d+A[ni][nj], (ni, nj)))
    return dist

# dist = dijkstra(2,4)
# for d in dist:
#     print(d)

dist1 = dijkstra(0, W-1)
dist2 = dijkstra(H-1, 0)
dist3 = dijkstra(H-1, W-1)

ans = 10**18
for si in range(H):
    for sj in range(W):
        # dist = dijkstra(si, sj)
        ans = min(ans, dist1[si][sj]+dist2[si][sj]+dist3[si][sj] - 2*A[si][sj])
print(ans)
