import heapq

N = int(input())
ab = [list(map(int, input().split())) for _ in range(N)]
tasks = [[] for _ in range(N)]

for aa, bb in ab:
    tasks[aa-1].append(-bb)

pq = []
heapq.heapify(pq)

ans = 0
res = []
for i in range(N):
    for e in tasks[i]:
        heapq.heappush(pq, e)
    val = heapq.heappop(pq)
    ans += -val
    res.append(ans)
    
for v in res:
    print(v)
    