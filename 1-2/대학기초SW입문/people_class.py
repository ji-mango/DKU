class Person:
    def __init__(self,name,age):
        self.name=name
        self.age=age
    def __repr__(self): #객체를 문자열로 나타내는 함수
        return "<이름:%s,나이:%s>"%(self.name,self.age)

def keyAge(person): #정렬의 기준을 반환하는 함수
    return person.age

people=[Person("홍길동",20),Person("김철수",35),Person("최자영",38)]
print(sorted(people,key=keyAge))

# keyAge 함수를 안쓸 경우
#print(sorted(people,key=lambda p:p.age))
