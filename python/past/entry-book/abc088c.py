c = [list(map(int, input().split())) for _ in range(3)]

flg = True

if not (c[0][0]-c[1][0]==c[0][1]-c[1][1]==c[0][2]-c[1][2]): flg = False
if not (c[1][0]-c[2][0]==c[1][1]-c[2][1]==c[1][2]-c[2][2]): flg = False
if not (c[0][0]-c[0][1]==c[1][0]-c[1][1]==c[2][0]-c[2][1]): flg = False
if not (c[0][1]-c[0][2]==c[1][1]-c[1][2]==c[2][1]-c[2][2]): flg = False

if flg: print("Yes")
else: print("No")
