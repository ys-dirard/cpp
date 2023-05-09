A, R, N = map(int, input().split())

if R==1:
    print(A)
else:
    flg = False
    for i in range(N-1):
        A *= R
        if A > 1e9:
            flg = True
            break
    if flg:
        print("large")
    else:
        print(A)
