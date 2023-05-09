K = int(input())
A, B = map(int, input().split())

flg = False
for i in range(A, B+1):
    if i % K == 0:
        flg = True
        
if flg: print("OK")
else: print("NG")
