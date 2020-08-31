from turtle import *
from random import randint

speed(10)
penup()
goto(-140,140)

for step in range(15):
    write(step,align='center')
    right(90)
    forward(10)
    pendown()
    forward(150)
    penup()
    backward(160)
    left(90)
    forward(20)

class MyTurtle(Turtle):
    def __init__(self,color,shape):
        super().__init__()
        self.color=color
        self.shape=shape

    def Setcolor(self,color):
        self.color=color

    def Setshape(self,shape):
        self.shape=shape

    def Getcolor(self):
        return self.color

    def Getshape(self):
        return self.shape

class RaceTurtle(MyTurtle):
    def __init__(self,color,shape,x,y):
        super().__init__(color,shape)
        self.color=color
        self.shape=shape
        self.x=x
        self.y=y

    def move(self):
        self.penup()
        self.goto(self.x,self.y)
        self.pendown()


        
ada=RaceTurtle('red','turtle',-160,100)
ada.move

bob=RaceTurtle('blue','turtle',-160,70)
bob.move

kim=RaceTurtle('pink','turtle',-160,40)
kim.move

lee=RaceTurtle('black','turtle',-160,10)
lee.move

for turn in range(100):
    ada.forward(randint(1,5))
    bob.forward(randint(1,5))
    kim.forward(randint(1,5))
    lee.forward(randint(1,5))
