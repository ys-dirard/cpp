N = int(input())
c = list(list(map(int, input().split())) for _ in range(N+1))

dp = [10**18]*(N+1)
dp[0] = 0
    
for i in range(1, N+1):
    for j in range(i):
        dp[i] = min(dp[i], dp[j]+c[j][i])
        
print(dp[N])
