## 核心函数简介

### cv2.VideoWriter()

```c
VideoWriter(filename, fourcc, fps, frameSize[, isColor]) -> <VideoWriter object>
```

1. 第一个参数是要保存的文件的路径
2. fourcc 指定编码器
3. fps 要保存的视频的帧率
4. frameSize 要保存的文件的画面尺寸
5. isColor 指示是黑白画面还是彩色的画面，默认为彩色



### cv2.VideoWriter_fourcc()

```c
fourcc = cv2.VideoWriter_fourcc('M', 'P', '4', 'V')#VideoWriter_fourcc为视频编解码器
      #编码参数：
    # cv2.VideoWriter_fourcc('M', 'P', '4', 'V') MPEG-4编码 .mp4  要限制结果视频的大小，这是一个很好的选择。
    # cv2.VideoWriter_fourcc('X','2','6','4')   MPEG-4编码  .mp4  想限制结果视频的大小，这可能是最好的选择。
    # cv2.VideoWriter_fourcc('I', '4', '2', '0'),该参数是YUV编码类型，文件名后缀为.avi   广泛兼容，但会产生大文件
    # cv2.VideoWriter_fourcc('P', 'I', 'M', 'I'),该参数是MPEG-1编码类型，文件名后缀为.avi
    # cv2.VideoWriter_fourcc('X', 'V', 'I', 'D'),该参数是MPEG-4编码类型，文件名后缀为.avi  要限制结果视频的大小，这是一个很好的选择。
    # cv2.VideoWriter_fourcc('T', 'H', 'E', 'O'),该参数是Ogg Vorbis,文件名后缀为.ogv
    # cv2.VideoWriter_fourcc('F', 'L', 'V', '1'),该参数是Flash视频，文件名后缀为.flv

videoWriter = cv2.VideoWriter('video.mp4', fourcc, video_fps, (video_width, video_height))
```

## 程序

### 将视频转换为图片

```python
import cv2

video_path=r"D:\MOT20-01-raw.mp4"   #视频路径
out_path=r"E:\Images"               #图片保存路径


is_all_frame=True       #是否保存所有帧
sta_frame=1             #开始保存的帧
end_frame=1000          #最后的帧

time_interval=8         #保存帧的间隔

def saveimage(image,num):
    address=out_path+"\\"+str(num)+".jpg"    #设置路径
    print("save success")
    cv2.imwrite(address,image)      #开始保存


cap=cv2.VideoCapture(video_path)    #创建一个对象，用于读取视频
success,frame=cap.read()            #读取一帧

i=0
j=0

while success:
    i+=1
    if i%time_interval==0:
        if not is_all_frame:
            if sta_frame <=i <=end_frame:
                j += 1
                print("save frame",j)
                saveimage(frame,j)
            else:
                break
        else:
            j+=1
            print("save frame",j)
            saveimage(frame, j)
    success, frame = cap.read()

cap.release()       #读取完后释放资源
```

### 将图片转化为视频

```python
import cv2
import os
from PIL import Image   #   python用于图像处理的库


def PicToVideo(imgPath, videoPath):

    images = os.listdir(imgPath)    # 获取所有图片名称

    images.sort(key=lambda x: int(x[:-4]))  # 对图片进行排序

    fps = 25  # 帧率

    fourcc = cv2.VideoWriter_fourcc(*"MJPG")    # 设置视频的编码格式

    im = Image.open(imgPath + images[0])    # 获取图片信息

    videoWriter = cv2.VideoWriter(videoPath, fourcc, fps, im.size,isColor=True) #创建一个videoWriter对象，用于将图片保存为视频的一部分

    for im_name in range(len(images)):
        frame = cv2.imread(imgPath + images[im_name])
        videoWriter.write(frame)

    videoWriter.release()   # 释放


imgPath = "E:/Images/"          # 图片的路径
videoPath = "E:/videos/video.avi"       # 保存视频的路径及视频
PicToVideo(imgPath, videoPath)
```

## 注意

> 需要注意的是在 VideoWriter 中指定的尺寸要和 write() 中写进去的一样，不然视频会存储失败的
>
> 如果需要读取视频文件，那么就将 VideoCapture 指定文件路径
>



## 总结

> 无论是将视频分割为图片，还是将图片合成为视频，其原理都是相似的：即一张一张读取。