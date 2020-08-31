import turtle


class MyTurtle(turtle.Turtle):
    def __init__(self):
        super(MyTurtle, self).__init__()
        self.shape("turtle")
        self.shapesize(2, 2)
        self.color("purple")

        self.window = turtle.Screen()
        self.window.onclick(self.on_mouse_clicked)

        self.is_moving = False

    def loop(self):
        self.window.mainloop()

    def on_mouse_clicked(self, x, y):
        print("clicked ({0}, {1})".format(x, y))
        if self.is_moving is True:
            return

        self.is_moving = True
        self.goto(x, y)
        self.is_moving = False

class Myturtle(turtle.Turtle):
    def __init__(self):
        super(MyTurtle, self).__init__()
        self.shape("turtle")
        self.shapesize(2, 2)
        self.color("blue")

        self.window = turtle.Screen()
        self.window.onclick(self.on_mouse_clicked)

        self.is_moving = False

    def loop(self):
        self.window.mainloop()

    def on_mouse_clicked(self, x, y):
        print("clicked ({0}, {1})".format(x, y))
        if self.is_moving is True:
            return

        self.is_moving = True
        self.goto(x, y)
        self.is_moving = False


t = MyTurtle()
t.loop()
