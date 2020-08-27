class Person:
     def __init__(self,name,number):
          self.name=name
          self.number=number

class Student(Person):
     def __init__(self,name,number,gpa):
          super().__init__(name,number)
          self.gpa=gpa
          self.classes=[]

     def setGpa(self,gpa):
          self.gpa=gpa

     def enrollCourse(self,course):
          self.classes.append(course)

     def __str__(self):
          return "\n이름="+self.name+"\n주민번호="+self.number+\
                 "\n수강과목="+str(self.classes)+"\n평점="+str(self.gpa)


class Teacher(Person):
     def __init__(self,name,number):
          super().__init__(name,number)
          self.courses=[]
          self.salary=30000000

     def assignTeaching(self,course):
          self.courses.append(course)

     def __str__(self):
          return "\n이름="+self.name+"\n주민번호="+self.number+\
                 "\n강의과목="+str(self.courses)+"\n월급="+str(self.salary)


kim=Student("김지민","32191105",0)
kim.enrollCourse("파이썬")
print(kim)

lee=Teacher("이철수","11223344")
lee.assignTeaching("파이썬")
print(lee)
