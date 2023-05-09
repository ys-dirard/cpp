from collections import deque

R, C = map(int, input().split())
sy, sx = map(int, input().split())
gy, gx = map(int, input().split())
sy -= 1; sx -= 1; gy -=1; gx -= 1
c = [input() for _ in range(R)]

dxy = [[1, 0], [0, 1], [-1, 0], [0, -1]]

dist = [[-1] * C for _ in range(R)]

q = deque()
dist[sy][sx] = 0
q.append([sy, sx, 0]) # (i, j, d)

while len(q) > 0:
    y, x, d = q.popleft()
    for dx, dy in dxy:
        ny = y + dy
        nx = x + dx
        
        if 0<=ny<R and 0<=nx<C and c[ny][nx]=='.' and dist[ny][nx]==-1:
            dist[ny][nx] = d+1
            q.append([ny, nx, d+1])
            
print(dist[gy][gx])

# for i in range(R):
#     print(dist[i])
