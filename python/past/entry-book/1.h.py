N = int(input())
C = list(map(int, input().split()))
Q = int(input())
S = [list(map(int, input().split())) for _ in range(Q)]

m_odd = min(C[::2])
m_all = min(C)
sub_odd = 0
sub_all = 0
ans = 0

for q in S:
    if q[0] == 1:
        q[1] -= 1
        if (q[1] % 2 == 0 and C[q[1]] >= q[2] + sub_odd) or (q[1] % 2 == 1 and C[q[1]] >= q[2] + sub_all):
            C[q[1]] -= q[2]
            ans += q[2]
            if C[q[1]] - sub_all < m_all:
                m_all = C[q[1]] - sub_all
            if q[1] % 2 == 0 and C[q[1]] - sub_odd < m_odd:
                m_odd = C[q[1]] - sub_odd
    elif q[0] == 2:
        
        if m_odd >= q[1]:
            m_odd -= q[1]
            sub_odd += q[1]
            ans += (N+1)//2 * q[1]
            if m_odd < m_all:
                m_all = m_odd
    else:
        if m_all >= q[1]:
            ans += N * q[1]
            m_all -= q[1]
            m_odd -= q[1]
            sub_all += q[1]
            sub_odd += q[1]
    # print(q)
    # print(C)
    # print(m_odd, m_all, sub_odd, sub_all)
    # print(ans)
            
print(ans)
