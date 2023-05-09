import heapq
import math

N, M = map(int, input().split())
hcood = [list(map(int, input().split())) for _ in range(N)]
lcood = [list(map(int, input().split())) for _ in range(M)]

def euclid_distance(s, t):
    v = math.sqrt((s[0]-t[0])**2 + (s[1]-t[1])**2)
    if not s[2]==t[2]: v *= 10
    return v

def prim(coods):
    n = len(coods)
    cnt = 0
    used = [False] * n
    res = 0
    
    g = []
    for s in coods:
        tmp = []
        for t in coods:
            tmp.append(euclid_distance(s, t))
        g.append(tmp)
    # print(g)
    
    q = []
    heapq.heappush(q, (0, 0))
    while cnt < n:
        # print(q[0])
        cost, pos = heapq.heappop(q)
        if used[pos]: continue
        res += cost
        used[pos] = True
        cnt += 1
        
        for nex, d in enumerate(g[pos]):
            if used[nex]:
                continue
            else:
                heapq.heappush(q, (d, nex))
        # print(cnt, res)

    return res

# print(prim(hcood))

ans = 10**18
for b in range(1<<M):
    coods = hcood.copy()
    for i in range(M):
        if (b) & (1<<i) > 0:
            coods.append(lcood[i])

    res = prim(coods)
    ans = min(ans, res)
    
print(ans)
