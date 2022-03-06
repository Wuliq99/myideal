## 图像

cv2.imread()

使用 **[cv.imread()](https://docs.opencv.org/4.0.0/d4/da8/group__imgcodecs.html#ga288b8b3da0892bd651fce07b3bbd3a56)** 函数读取一张图像，图片应该在工作目录中，或者应该提供完整的图像路径。

第二个参数是一个 flag，指定了应该读取图像的方式

- **[cv.IMREAD_COLOR](https://docs.opencv.org/4.0.0/d4/da8/group__imgcodecs.html#gga61d9b0126a3e57d9277ac48327799c80af660544735200cbe942eea09232eb822)**：加载彩色图像，任何图像的透明度都会被忽略，它是默认标志
- **[cv.IMREAD_GRAYSCALE](https://docs.opencv.org/4.0.0/d4/da8/group__imgcodecs.html#gga61d9b0126a3e57d9277ac48327799c80ae29981cfc153d3b0cef5c0daeedd2125)**：以灰度模式加载图像
- **[cv.IMREAD_UNCHANGED](https://docs.opencv.org/4.0.0/d4/da8/group__imgcodecs.html#gga61d9b0126a3e57d9277ac48327799c80aeddd67043ed0df14f9d9a4e66d2b0708)**：加载图像，包括 alpha 通道

Note

- 你可以简单地分别传递整数 1、0 或-1，而不是这三个 flag。

``` py
img=cv2.imread("person.jpg",1)
```

注意：即使图像路径错误，它也不会抛出任何错误，但是`打印 img`会给你`None`



cv2.imshow()

在窗口中显示图像，窗口自动适应图像的大小。

第一个参数是窗口名，它是一个字符串，第二个参数就是我们的图像。你可以根据需要创建任意数量的窗口，但是窗口名字要不同。

```python
cv.imshow('image', img)
```

cv.destroyAllWindows()

简单的销毁我们创建的所有窗口

cv.destroyWindow()

销毁任意指定窗口，参数是确切的窗口名。



cv.namedWindow()

有一种特殊情况，你可以先创建一个窗口然后加载图像到该窗口。在这种情况下，你能指定窗口是否可调整大小。它是由这个函数完成的 **[cv.namedWindow()](https://docs.opencv.org/4.0.0/d7/dfc/group__highgui.html#ga5afdf8410934fd099df85c75b2e0888b)**。默认情况下，flag 是 **[cv.WINDOW_AUTOSIZE](https://docs.opencv.org/4.0.0/d7/dfc/group__highgui.html#ggabf7d2c5625bc59ac130287f925557ac3acf621ace7a54954cbac01df27e47228f)**，此时图片不会随窗口的大小而变化。但如果你指定了 flag 为 **[cv.WINDOW_NORMAL](https://docs.opencv.org/4.0.0/d7/dfc/group__highgui.html#ggabf7d2c5625bc59ac130287f925557ac3a29e45c5af696f73ce5e153601e5ca0f1)**，你能调整窗口大小。当图像尺寸太大，在窗口中添加跟踪条是很有用的。

``` python
import cv2
img=cv2.imread("person.jpg",1)
cv2.namedWindow("img")
cv2.imshow("img",img)
cv2.waitKey(0)
```

cv.imwrite()

保存图像，第一个参数是文件名，第二个参数是你要保存的图像。

``` python
cv.imwrite('messigray.png',img)
```

cv.waitKey()

是一个键盘绑定函数，它的参数是以毫秒为单位的时间。该函数为任意键盘事件等待指定毫秒。如果你在这段时间内按下任意键，程序将继续。如果传的是 0，它会一直等待键盘按下。它也可以设置检测特定的击键



## 视频

cv.VideoCapture()

去获取一个视频，你需要创建一个**VideoCapture**对象。它的参数可以是设备索引或者一个视频文件名。设备索引仅仅是摄像机编号。通常会连接一台摄像机(as in my case)。所以我只传了 0(或者-1)。你可以通过传 1 来选择第二个摄像机，以此类推。之后，你能逐帧捕获。但是最后，不要忘记释放这个 Capture 对象

cv.VideoWriter()

依据OpenCV3.4.1版本文档中对VideoWriter()函数的描述，使用方法如下：

``` c
<VideoWriter object> = VideoWriter(const String &filename, int fourcc, double fps, Size frameSize, bool isColor=true)
```

> VideoWriter()的参数有filename, fourcc, fps, frameSize, isColor。下面我们就来逐个的解释：
>
> filename：需要生成的视频的名字
>
> fourcc：用于压缩框架的解码器的4位编码(four code of codec)，你在这个链接里可以查找到可用的4位码（http://www.fourcc.org/codecs.php）
>
> fps：每秒的视频帧数(framrate persecond)
>
> frameSize：视频画面的尺寸（这里需要与用于合成视频的图片尺寸一致）
>
> isColor：如果该位值为Ture，解码器会进行颜色框架的解码，否则会使用灰度进行颜色架构（该功能仅支持在Windows系统中使用）

## 绘图

> - img：你想画的图片
> - color：形状的颜色，如 BGR，它是一个元组，例如：蓝色(255,0,0)。对于灰度图，只需传一个标量值。
> - thickness： 线或圆等的厚度。如果传 **-1** 就是像圆的闭合图形，它将填充形状。_ 默认 thickness = 1_
> - lineType：线条类型，如 8 连接，抗锯齿线等。默认情况下，它是 8 连接。**[cv.LINE_AA](https://docs.opencv.org/4.0.0/d6/d6e/group__imgproc__draw.html#ggaf076ef45de481ac96e0ab3dc2c29a777a85fdabe5335c9e6656563dfd7c94fb4f)** 画出抗锯齿线，非常好看的曲线。

cv.polylines()

 能画很多线条。只需创建你想绘制所有线条的列表，然后将其传给这个函数。所有线条都将单独绘制。绘制一组线条比调用 **[cv.line()](https://docs.opencv.org/4.0.0/d6/d6e/group__imgproc__draw.html#ga7078a9fae8c7e7d13d24dac2520ae4a2)** 好很多，快很多。

``` c
cv2.rectangle(image, start_point, end_point, color, thickness)
```

**参数：**

> **image:**它是要在其上绘制矩形的图像
> **start_point：**它是矩形的起始坐标。坐标表示为两个值的元组，即(X坐标值，Y坐标值)
> **end_point：**它是矩形的结束坐标。坐标表示为两个值的元组，即(**X**坐标值**ÿ**坐标值)
> **color:**它是要绘制的矩形的边界线的颜色。对于**BGR**，我们通过一个元组。例如：(255，0，0)为蓝色
> **thickness:**它是矩形边框线的粗细**像素**。厚度**-1像素**将以指定的颜色填充矩形形状

**返回值：**它返回一个图像。

``` c
cv2.putText(image, text, (5,50 ), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0, 0, 255), 2)
```

位置参数说明：

- 图片
- 要添加的文字
- 文字添加到图片上的位置
- 字体的类型
- 字体大小
- 字体颜色
- 字体粗细

```  c
# 图片 添加的文字 位置 字体 字体大小 字体颜色 字体粗细
cv2.putText(result, fps, (5,50 ), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0, 0, 255), 2)
```

## 鼠标作为画笔

cv.setMouseCallback()

首先我们创建一个鼠标回调函数，该函数在鼠标事件发生时执行。鼠标事件可以是与鼠标有关的任何内容，比如鼠标左键按下，左键弹起，左键双击等等。所有鼠标事件都给我们提供坐标 (x,y)。通过这个事件和位置，我们能做任何我们喜欢的事情。要列出所有可用事件

创建鼠标回调函数是有特定的格式，在任何地方都一样。它仅仅是函数的功能不同。因此我们的鼠标回调函数是做一件事，就是我们双击的地方画圆

## 图像基本操作

**警告**

Numpy 是一个用于快速阵列计算的优化库。因此，简单地访问每个像素值并对其进行修改将非常缓慢，并不鼓励这样做。

> **注意** 上述方法通常用于选择数组的某个区域，比如前 5 行和后 3 列。对于单个像素的访问，可以选择使用 Numpy 数组方法中的 array.item()和 array.itemset()，注意它们的返回值是一个标量。如果需要访问所有的 G、R、B 的值，则需要分别为所有的调用 array.item()

### 访问图像属性

图像属性包括行数，列数和通道数，图像数据类型，像素数等。

与一般的numpy.array一样，可以通过 img.shape 访问图像的形状。它返回一组由图像的行、列和通道组成的元组（如果图象是彩色的）：

```python
>>>print(img.shape)
(128,128,3)复制ErrorOK!
```

> **注意** 如果图像是灰度图像，则返回的元组仅包含行数和列数，因此它是检查加载的图像是灰度图还是彩色图的一种很好的方法。

通过 img.size 访问图像的总像素数：

```python
>>>print(img.size)
562248复制ErrorOK!
```

图像数据类型可以由 img.dtype 获得：

```python
>>>print(img.dtype)
UINT8复制ErrorOK!
```

> **注意** img.dtype 在调试时非常重要，因为 OpenCV—Python 代码中的大量错误是由无效的数据类型引起的。

假设您要将所有红色像素设置为零，则无需先拆分通道。Numpy 索引更快：

```python
>>> img[:,:,2] = 0
```

> cv.spilt()是一项代价高昂的操作（就时间而言）。所以只有在你需要时才这样做，否则就使用 Numpy 索引

 cv.copyMakeBorder()

如果要在图像周围创建边框，比如相框，可以使用 cv.copyMakeBorder()。但它有更多卷积运算，零填充等应用。该函数采用以下参数：

- src-输入的图像

- top,bottom,left,right-上下左右四个方向上的边界拓宽的值

- borderType-定义要添加的边框类型的标志。它可以是以下类型：

  > - [cv.BORDER_CONSTANT](https://docs.opencv.org/4.0.0/d2/de8/group__core__array.html#gga209f2f4869e304c82d07739337eae7c5aed2e4346047e265c8c5a6d0276dcd838)- 添加一个恒定的彩色边框。该值应作为下一个参数value给出。
  > - [cv.BORDER_REFLECT](https://docs.opencv.org/4.0.0/d2/de8/group__core__array.html#gga209f2f4869e304c82d07739337eae7c5a815c8a89b7cb206dcba14d11b7560f4b)-边框将是边框元素的镜像反射，如下所示：fedcba|abcdefgh|hgfedcb
  > - [cv.BORDER_REFLECT_101](https://docs.opencv.org/4.0.0/d2/de8/group__core__array.html#gga209f2f4869e304c82d07739337eae7c5ab3c5a6143d8120b95005fa7105a10bb4)或者[ cv.BORDER_DEFAULT](https://docs.opencv.org/4.0.0/d2/de8/group__core__array.html#gga209f2f4869e304c82d07739337eae7c5afe14c13a4ea8b8e3b3ef399013dbae01)-与上面相同，但略有改动，如下所示： gfedcb | abcdefgh | gfedcba
  > - [cv.BORDER_REPLICATE ](https://docs.opencv.org/4.0.0/d2/de8/group__core__array.html#gga209f2f4869e304c82d07739337eae7c5aa1de4cff95e3377d6d0cbe7569bd4e9f)-最后一个元素被复制，如下所示： aaaaaa | abcdefgh | hhhhhhh
  > - [cv.BORDER_WRAP](https://docs.opencv.org/4.0.0/d2/de8/group__core__array.html#gga209f2f4869e304c82d07739337eae7c5a697c1b011884a7c2bdc0e5caf7955661)-不好解释，它看起来像这样： cdefgh | abcdefgh | abcdefg

- value- 如果边框类型为[cv.BORDER_CONSTANT](https://docs.opencv.org/4.0.0/d2/de8/group__core__array.html#gga209f2f4869e304c82d07739337eae7c5aed2e4346047e265c8c5a6d0276dcd838)，则这个值即为要设置的边框颜色

## 图像混合

