A, B, C = map(int, input().split())

MOD = 998244353

A %= MOD
B %= MOD
C %= MOD
Sa = (A*(A+1)) // 2 % MOD 
Sb = (B*(B+1)) // 2 % MOD 
Sc = (C*(C+1)) // 2 % MOD
    
ans = (((Sa * Sb) % MOD) * Sc) % MOD

# print(Sa, Sb, Sc)
print(ans)
