rows=6
cols=6
table=[]

#2차원 리스트 생성
for row in range(rows):
    table+=[[0]*cols]

#리스트에 rows, cols 더하여 저장
for row in range(rows):
    for col in range(cols):
        table[row][col]=(row+1+col+1)

print(table)
