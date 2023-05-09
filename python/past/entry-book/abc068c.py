N, M = map(int, input().split())
a, b = [], []
g = [[] for _ in range(N)]
for i in range(M):
    aa, bb = map(int, input().split())
    aa -= 1
    bb -= 1
    a.append(aa)
    b.append(bb)
    g[aa].append(bb)
    g[bb].append(aa)
    
flg = False
for pos in g[0]:
    for nex in g[pos]:
        if nex==N-1:
            flg = True
            
if flg: print("POSSIBLE")
else: print("IMPOSSIBLE")
