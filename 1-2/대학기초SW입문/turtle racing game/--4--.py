#마우스 클릭으로 거북이 이동시킴

import turtle

class MyTurtle(turtle.Turtle) :
    def __init__(self, shape, color, speed) : #모양 설정된 부모 클래스
        super(MyTurtle,self).__init__() #screen 띄워 주는 듯
        self.shape(shape) #거북이 모양 설정
        self.speed(speed)#거북이 속도
        self.color(color)#거북이 색깔
        self.getscreen().bgcolor("black") #배경색 설정

        self.window = turtle.Screen() #그림 그려지는 캔버스 생성
        self.window.onclick(self.draw)#마우스 클릭 이벤트 처리 함수 등록

    def loop(self) :
        self.window.mainloop()
        
#방해하는 거북이 객체
class Enemy(MyTurtle) :
    def __init__(self, shape, color, speed) :
        super().__init__(shape, color, speed)
        self.shapesize(0.5,0.5) #거북이 크기
        self.pendown() #펜 들어서 왔다갔다 해도 남는 줄 없게 함

    #방해물 왔다갔다 움직임
    def move(self) :
        while True :
            self.right(100)
            self.left(100)

#미션 수행할 거북이 객체
class Mission(MyTurtle) :
    def __init__(self, shape, color, speed) :
        super().__init__(shape, color, speed)

    #클릭한 좌표(x, y)로 이동하는 함수
    def draw(self, x, y) :
        self.goto(x,y)


#객체 생성        
t1 = Mission("turtle", "white", 3)
t2 = Enemy("circle", "red", 5)
