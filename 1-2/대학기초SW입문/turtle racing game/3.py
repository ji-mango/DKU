import turtle

class MyTurtle(turtle.Turtle) :
    def __init__(self, shape) : #모양 설정된 부모 클래스
        super(MyTurtle, self).__init__() #screen 띄워 주는 듯
        self.shape(shape) #거북이 모양 설정
        self.getscreen().bgcolor("black") #배경


#방해하는 거북이 객체
class Enemy(MyTurtle) :
    def __init__(self, shape, color, speed) :
        super().__init__(shape)
        self.speed(speed)#거북이 속도
        self.color(color)#거북이 색깔
        self.shapesize(0.5,0.5) #거북이 크기

    #def position은 작동 안 됨
    def position(self) :
        self = get.turtle()
        self.fd(200)

#미션 수행할 거북이 객체
class Mission(MyTurtle) :
    def __init__(self, shape, color) :
        super().__init__(shape)
        self.color(color)


#객체 생성        
t1 = Mission("turtle", "pink")
t2 = Enemy("circle", "red", 5)
