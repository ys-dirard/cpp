R, B = map(int, input().split())
x, y = map(int, input().split())

def bin_search(ok, ng, solve):
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if solve(mid):
            ok = mid
        else:
            ng = mid
    return ok

def solve(t):
    r, b = R, B
    if r<t or b<t:
        return False
    
    r -= t
    b -= t
    n = r // (x-1) + b // (y-1)
    return n >= t

ok = 0
ng = int(1e18+1)

ans = bin_search(ok, ng, solve)
print(ans)
