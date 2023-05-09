N, X = map(int, input().split())
w = [int(input()) for _ in range(N)]

n1 = N // 2
n2 = N - n1

s1 = [dict() for _ in range(n1+1)]
s2 = [dict() for _ in range(n2+1)]

s1[0][0] = 1
for i in range(n1):
    for j in s1[i]:
        # j in s1[i+1]
        if j in s1[i+1]:
            s1[i+1][j] += s1[i][j]
        else:
            s1[i+1][j] = s1[i][j]
        # j+w[i] in s1[i+1]
        if j+w[i] in s1[i+1]: 
            s1[i+1][j+w[i]] += s1[i][j]
        else:
            s1[i+1][j+w[i]] = s1[i][j]
            
s2[0][0] = 1
for i in range(n2):
    for j in s2[i]:
        # j in s1[i+1]
        if j in s2[i+1]:
            s2[i+1][j] += s2[i][j]
        else:
            s2[i+1][j] = s2[i][j]
        # j+w[i] in s2[i+1]
        if j+w[n1+i] in s2[i+1]: 
            s2[i+1][j+w[n1+i]] += s2[i][j]
        else:
            s2[i+1][j+w[n1+i]] = s2[i][j]
            
        # if j+w[n1+i] in s2:
        #     s2[j+w[n1+i]] += s2[j]
        # else:
        #     s2[j+w[n1+i]] = s2[j]
            
ans = 0
for i1 in s1[n1]:
    if X-i1 in s2[n2]:
        ans += s1[n1][i1]* s2[n2][X-i1]
        
print(ans)