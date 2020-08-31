import turtle

class MyTurtle(turtle.Turtle) :
    def __init__(self) :
        super().__init__()
        self.shape("turtle")
        self.hideturtle()
        self.penup()
        self.speed(0)

        self.window = turtle.Screen()
        self.window.onclick(self.draw)

    def loop(self) :
        self.window.mainloop()

class Mission(MyTurtle) :
    def __init__(self) :
        super().__init__()

    def draw(self, x, y) :
        self.goto(x, y)
        self.showturtle()
        self.pendown()
        self.speed(1)

mission = Mission()
mission.draw(-250, 250)

#미로 그리기
maze = turtle.Turtle()
def drawMaze(maze, x, y) :
    maze.hideturtle()
    maze.penup()
    maze.speed(0) #거북이 속도 가장 빠르게
    maze.color("green") #거북이 색깔
    for i in range(2) :
        if i == 1 :
            maze.goto(x + 100, y + 100)
        else :
            maze.goto(x, y)
        maze.pendown()
        maze.fd(300)
        maze.right(90)
        maze.fd(300)
        maze.left(90)
        maze.fd(300)
        maze.penup()
drawMaze(maze, -300, 200)


#방해물 여러 개
enemiesN = 3 #방해물 개수 지정
enemies = [] #방해물 리스트 생성

for count in range(enemiesN) : #방해물 객체의 색, 모양, 크기 등 지정
    enemies.append(turtle.Turtle())
    enemies[count].hideturtle()
    enemies[count].color("red")
    enemies[count].shape("circle")
    enemies[count].shapesize(0.5, 0.5)
    enemies[count].speed(7)
    enemies[count].penup()

enemies[0].setposition(-200, 200) #방해물 위치설정
enemies[1].setposition(0, 100)
enemies[2].setposition(300, -100)

for count in range(enemiesN) : #방해물 보여주기
    enemies[count].showturtle()

enemies[0].left(90) #방해물 거북이 움직이기
enemies[2].right(90)
while True :
    enemies[0].fd(100)
    enemies[2].left(180)
    enemies[1].fd(100)
    enemies[2].fd(100)
    enemies[0].left(180)
    enemies[1].left(180)
