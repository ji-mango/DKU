import turtle

def draw(x,y):
     t.goto(x,y)

t=turtle.Turtle()
t.penup()
t.setx(-100)
t.sety(100)
t.shape("turtle")
t.pensize(10)
s=turtle.Screen()
s.onscreenclick(draw)
