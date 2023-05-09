N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]

dp = [[1e18]*N for _ in range(1<<N)]

dp[0][0] = 0
# print(dp)

for b in range(1<<N):
    for s in range(N):
        for t in range(N):
            # if b&(1<<s) == 0:
            #     continue
            if b&(1<<t)>0 or s==t:
                continue
            nb = b | (1<<t)
            dp[nb][t] = min(dp[nb][t], dp[b][s]+A[s][t])
            
# print(dp)
print(dp[(1<<N)-1][0])
