# input
A = [list(map(int, input().split())) for i in range(3)]
N = int(input())
b = [int(input()) for i in range(N)]

# bingo card
bi = [[False]*3 for i in range(3)]

# check
for i in range(3):
    for j in range(3):
        if A[i][j] in b:
            bi[i][j] = True
print(bi)
# flag of bingo
flg = False

# check row/col
for i in range(3):
    if(bi[i][0] and bi[i][1] and bi[i][2]): flg = True
    if(bi[0][i] and bi[1][i] and bi[2][i]): flg = True
  
# check diagonal
if(bi[0][0] and bi[1][1] and bi[2][2]): flg = True
if(bi[0][2] and bi[1][1] and bi[2][0]): flg = True

# print answer
if flg: print("Yes")
else: print("No")
    