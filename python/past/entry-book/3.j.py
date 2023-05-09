import bisect

N, M = map(int, input().split())

a = list(map(int, input().split()))

L = [10**9]*(N+1)

for v in a:
    i = bisect.bisect_right(L, -v)
    # print(i)
    if i == N: print(-1)
    else:
        L[i] = -v
        print(i+1)
    # print(L)
    