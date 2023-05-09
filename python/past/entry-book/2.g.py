from collections import deque, defaultdict

Q = int(input())
q = deque()

for _ in range(Q):
    query = input().split()
    if int(query[0])==1:
        q.append([query[1], int(query[2])])
        # print([query[1], int(query[2])])
    else:
        n = int(query[1])
        dt = defaultdict(int)
        res = 0
        while n>0 and len(q)>0:
            t = q.popleft()
            if t[1]<=n:
                n -= t[1]
                dt[t[0]] += t[1]
            else:
                t[1] -= n
                dt[t[0]] += n
                n = 0
                q.appendleft([t[0], t[1]])
        for v in dt.values():
            res += v**2
        print(res)
