N, M = map(int, input().split())
sc = [input().split() for _ in range(M)]
S = [sc[i][0] for i in range(M)]
C = [int(sc[i][1]) for i in range(M)]
# print(S)
# print(C)

def str2bit(s):
    # print(s)
    res = 0
    e = 0
    for ss in s:
        # print(ss)
        if ss=='Y':
            # print("TTT", 1<<e, e)
            res += (1<<e)
        # print(res)
        e += 1
    return res

# dp[i][j]: i番目のセットまででできるjの最小値
dp = [[1e18]*(1<<N) for _ in range(M+1)]

dp[0][0] = 0
for i in range(1, M+1):
    dp[i] = dp[i-1]
    for j in range(1<<N):
        b = str2bit(S[i-1])
        # print(b, j|b)
        dp[i][j|b] = min(dp[i][j|b], dp[i-1][j]+C[i-1])
        # print(dp[i][j|b])
if dp[M][(1<<N)-1] == 1e18: print(-1)
else: print(dp[M][(1<<N)-1])
# print(dp)
