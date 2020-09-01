import math

def calcircle(r):
    area=r*r*math.pi
    circum=2*r*math.pi
    return(area,circum)

r=float(input("원의 반지름을 입력하시오:"))
(a,c)=calcircle(r)
print("원의 넓이는 %lf이고 둘레는 %lf이다."%(a,c)) 
    
