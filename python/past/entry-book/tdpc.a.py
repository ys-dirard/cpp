N = int(input())
p = list(map(int, input().split()))

pM = 10000

dp = [[0] * (pM+1) for _ in range(N+1)]

dp[0][0] = 1
for i in range(1, N+1):
    for j in range(pM+1):
        dp[i][j] += dp[i-1][j]
        if j-p[i-1]>=0:
            dp[i][j] += dp[i-1][j-p[i-1]]

ans = 0
for j in range(0, pM+1):
    if dp[N][j]>0:
        ans += 1

print(ans)
