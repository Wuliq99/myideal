面向对象VS面向过程

依赖倒转其实可以说是面向对象设计的标志，用哪种语言来编写 

程序不重要，如果编写时考虑的都是如何针对抽象编程而不是针对细 

节编程，即程序中所有的依赖关系都是终止于抽象类或者接口，那就 

是面向对象的设计，反之那就是过程化的设计了





继承--复制

```` python
class GrandFather:
    def __init__(self):
        self.address="上海"
        print("执行1")
    def say(self):
        print("我是爸爸")

class Father:
    def __init__(self):
        self.age=100
        print("执行2")
    def where(self):
        print("我现在住在：",self.address)

class Son(GrandFather,Father):
    def __init__(self):
        super().__init__()

    def say(self):
        print("我是儿子")

son=Son()
son.where()
````

