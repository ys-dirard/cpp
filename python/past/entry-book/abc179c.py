import math

N = int(input())

ans = 0

for a in range(1, N):
    # A*B+C=N -> A*B=N-C -> ABを固定するとA*B<NならCが1つに決まるのでOK!
    # Aを固定 -> A*B<NとなるBの個数を求める!
    b_cnt = (N-1)//a
    ans += b_cnt
                
print(ans)
