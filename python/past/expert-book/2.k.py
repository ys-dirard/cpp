N = int(input())
S = input()
C = list(map(int, input().split()))
D = list(map(int, input().split()))

# dp[i][j]: Sのi文字目までのjにするための最小コスト
# ※j: (->+1, )->-1
dp = [[10**18]*(N+1) for _ in range(N+1)]
dp[0][0] = 0

for i in range(N):
    for j in range(N):
        if S[i]=='(':
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j])
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+D[i])
            if j>0: dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j]+C[i])
        else:
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+C[i])
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+D[i])
            if j>0: dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j])
            
print(dp[N][0])
