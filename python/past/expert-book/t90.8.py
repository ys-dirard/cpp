MOD = 10**9 + 7

N = int(input())
S = input()
s = "atcoder"

# dp[i][j]: Sのi文字目まででatcoderのj文字目までが完成する総数
dp = [[0]*(len(s)+1) for _ in range(N+1)]

dp[0][0] = 1

for i in range(N):
    for j in range(len(s)+1):
        dp[i+1][j] += dp[i][j]
        dp[i+1][j] %= MOD
        if j<len(s) and S[i]==s[j]:
            dp[i+1][j+1] += dp[i][j]
            dp[i+1][j+1] %= MOD
            
print(dp[N][len(s)])
# print(dp)
