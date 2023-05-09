N = int(input())
A = list(map(int, input().split()))

# Average:
# (A[1] + ... + A[K])/K >= X
# -> A[1] + ... + A[K] >= KX
# -> A[1]-K + ... + A[K]-K >= 0
# B[i] = A[i] - Kとすると
# B[1] + ... + B[K] >= 0であればよい！
# 
# S[i+1] = Bのi番目までで条件を満たす中でi番目を選んだ場合の合計の最大値
# T[i+1] = Bのi番目までで条件を満たす中でi番目を選ばなかった場合の合計の最大値
# として、max(S[N], T[N]) >= 0だったらOK!!!

def check_average(mid):
    B = [a-mid for a in A]
    
    
    S = [0]*(N+1)
    T = [0]*(N+1)
    for i in range(N):
        S[i+1] = max(S[i], T[i]) + B[i]
        T[i+1] = S[i]
    return max(S[N], T[N]) >= 0


# median:
# 奇数 -> (K+1)/2 番目
# 偶数 -> K/2 番目
# 中央値がX以上であるとき
# 奇数 -> (K+1)/2 個以上がX以上
# 偶数 -> K/2+1個以上がX以上
#
# B[i]: 1(A[i]>=X), -1(A[i]<X)として
# 選んだB[i]の和>=0となる選び方があればよい
# 
# S[i+1] = Bのi番目までで条件を満たす中でi番目を選んだ場合の合計の最大値
# T[i+1] = Bのi番目までで条件を満たす中でi番目を選ばなかった場合の合計の最大値
# として、max(S[N], T[N]) >= 0だったらOK!!!

def check_median(mid):
    B = [int(((a>=mid) - 0.5)*2) for a in A]
    
    S = [0]*(N+1)
    T = [0]*(N+1)
    for i in range(N):
        S[i+1] = max(S[i], T[i]) + B[i]
        T[i+1] = S[i]
    return max(S[N], T[N]) > 0


def bin_search_double(ok, ng, solve):
    while abs(ok - ng) > 1e-6:
        mid = (ok + ng) / 2
        if solve(mid):
            ok = mid
        else:
            ng = mid
    return ok


def bin_search(ok, ng, solve):
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if solve(mid):
            ok = mid
        else:
            ng = mid
    return ok


ok = 0
ng = 10**10

ave = bin_search_double(ok, ng, check_average)
med = bin_search(ok, ng, check_median)

print(ave)
print(med)