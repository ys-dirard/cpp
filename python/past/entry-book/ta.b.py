import heapq

N = int(input())
ab = [list(map(int, input().split())) for _ in range(N)]

pq = []
ans = 0
end = 0

for a, b in ab:
    heapq.heappush(pq, [b, a])
    
while len(pq)>0:
    e = heapq.heappop(pq)
    if end < e[1]:
        ans += 1
        end = e[0]
        
print(ans)
