N, L = map(int, input().split())
x = list(map(int, input().split()))
T1, T2, T3 = map(int, input().split())

hurdle = [False]*(L+1)
for xx in x:
    hurdle[xx] = True

dp = [1e9] * (L+1)
dp[0] = 0

for i in range(0, L+1):
    
    dp[i] = min(dp[i], dp[i-1]+T1)
    if i-4>=0:
        dp[i] = min(dp[i], dp[i-2]+T1+T2, dp[i-4]+T1+3*T2)
    elif i-2>=0:
        dp[i] = min(dp[i], dp[i-2]+T1+T2)
        
    if hurdle[i]:
        dp[i] += T3
        
ans = dp[L]
for d in range(1, 4):
    if L-d>=0:
        ans = min(ans, dp[L-d]+T1//2+T2//2+T2*(d-1))
print(ans)
# print(dp[L])
# print(dp)
# print(x)