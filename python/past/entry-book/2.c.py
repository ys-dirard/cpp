N = int(input())
S = list(list(input()) for _ in range(N))

for i in range(N-2, -1, -1):
    for j in range(1, 2*N-2):
        X_flg = False
        for di, dj in [[1, -1], [1, 0], [1, 1]]:
            if S[i+di][j+dj] == "X": X_flg = True
            
        if(S[i][j]=="#" and X_flg):
            S[i][j] = "X"
            
for i in range(N):
    print("".join(S[i]))
        