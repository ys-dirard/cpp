N, L = map(int, input().split())
A = list(map(int, input().split()))
S = [0]
for a in A:
    S.append(a+S[-1])


def bin_search(ok, ng, solve):
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if solve(mid):
            ok = mid
        else:
            ng = mid
    return ok


def _solve(mid):
    # midが条件を満たしているかを調べる
    # C[i]: i番目の切れ目を切れるかどうか
    # D[i]: C[i]の差分、imos用(C[i]=D[i]+...+D[0])
    C = [0]*(N+1)
    D = [0]*(N+1)
    D[0] += 1; D[1] -= 1
    
    # l, r: 尺取り法、切れ目の位置は単調増加する
    l = 0
    r = 0
    for i in range(N+1):
        # imos法の差分からの復元、C[i]の復元にはD[i]までが必要
        if i>0:
            C[i] = C[i-1] + D[i]
        else:
            C[i] = D[i]
            
        if C[i]==0:
            continue
        
        while l<=N and S[l] - S[i] < mid:
            l += 1
        if l > N:
            continue
        
        while r+1<=N and S[r+1] - S[i] <= L:
            r += 1
            
        D[l] += 1
        if r+1 <= N:
            D[r+1] -= 1
    # C[N] = C[N-1] + D[N]
    return C[N] > 0


ok = 0
ng = 10**15

ans = bin_search(ok, ng, _solve)
print(ans)
