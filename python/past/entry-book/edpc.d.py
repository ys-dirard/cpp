# PythonだとTLE, PypyだとOK

N, W = map(int, input().split())
w = [0]*(N+1)
v = [0]*(N+1)
for i in range(1, N+1):
    ww, vv = map(int, input().split())
    w[i] = ww
    v[i] = vv
    
dp = [[-1e9]*(W+1) for _ in range(N+1)]

dp[0][0] = 0

for i in range(1, N+1):
    for j in range(W+1):
        dp[i][j] = max(dp[i][j], dp[i-1][j])
        if j-w[i]>=0:
            dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i])
            
ans = 0
for j in range(W+1):
    ans = max(ans, dp[N][j])
    
print(ans)
