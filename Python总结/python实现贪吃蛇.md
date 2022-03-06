***最近完成了Pygame库的基础入门学习，写一个小游戏练练手。友情提示：练手项目有Bug，复制需谨慎***

类型一：窗口可调
```python
import pygame
import sys
import random

class Snack():
    def __init__(self):
        self.length = 3  # 蛇身的长度

        # bodys中的每个字典为蛇身每一节的位置
        self.bodys = [
            {"x": 50, "y": 50, "width": 10, "height": 10},
            {"x": 50, "y": 60, "width": 10, "height": 10},
            {"x": 50, "y": 70, "width": 10, "height": 10}
        ]

        self.direction = 0  # 蛇运动的方向

    # 打印蛇
    def show(self):
        for body in self.bodys:
            pygame.draw.rect(screen, (245, 135, 155), (body["x"], body["y"], body["width"], body["height"]), 0)

    # 增加蛇身，每次调用增加一节
    def addnode(self, node):
        self.bodys.insert(0, node)

    # 缩短蛇身，每次调用减少一节
    def delnode(self):
        self.bodys.pop()


# 生成随机食物
def creat_food(snack):
    # 食物的x,y坐标必须能被10整除，因为蛇身的每节的坐标是十的的倍数
    x = random.randint(0, 500) // 10 * 10
    y = random.randint(0, 300) // 10 * 10

    # 防止食物生成在蛇身上
    for body in snack.bodys:
        if x == body["x"] and y == body["y"]:
            return creat_food(snack)
    return x, y

score=0
BLACK = 0, 0, 0  # 设置颜色，黑色
snack = Snack()  # 创建蛇的实例
pygame.init()  # 初始化

size = width, height = 600, 400
screen = pygame.display.set_mode(size, pygame.RESIZABLE)  # 创建窗口,窗口大小可变
clock = pygame.time.Clock()  # 创建clock对象，控制游戏刷新速度
food = creat_food(snack)  # 创建食物
eat_flag = 0  # 设置食物是否被吃的标志，0表示食物未被吃


while True:
    clock.tick(3)  # 控制刷新次数
    for event in pygame.event.get():  # 获得键盘事件

        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT and snack.direction != 1:
                snack.direction = 3
            elif event.key == pygame.K_RIGHT and snack.direction != 3:
                snack.direction = 1
            elif event.key == pygame.K_UP and snack.direction != 2:
                snack.direction = 0
            elif event.key == pygame.K_DOWN and snack.direction != 0:
                snack.direction = 2
            elif event.key == pygame.K_ESCAPE:
                sys.exit()

                #当窗口大小改变时，发生此事件
        elif event.type == pygame.VIDEORESIZE:
            size = width, height =event.w,event.h
            screen = pygame.display.set_mode(size, pygame.RESIZABLE)
    if snack.direction == 0:
        snack.addnode({"x": snack.bodys[0]["x"], "y": snack.bodys[0]["y"] - 10, "width": 10, "height": 10})

    elif snack.direction == 1:
        snack.addnode({"x": snack.bodys[0]["x"] + 10, "y": snack.bodys[0]["y"], "width": 10, "height": 10})

    elif snack.direction == 2:
        snack.addnode({"x": snack.bodys[0]["x"], "y": snack.bodys[0]["y"] + 10, "width": 10, "height": 10})

    elif snack.direction == 3:
        snack.addnode({"x": snack.bodys[0]["x"] - 10, "y": snack.bodys[0]["y"], "width": 10, "height": 10})

    if snack.bodys[0]["x"] == food[0] and snack.bodys[0]["y"] == food[1]:
        eat_flag = 1
    else:
        snack.delnode()

    # 判断是否碰壁
    if snack.bodys[0]["x"] < 0 or snack.bodys[0]["x"] > width or snack.bodys[0]["y"] < 0 or snack.bodys[0][
        "y"] > height:
        break

    # 判断是否要吃自己
    for i in range(1, snack.length):
        if snack.bodys[0]["x"] == snack.bodys[i]["x"] and snack.bodys[0]["y"] == snack.bodys[i]["y"]:
            break

    screen.fill(BLACK)  # 填充黑色
    if eat_flag:
        score+=1
        food = creat_food(snack)
        eat_flag = 0
        # 重新绘制图像
    pygame.draw.rect(screen, (255, 255, 0), (food[0], food[1], 10, 10), 0)
    snack.show()
    pygame.display.update()  # 必须存在此类函数，因为要重绘窗口

```
类型二：直接全屏

```python
import pygame
import sys
import random

class Snack():
    def __init__(self):
        self.length = 3  # 蛇身的长度

        # bodys中的每个字典为蛇身每一节的位置
        self.bodys = [
            {"x": 50, "y": 50, "width": 10, "height": 10},
            {"x": 50, "y": 60, "width": 10, "height": 10},
            {"x": 50, "y": 70, "width": 10, "height": 10}
        ]

        self.direction = 0  # 蛇运动的方向

    # 打印蛇
    def show(self):
        for body in self.bodys:
            pygame.draw.rect(screen, (245, 135, 155), (body["x"], body["y"], body["width"], body["height"]), 0)

    # 增加蛇身，每次调用增加一节
    def addnode(self, node):
        self.bodys.insert(0, node)

    # 缩短蛇身，每次调用减少一节
    def delnode(self):
        self.bodys.pop()


# 生成随机食物
def creat_food(snack):
    # 食物的x,y坐标必须能被10整除，因为蛇身的每节的坐标是十的的倍数
    x = random.randint(0, 500) // 10 * 10
    y = random.randint(0, 300) // 10 * 10

    # 防止食物生成在蛇身上
    for body in snack.bodys:
        if x == body["x"] and y == body["y"]:
            return creat_food(snack)
    return x, y


BLACK = 0, 0, 0  # 设置颜色，黑色
snack = Snack()  # 创建蛇的实例
pygame.init()  # 初始化

vInfo = pygame.display.Info()  # 为了窗口全屏显示，要获得全屏时窗口的大小
size = width, height = vInfo.current_w, vInfo.current_h

# size = width, height = 600, 400
screen = pygame.display.set_mode(size, pygame.FULLSCREEN)  # 创建窗口
clock = pygame.time.Clock()  # 创建clock对象，控制游戏刷新速度
food = creat_food(snack)  # 创建食物
eat_flag = 0  # 设置食物是否被吃的标志，0表示食物未被吃

while True:
    clock.tick(3)  # 控制刷新次数
    for event in pygame.event.get():  # 获得键盘事件

        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT and snack.direction != 1:
                snack.direction = 3
            elif event.key == pygame.K_RIGHT and snack.direction != 3:
                snack.direction = 1
            elif event.key == pygame.K_UP and snack.direction != 2:
                snack.direction = 0
            elif event.key == pygame.K_DOWN and snack.direction != 0:
                snack.direction = 2
            elif event.key == pygame.K_ESCAPE:
                sys.exit()
    if snack.direction == 0:
        snack.addnode({"x": snack.bodys[0]["x"], "y": snack.bodys[0]["y"] - 10, "width": 10, "height": 10})

    elif snack.direction == 1:
        snack.addnode({"x": snack.bodys[0]["x"] + 10, "y": snack.bodys[0]["y"], "width": 10, "height": 10})

    elif snack.direction == 2:
        snack.addnode({"x": snack.bodys[0]["x"], "y": snack.bodys[0]["y"] + 10, "width": 10, "height": 10})

    elif snack.direction == 3:
        snack.addnode({"x": snack.bodys[0]["x"] - 10, "y": snack.bodys[0]["y"], "width": 10, "height": 10})

    if snack.bodys[0]["x"] == food[0] and snack.bodys[0]["y"] == food[1]:
        eat_flag = 1
    else:
        snack.delnode()

    # 判断是否碰壁
    if snack.bodys[0]["x"] < 0 or snack.bodys[0]["x"] > width or snack.bodys[0]["y"] < 0 or snack.bodys[0][
        "y"] > height:
        break

    # 判断是否要吃自己
    for i in range(1, snack.length):
        if snack.bodys[0]["x"] == snack.bodys[i]["x"] and snack.bodys[0]["y"] == snack.bodys[i]["y"]:
            break

    screen.fill(BLACK)  # 填充黑色
    if eat_flag:
        food = creat_food(snack)
        eat_flag = 0
        # 重新绘制图像
    pygame.draw.rect(screen, (255, 255, 0), (food[0], food[1], 10, 10), 0)
    snack.show()
    pygame.display.update()  # 必须存在此类函数，因为要重绘窗口

```