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

if __name__ == "__main__":
    val = 1000
    A = [1, 2, 3 , 1004, 2874]
    
    ok = 4
    ng = 0
    solve = lambda x: A[x] > val
    
    print(bin_search(ok, ng, solve))
    