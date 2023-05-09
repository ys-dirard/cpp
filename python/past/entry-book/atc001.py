import sys
sys.setrecursionlimit(1000000)

H, W = list(map(int, input().split()))
# c = [input() for _ in range(H)]
c = []
for i in range(H):
    s = input()
    c.append(s)

for i in range(H):
    for j in range(W):
        if c[i][j]=='s':
            si, sj = i, j
        if c[i][j]=='g':
            gi, gj = i, j

# visited = [[False] * W for _ in range(H)]
visited = []
for i in range(H):
    visited.append([False] * W)

def dfs(i, j):
    visited[i][j] = True
    
    for ni, nj in [[i+1, j], [i-1, j], [i, j+1], [i, j-1]]:
        if not(0<=ni<H and 0<=nj<W):
            continue
        if c[i][j]=='#':
            continue
        if not visited[ni][nj]:
            dfs(ni, nj)

dfs(si, sj)

if visited[gi][gj]:
    print("Yes")
else:
    print("No")
