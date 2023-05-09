M, N = map(int, input().split())
S = input()
T = input()

dp = [[10**9]*(len(S)+1) for _ in range(len(T)+1)]

dp[0][0] = 0
for i in range(1, len(S)+1):
    dp[0][i] = dp[0][i-1]+1
    
for i in range(1, len(T)+1):
    dp[i][0] = dp[i-1][0]+1
    
# main
for i in range(1, len(T)+1):
    for j in range(1, len(S)+1):
        dp[i][j] = min(dp[i][j], dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1)
        if T[i-1]==S[j-1]:
            dp[i][j] = min(dp[i][j], dp[i-1][j-1])
    
print(dp[len(T)][len(S)])
# print(dp)
