#리스트 함축 사용
lt7=[x**2 for x in range(10) if x%3==0]

#리스트 함축 사용안함
lt8=[]

for x in range(10):
    if x%3==0:
        lt8.append(x**2)
        #or lt8+=[x**2]

print(lt7)
print(lt8)
