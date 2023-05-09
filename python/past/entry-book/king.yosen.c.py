N = int(input())
A, B = [], []
arr = []
for i in range(N):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)
    arr.append([-a-b, a, b])
    
arr.sort()

ans = 0
for i in range(N):
    c, a, b = arr[i]
    if i%2==0:
        ans += a
    else:
        ans -= b

print(ans)
