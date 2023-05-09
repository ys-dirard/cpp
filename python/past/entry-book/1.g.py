N = int(input())
a = [list(map(int, input().split())) for _ in range(N-1)]

ans = -1e18

for b in range(pow(3, N)):
    group = [[], [], []]
    for i in range(N):
        g = b//pow(3, i) % 3
        group[g].append(i)
    
    tmp = 0
    for g in group:
        for i in range(len(g)):
            for j in range(i+1, len(g)):
                tmp += a[g[i]][g[j]-g[i]-1]
    ans = max(ans, tmp)
    
print(ans)
