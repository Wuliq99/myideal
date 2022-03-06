OS

``` python
os.rename(原文件名，新的文件名)	——文件重命名
os.remove(文件名)	——删除文件
	如果不说明路径，则在源代码所在文件夹下寻找，寻找不到会报错。
	若想删除指定文件夹下的文件，文件名则需要具体路径，例如 os.remove(r"D:\test_1\文件名"),r防止斜杠发生转义
os.mkdir(文件夹名)	——创建文件夹
os.rmdir(文件夹名)	——删除文件夹
os.getcwd()	——获取当前目录
os.chdir(目录)	——切换目录
os.listdir(目录)	——获取当前文件夹下所有的文件或者文件夹，返回一个列表
os.name		——windows是nt，linux是posix
```



## os.path.join()

用于拼接文件路径，可以传入多个路径

**如果不存在以 / 开始的参数，则函数会自动加上**

```python
>>> import os
>>> print(os.path.join('path','abc','yyy'))

path\abc\yyy
```

 **存在以 / 开始的参数，从最后一个以”/”开头的参数开始拼接，之前的参数全部丢弃。**

``` python
>>> print('1',os.path.join('aaa','/bbb','ccc.txt'))
1 /bbb\ccc.txt
 
>>> print('1',os.path.join('/aaa','/bbb','ccc.txt'))
1 /bbb\ccc.txt
 
>>> print('1',os.path.join('/aaa','/bbb','/ccc.txt'))
1 /ccc.txt
 
>>> print('1',os.path.join('/aaa','bbb','ccc.txt'))
1 /aaa\bbb\ccc.txt
 
>>> print('1',os.path.join('/aaa','bbb','/ccc.txt'))
1 /ccc.txt
```

**同时存在以 ./ 与 / 开始的参数，以  /  为主，从最后一个  /  开头的参数开始拼接，之前的参数全部丢弃。**

``` python
>>> print('2',os.path.join('/aaa','./bbb','ccc.txt'))
2 /aaa\./bbb\ccc.txt
 
>>> print('2',os.path.join('aaa','./bbb','/ccc.txt'))
2 /ccc.txt
```

**只存在以  ./  开始的参数,会  ./  开头的参数的上一个参数开始拼接。**

```  python
>>> print(os.path.join('aaa','./bbb','ccc.txt'))
aaa\./bbb\ccc.txt
```

**注意**

``` python
>>> path='C:/yyy/yyy_data/'
>>> print(os.path.join(path,'/abc'))
C:/abc
>>> print(os.path.join(path,'abc'))
C:/yyy/yyy_data/abc
```



#### os.path.splitext(path)

将对应路径的文件名和后缀名分割

``` python
>>> #定义参数内容
... import os
>>> path1='E:\test\6.txt'#文件路径
>>> path2='E:\test'#目录
>>>
>>> #用splitext()方法切割
... split_path1=os.path.splitext(path1)
>>> split_path2=os.path.splitext(path2)
>>>
>>> #打印结果
... print(split_path1)#正常切割
('E:\test\x06', '.txt')
>>> print(split_path2)#目录切割后异常
('E:\test', '')
```



#### **os.walk()**

##### **说明**

os.walk(top,topdown=True,onerror=None,followlinks=False)

### 参数

- **top** -- 是你所要遍历的目录的地址, 返回的是一个三元组(root,dirs,files)。
  - root 所指的是当前正在遍历的这个文件夹的本身的地址
  - dirs 是一个 list ，内容是该文件夹中所有的目录的名字(不包括子目录)
  - files 同样是 list , 内容是该文件夹中所有的文件(不包括子目录)
- **topdown** --可选，为 True，则优先遍历 top 目录，否则优先遍历 top 的子目录(默认为开启)。如果 topdown 参数为 True，walk 会遍历top文件夹，与top 文件夹中每一个子目录。
- **onerror** -- 可选，需要一个 callable 对象，当 walk 需要异常时，会调用。
- **followlinks** -- 可选，如果为 True，则会遍历目录下的快捷方式(linux 下是软连接 symbolic link )实际所指的目录(默认关闭)，如果为 False，则优先遍历 top 的子目录。

### 返回值

返回生成器。

 简单例子：

``` python
import os

path='E:\Model\\tttt'

with open('true.txt','w',encoding='utf-8') as fp:
    for root, dirs, files in os.walk(path, topdown=True):

        fp.writelines(f"当前目录：{root}\n")
        print(u"当前目录：", root)  # 打印当前绝对路径

        for name in files:
            fp.writelines(f"文件名：{name}\n")
            print(u"文件名：",name)  # 打印文件绝对路径

        for dir in dirs:
            fp.writelines(f"目录名：{dir}\n")
            print(u"目录名：", dir)  # 打印目录绝对路径

        fp.writelines('\n')
        fp.writelines('-'*30)
        fp.writelines('\n')
```



## os.path.isfile(path)方法

判断是否为文件，path为要判断的路径，必须为**绝对路径**

```
>>> import os  
>>> os.path.isfile('E:\\book\\temp') 
```

## os.path.isdir(path)方法

判断是否为目录，path为要判断的路径，必须为**绝对路径**

## os.popen()

该方法会打开一个连接到命令行的管道，该管道的读写性依赖于打开模式。
os.popen(command[, mode[, bufsize]])
mode（打开模式）和bufsize不是必须要提供的。如果为打开模式为提供，那么默认为"r",也就是只读模式（read only）

```python
import os
fd = "a.txt"
 
# popen() 和 open() 相似
file = open(fd, 'w')
file.write("Hello")
file.close()
file = open(fd, 'r')
text = file.read()
print(text)
 
# popen() 提供了直接访问文件的管道
file = os.popen(fd, 'w')
file.write("Hello")
# 其他的一些操作
# 关闭文件
file.close()
```

## os.close()

如果一个文件是使用open()打开的，那么只能使用close()关闭。但是如果一个文件是通过os.popen()的，那么可以使用close()或os.close()方法。如果我们试图用os.close()去关闭一个open()打开的文件，那么会抛出错误：

```
import os
fd = "a.txt"
file = open(fd, 'r') #使用open打开文件
text = file.read()
print(text)
os.close(file) #使用os.close()关闭文件
```

输出：

```
Traceback (most recent call last):
  File "/home/user/test/a.py", line 6, in
    os.close(file)
TypeError: an integer is required (got type _io.TextIOWrapper)
```
