# import pypyjit
# pypyjit.set_param("max_unroll_recursion=-1")
import sys
sys.setrecursionlimit(1000000)



N = int(input())
ps = [int(input()) - 1 for _ in range(N)]
Q = int(input())
# queries[a]: aの値に対応する[クエリ番号、bの値]を並べたもの
queries = [[] for _ in range(N)]
for i in range(Q):
    a, b = map(int, input().split())
    queries[a-1].append([i, b-1])

g = [[] for _ in range(N)]
for i in range(N):
    if ps[i]==-2:
        pres = i
    else:
        g[ps[i]].append(i)
        
ans = [False]*Q
# boss[i]: 頂点iが今見ている頂点の上司ならTrue
boss = [False]*N

def dfs(pos):
    for q, b in queries[pos]:
        ans[q] = boss[b]
        
    boss[pos] = True
    
    for nex in g[pos]:
        dfs(nex)
    boss[pos] = False
    
dfs(pres)

for flg in ans:
    if flg: print("Yes")
    else: print("No")
    