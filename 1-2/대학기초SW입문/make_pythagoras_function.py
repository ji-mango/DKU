#그냥 리스트로
list=[]

for x in range(1,30):
    for y in range(x, 30):
        for z in range(y,30):
            if x**2+y**2==z**2:
                list.append((x,y,z))
print(list)


#함축식 리스트로
n_list=[(x,y,z) for x in range(1,30) for y in range(x, 30) for z in range(y,30)
        if x**2+y**2==z**2]
print(n_list)
