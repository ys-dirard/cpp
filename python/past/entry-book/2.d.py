def is_match(S, T):
    for i in range(len(S)-len(T)+1):
        ok = True
        
        for j in range(len(T)):
            if S[i+j] != T[j] and T[j] != '.':
                ok = False
                
        if ok: return True
    return False

S = input()
C = "abcdefghijklmnopqrstuvwxyz."
M = []

for c in C:
    T = c
    if is_match(S, T):
        M.append(T)
        
for c1 in C:
    for c2 in C:
        T = c1 + c2
        if is_match(S, T):
            M.append(T)
            
for c1 in C:
    for c2 in C:
        for c3 in C:
            T = c1 + c2 + c3
            if is_match(S, T):
                M.append(T)

print(len(M))