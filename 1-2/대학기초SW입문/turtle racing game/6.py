#방해물 거북이 객체 class

import turtle

class MyTurtle(turtle.Turtle) :
    def __init__(self) : #모양 설정된 부모 클래스
        super().__init__() #screen 띄워 주는 듯
        self.shape("circle") #거북이 모양 설정
        self.getscreen().bgcolor("black") #배경색 설정
        self.shapesize(0.5, 0.5)

    def drawMaze(self, x, y) :
        self.penup()
        self.speed(0) #거북이 속도 가장 빠르게
        self.color("yellow") #거북이 색깔
        for i in range(2) :
            if i == 1 :
                self.goto(x + 100, y + 100)
            else :
                self.goto(x, y)
            self.pendown()
            self.fd(300)
            self.right(90)
            self.fd(300)
            self.left(90)
            self.fd(300)
            self.penup()

    def position(self, x, y) :
        self.goto(x, y)
        self.color("red")
        self.showturtle()
    
    def move(self) :
        self.speed(1)
        self.right(90)
        while True :
            self.fd(100)
            self.left(180)

#객체 생성        
t1 = MyTurtle()
t1.drawMaze(-300, 200)
t1.position(-200, 300)
t1.move()
