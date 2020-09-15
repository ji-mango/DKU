class Dog:
    def __init__(self,name,age):
        self.__name=name #private으로 인스턴스 변수 생성
        self.__age=age   #객체명.인스턴스변수명 접근 불가능(정보 은닉)

    def bark(self):
        print(self.__name,"is barking.")

    def getName(self):
        return self.__name

    def getAge(self):
        return self.__age

    def setName(self, name):
        self.__name=name

    def setAge(self,age):
        self.__age=age
        
