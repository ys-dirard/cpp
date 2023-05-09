N, M = map(int, input().split())
mm = [list(map(int, input().split())) for _ in range(N)]
sm = [list(map(int, input().split())) for _ in range(M)]

def bin_search(ok, ng, solve):
    while abs(ok - ng) > 1e-10:
        mid = (ok + ng) / 2
        if solve(mid):
            ok = mid
        else:
            ng = mid
    return ok

def _solve(mid):
    mv = [b-mid*a for a, b in mm]
    mv = sorted(mv, reverse=True)
    sv = [b-mid*a for a, b in sm]
    sv = sorted(sv, reverse=True)
    res = max(sum(mv[:4]) + sv[0], sum(mv[:5]))
    return res >= 0

ok = 0
ng = 100000

ans = bin_search(ok, ng, _solve)
print(ans)
