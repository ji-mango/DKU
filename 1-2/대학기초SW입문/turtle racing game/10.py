import turtle
import random

class MyTurtle(turtle.Turtle) :
    def __init__(self, color, shape = 'turtle') :
        super().__init__()
        self.color = color
        self.shape = shape
        
    def setColor(self, color) :
        self.color = color

    def setShape(self, shape) :
        self.shape = shape



class Race(MyTurtle) :
    def __init__(self, color, shape, x, y) :
        super().__init__(color, shape)
        self.color = color
        self.shape = shape
        self.x = x
        self.y = y

    def moveTo(self) : #경주시작 자리로 이동
        self.penup()
        self.goto(self.x, self.y)
        self.pendown()

    def run(self) :
        for turn in range(100) :
            self.fd(random.randint(1, 5))



class MakeRaceLine(MyTurtle) :
    def __init__(self, color, shape, x, y, speed = 10) :
        super().__init__(color, shape)
        self.color = color
        self.shape = shape
        self.x = x
        self.y = y
        self.speed = speed
        self.penup()

    def make(self) :
        self.goto(self.x, self.y)
        for step in range(15) :
            self.right(90)
            self.fd(10)
            self.pendown()
            self.fd(150)
            self.penup()
            self.backward(160)
            self.left(90)
            self.fd(20)

raceLine = MakeRaceLine('black', 'turtle', -140, 140, 0)
raceLine.make()

run1 = Race('red', 'turtle', -160, 100)
run1.moveTo()
run1.run()
run2 = Race('blue', 'turtle', -160, 70)
run2.moveTo()
run2.run()
run3 = Race('pink', 'turtle', -160, 40)
run3.moveTo()
run3.run()
