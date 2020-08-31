import turtle
import random

class MyTurtle(turtle.Turtle) :
    def __init__(self, color, shape = 'turtle') :
        super().__init__()
        self.color(color)
        self.shape(shape)
        self.getscreen().bgcolor("gold") #배경색 지정
        
    def setColor(self, color) :
        self.color(color)

    def setShape(self, shape) :
        self.shape(shape)
        
#거북이 선수들 달리기
class Race(MyTurtle) :
     runnerNumber = 0 #정적변수 선언
     def __init__(self, color, shape, x, y) :
          super().__init__(color, shape)
          Race.runnerNumber += 1 #Race 클래스 불러올 때마다 정적변수의 값이 1씩 증가함
          self.number = Race.runnerNumber #정적변수의 값은 생성된 거북이의 선수 번호
          self.color(color)
          self.shape(shape)
          self.x = x
          self.y = y

     def moveTo(self) : #경주시작 자리로 이동
          self.penup()
          self.goto(self.x, self.y)
          self.pendown()

     def run(self) :
          self.write(str(self.number), font = ("Times New Roman", 16, "bold")) #거북이 선수 번호 출력
          for turn in range(200) :
               self.fd(random.randint(1, 5))
          self.run_x=self.xcor()

     
     def x_cor(self):
          return self.run_x


#레이스 선 만들기
class MakeRaceLine(MyTurtle) :
    def __init__(self, color, shape, x, y, speed = 10) :
        super().__init__(color, shape)
        self.color(color)
        self.shape(shape)
        self.x = x
        self.y = y
        self.speed(speed)
        self.penup()
        self.hideturtle() #레이스 선 만드는 거북이 안 보이게 함

    def make(self) :
        self.goto(self.x, self.y)
        for step in range(1, 33) :
            self.write(step, align = "center") # align은 정렬방식으로, center는 가운데 정렬임
            self.right(90)
            self.fd(10)
            self.pendown()
            self.fd(150)
            self.penup()
            self.backward(160)
            self.left(90)
            self.fd(20)

raceLine = MakeRaceLine('black', 'triangle', -320, 140, 0)
raceLine.make()

#우승후보 질문하고 입력 받기
asker = turtle.Turtle()
asker.color('white')
asker.penup()
asker.hideturtle()
asker.goto(-300, 250)
asker.write("<거북이 경마 게임>",
            font = ("Arial", 30, "italic"))
asker.goto(-300, 200)
num = turtle.textinput("1번 ~ 4번 중 선택", "누가 가장 멀리 갈 것 같나요?")
while True :
    if (int(num)<=4 and int(num)>=1) :
        asker.write("당신은 우승 후보로 " + str(num) + "번 거북이를 골랐습니다.", font = ("Arial", 20, "italic"))
        break
    else :
        num = turtle.textinput("1번 ~ 4번 중 선택", "다른 숫자를 입력하셨습니다. 다시 입력하세요.")

#거북이 선수 객체 생성
run1 = Race('salmon', 'turtle', -320, 100)
run1.moveTo()
run1.run()
run2 = Race('coral', 'turtle', -320, 70)
run2.moveTo()
run2.run()
run3 = Race('darkseagreen', 'turtle', -320, 40)
run3.moveTo()
run3.run()
run4 = Race('lightblue', 'turtle', -320, 10)
run4.moveTo()
run4.run()

#결과 출력
if num=='1':
     if run1.x_cor()>=run2.x_cor() and run1.x_cor()>=run3.x_cor() and run1.x_cor()>=run4.x_cor():
          asker.color('white')
          asker.goto(-330,-260)
          asker.write("1등입니다!\n축하합니다!!!",
                      font=("Arial",70,"italic"))
     else:
          asker.color('white')
          asker.goto(-330,-260)
          asker.write("당신의 거북이는\n1등이 아닙니다.",
                      font=("Arial",70,"italic"))
          
if num=='2':
     if run2.x_cor()>=run1.x_cor() and run2.x_cor()>=run3.x_cor() and run2.x_cor()>=run4.x_cor():
          asker.color('white')
          asker.goto(-330,-260)
          asker.write("1등입니다!\n축하합니다!!!",
                      font=("Arial",70,"italic"))
     
     else:
          asker.color('white')
          asker.goto(-330,-260)
          asker.write("당신의 거북이는\n1등이 아닙니다.",
                      font=("Arial",70,"italic"))

if num=='3':
     if run3.x_cor()>=run1.x_cor() and run3.x_cor()>=run2.x_cor() and run3.x_cor()>=run4.x_cor():
          asker.color('white')
          asker.goto(-330,-260)
          asker.write("1등입니다!\n축하합니다!!!",
                      font=("Arial",70,"italic"))
     
     else:
          asker.color('white')
          asker.goto(-330,-260)
          asker.write("당신의 거북이는\n1등이 아닙니다.",
                      font=("Arial",70,"italic"))

if num=='4':
     if run4.x_cor()>=run1.x_cor() and run4.x_cor()>=run2.x_cor() and run4.x_cor()>=run3.x_cor():
          asker.color('white')
          asker.goto(-330,-260)
          asker.write("1등입니다!\n축하합니다!!!",
                      font=("Arial",70,"italic"))
     
     else:
          asker.color('white')
          asker.goto(-330,-260)
          asker.write("당신의 거북이는\n1등이 아닙니다.",
                      font=("Arial",70,"italic"))
