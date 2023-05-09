A, B, X = map(int, input().split())

def bin_search(ok, ng, solve):
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if solve(mid):
            ok = mid
        else:
            ng = mid
    return ok

def dig10(x):
    res = 0
    while(x>0):
        x //= 10
        res += 1
    return res

ok = 0
ng = int(1e9+1)
solve = lambda x: A*x+B*dig10(x) <= X

ans = bin_search(ok, ng, solve)

print(ans)
# if ans < NA: print(ans)
# else: print(-1)