from collections import deque

N, M = map(int, input().split())
A = [list(input()) for _ in range(N)]

for i in range(N):
    for j in range(M):
        if A[i][j]=='S':
            si = i
            sj = j
        if A[i][j]=='G':
            gi = i
            gj = j
            
for i in range(N):
    for j in range(M):
        if A[i][j] in ['S', 'G']:
            A[i][j] = -1
        else:
            A[i][j] = int(A[i][j])
            
dp = [[[1e9]*10 for _ in range(M)] for _ in range(N)]

q = deque()

q.append((si, sj))
dp[si][sj][0] = 0

while len(q)>0:
    ti, tj = q.popleft()
    for ni, nj in [[ti-1, tj], [ti, tj-1], [ti+1, tj], [ti, tj+1]]:
        update = False
        if not (0<=ni<N and 0<=nj<M):
            continue
        for i in range(10):
            if dp[ni][nj][i] > dp[ti][tj][i]+1:
                dp[ni][nj][i] = min(dp[ni][nj][i], dp[ti][tj][i]+1)
                update = True
            if A[ni][nj]==i and dp[ni][nj][i] > dp[ti][tj][i-1]+1:
                dp[ni][nj][i] = min(dp[ni][nj][i], dp[ti][tj][i-1]+1)
                update = True
        if update: q.append((ni, nj))
        
if dp[gi][gj][9]==1e9: print(-1)
else: print(dp[gi][gj][9])
