# PAST 2.B

S = input()

dt = {"a": 0, "b": 0, "c": 0}
for s in S:
    dt[s] += 1
    
M = 0
for d in dt:
    if M < dt[d]:
        M = dt[d]
        ans = d
        
print(ans)