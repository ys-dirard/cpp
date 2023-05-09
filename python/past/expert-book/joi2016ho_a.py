N, M, K = map(int, input().split())
A = [int(input()) for _ in range(N)]

# dp[i]: i個目までを分けた時のコストの最小値
dp = [10**18]*(N+1)
cost = [[0]*(M+1) for _ in range(N+1)]
for i in range(N):
    min_val, max_val = 10**18, 0
    for j in range(i, min(N, M+i)):
        min_val = min(min_val, A[j])
        max_val = max(max_val, A[j])
        cost[i][j-i+1] = K + (max_val - min_val)*(j-i+1)
        
dp[0] = 0
for i in range(1, N+1):
    for j in range(max(i-M, 0), i):
        dp[i] = min(dp[i], dp[j]+cost[j][i-j])
        
print(dp[N])
