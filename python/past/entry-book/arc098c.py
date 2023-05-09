N = int(input())
S = input()

Es = [0] * (N) # i番目までにEを向いている人数の累積和

for i in range(N):
    if(i):
        Es[i] = Es[i-1] + int(S[i]=='E')
    else:
        Es[0] = int(S[0]=='E')
        
ans = 1e9

for i in range(N):
    tmp = 0
    if(i>0):
        tmp += i-Es[i-1]
        
    if(i<N-1):
        tmp += Es[N-1] - Es[i]
        
    ans = min(ans, tmp)
    
print(ans)
    