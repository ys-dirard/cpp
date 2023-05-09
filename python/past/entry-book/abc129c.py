MOD = 10**9+7

N, M = map(int, input().split())
broken = [False] * (N+1)
a = list(int(input()) for _ in range(M))
for i in a:
    broken[i] = True

dp = [0]*(N+1)
dp[0] = 1

for i in range(N):
    if broken[i]:
        continue
    dp[i+1] += dp[i]
    dp[i+1] %= MOD
    
    if i+2<=N:
        dp[i+2] += dp[i]
        dp[i+2] %= MOD
        
print(dp[N])
