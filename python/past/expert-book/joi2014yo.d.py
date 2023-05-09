MOD = 10007

N = int(input())
S = input()
d = {'J': 0, 'O': 1, 'I': 2}
S = [d[s] for s in S]
# print(S)

# dp[i][j]: i日目の終わりにjが鍵を持っている総数
dp = [[0]*(1<<3) for _ in range(N+1)]

dp[0][(1<<0)] = 1

for i in range(N):
    for j in range(0, 1<<3):
        for k in range(0, 1<<3):
            if j & k != 0 and (j & (1<<S[i])) > 0:
                dp[i+1][j] += dp[i][k]
                dp[i+1][j] %= MOD
ans = sum(dp[N])%MOD
print(ans)

# 連続で出席する必要がある
# -> 出席をタイルを黒く塗るに言い換えると
#    どこかで黒が隣接(j&k>0)すれば連日参加する人が存在することになる！