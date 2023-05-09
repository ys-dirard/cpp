MOD = 10**9+7

H, W = map(int, input().split())
a = list(input() for _ in range(H))

dp = [[0]*W for _ in range(H)]

dp[0][0] = 1
for i in range(H):
    for j in range(W):
        if a[i][j]=="#":
            continue
        if i<H-1:
            dp[i+1][j] += dp[i][j]
            dp[i+1][j] %= MOD
        if j<W-1:
            dp[i][j+1] += dp[i][j]
            dp[i][j+1] %= MOD
            
print(dp[H-1][W-1])
