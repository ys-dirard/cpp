import sys
sys.setrecursionlimit(1000000)

N = int(input())

ans = 0

def dfs(n):
    global ans
    st = set()
    nn = n
    while nn>0:
        st.add(nn % 10)
        nn //= 10
    if len(st)==3 and n<=N:
        ans = ans + 1
        
    for i in [3, 5, 7]:
        tmp = n*10+i
        if tmp<=N:
            dfs(tmp)
        
        
dfs(0)

print(ans)
