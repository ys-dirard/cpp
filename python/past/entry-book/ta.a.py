# ok: 解が存在する範囲
# ng: 解が存在しない範囲
# 半開区間(ng, ok] or [ok, ng)を考える
# 解であるかどうかはsolve関数(別途用意)で判定
# -> mが解であればtrueを返す

def bin_search(ok, ng, solve):
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if solve(mid):
            ok = mid
        else:
            ng = mid
    return ok

N, K = map(int, input().split())
A = list(map(int, input().split()))

ok = N
ng = 0
solve = lambda x: x >= N or A[x] >= K

ans = bin_search(ok, ng, solve)

if ans < N: print(ans)
else: print(-1)
