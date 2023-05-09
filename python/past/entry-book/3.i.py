N = int(input())
Q = int(input())
queries = [list(map(int, input().split())) for _ in range(Q)]

row_idx = [i for i in range(N)]
col_idx = [i for i in range(N)]

transpose = False

for q in queries:
    if q[0]==1:
        a, b = q[1]-1, q[2]-1
        if not transpose: row_idx[a], row_idx[b] = row_idx[b], row_idx[a]
        else: col_idx[a], col_idx[b] = col_idx[b], col_idx[a]
    elif q[0]==2:
        a, b = q[1]-1, q[2]-1
        if not transpose: col_idx[a], col_idx[b] = col_idx[b], col_idx[a]
        else: row_idx[a], row_idx[b] = row_idx[b], row_idx[a]
    elif q[0]==3:
        transpose = not transpose
    else:
        a, b = q[1]-1, q[2]-1
        if not transpose: val = N*row_idx[a] + col_idx[b]
        else: val = N*row_idx[b] + col_idx[a]
        print(val)