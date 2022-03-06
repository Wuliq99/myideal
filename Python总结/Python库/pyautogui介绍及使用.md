# 					pyautogui介绍及使用

## 简介

> PyAutoGUI允许您的Python脚本**控制鼠标和键盘**，以自动与其他应用程序进行交互。该 API 设计为简单。PyAutoGUI适用于Windows，macOS和Linux，并在Python 2和3上运行。
>
> 要使用 pip 进行安装，请运行 。有关更多详细信息，请参阅[安装](https://pyautogui.readthedocs.io/en/latest/install.html)页面。`pip install pyautogui`
>
> 源代码可在以下网址获得：https://github.com/asweigart/pyautogui
>
> PyAutoGUI有几个功能：
>
> - 移动鼠标并在其他应用程序的窗口中单击。
> - 向应用程序发送击键（例如，填写表单）。
> - 截取屏幕截图，并给出图像（例如，按钮或复选框的图像），然后在屏幕上找到它。
> - 找到应用程序的窗口，然后移动、调整大小、最大化、最小化或关闭它（目前仅限 Windows）。
> - 显示警报和消息框。

## 常用函数介绍

```python
import pyautogui

screenWidth, screenHeight = pyautogui.size() # 得到屏幕尺寸
# (2560, 1440)

currentMouseX, currentMouseY = pyautogui.position() # 得到鼠标坐标
# (1314, 345)

pyautogui.moveTo(100, 150) # 移动光标到指定位置

pyautogui.click()          # 点击
pyautogui.click(100, 200)  # 移动光标到指定位置并点击
pyautogui.click('button.png') # 找到该图片出现的位置并点击

pyautogui.move(400, 0)      # 将光标从当前位置移动指定距离
pyautogui.doubleClick()     # 双击
pyautogui.moveTo(500, 500, duration=2, tween=pyautogui.easeInOutQuad)  # 移动光标并使用 duration 指定移动时间

pyautogui.write('Hello world!', interval=0.25)  # 输出字符串，interval 指定每个字符输出的间隔时间
pyautogui.press('esc')     # 按下 Esc 键. 所有的键名能被找到在 pyautogui.KEY_NAMES

with pyautogui.hold('shift'):  # Press the Shift key down and hold it.
    pyautogui.press(['left', 'left', 'left', 'left'])  # Press the left arrow key 4 times.
 # Shift key is released automatically.

pyautogui.hotkey('ctrl', 'c') # Press the Ctrl-C hotkey combination.

pyautogui.alert('This is the message to display.') # Make an alert box appear and pause the program until OK is clicked.
```

## 简单使用

### 		获取光标实时位置

```python
#获取光标实时位置
import time
import pyautogui as pag
while True:
    x, y = pag.position()  # 返回鼠标的坐标
    posStr = "Position:" + '('+str(x) + ',' + str(y)+')'
    print(posStr)  # 打印坐标
    time.sleep(0.2)
```

### 		将光标移动到指定位置并输出内容

```python
import pyautogui    #控制键盘和鼠标
import pyperclip    #控制电脑进行复制和粘贴
import time         #控制时间

#消息内容
content = """   
one\ntwo\nthree\nfour\nfive
"""

time.sleep(5)   #设置休眠时间，防止速度过快
for line in list(content.split("\n"))*10:
    if line:
        time.sleep(1)
        pyautogui.click(738,711)  #定位到指定位置
        pyperclip.copy(line)    #复制一行内容
        pyautogui.hotkey("ctrl","v") #粘贴，mac电脑则把ctrl换成command
        pyautogui.typewrite("\n")   #发送
        time.sleep(0.5) #每次发完间隔0.5s
```

## 小贴士

​		在使用 pyautogui 相关函数时，若发生程序死循环，可将光标移动到屏幕四个角中的任何一个，此时程序将异常终止（详情参照官方文档）。当然也可以在程序中加入以下语句禁用此功能

```python
pyautogui.FAILSAFE = True
```

## 参考

​		官方文档：https://pyautogui.readthedocs.io