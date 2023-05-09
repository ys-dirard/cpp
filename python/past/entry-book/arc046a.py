N = int(input())

keta = (N - 1) // 9 + 1
amari = N % 9
if amari==0:
    amari = 9

base = (pow(10, keta)-1)/9
ans = int(base * amari)


print(ans)