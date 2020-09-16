class Student:
    def __init__(self,name,grade,number):
        self.name=name
        self.grade=grade
        self.number=number
    def __repr__(self):
        return repr((self.name,self.grade,self.number))

students=[
    Student('홍길동',3.9,20190303),
    Student('김철수',3.0,20190302),
    Student('최자영',4.3,20190301),
    Student('박소현',4.5,20190304),
    Student('김기수',4.5,20190305)
    ]

print(sorted(students, key=lambda s:s.grade)) #인덱스는 사용못함!!!!
