N, Q = map(int, input().split())
S = list(list(map(int, input().split())) for _ in range(Q))

g = [[False]*N for _ in range(N)]

for q in S:
    if q[0] == 1:
        q[1] -= 1
        q[2] -= 1
        g[q[1]][q[2]] = True
    elif q[0] == 2:
        q[1] -= 1
        for i in range(N):
            if g[i][q[1]]:
                g[q[1]][i] = True
    else:
        q[1] -= 1
        tmp = g[q[1]].copy()
        for i in range(N):
            if i == q[1]: continue
            if g[q[1]][i]:
                for j in range(N):
                    if j == q[1]: continue
                    if g[i][j]:
                        tmp[j] = True
        g[q[1]] = tmp
                        
for i in range(N):
    s = ""
    for j in range(N):
        if g[i][j]:
            s += 'Y'
        else:
            s += 'N'
    print(s)
