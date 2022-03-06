## 概述

Python提供fileinput模块对一个或者多个文件中的内容进行迭代、遍历、格式化输出、查找替换操作功能

## 原因

​		我们可以使用 open() 和 read()（或者 readline()、readlines() ）组合，来读取单个文件中的数据。但在某些场景中，可能需要读取多个文件的数据，这种情况下，再使用这个组合，显然就不合适了。庆幸的是，Python 提供了 fileinput 模块，通过该模块中的 input() 函数，我们能同时打开指定的多个文件，还可以逐个读取这些文件中的内容。

## 详解

fileinput模块可以对一个或多个文件中的内容进行迭代、遍历等操作。该模块的input()函数有点类似文件readlines()方法，区别在于前者是一个迭代对象，需要用for循环迭代，后者是一次性读取所有行。

### 【典型用法】

```python
import fileinput
for line in fileinput.input():
    print(line)
```

### 【基本格式】

fileinput.input([files[, inplace[, backup[, bufsize[, mode[, openhook]]]]]])

### 【默认格式】

fileinput.input (files=None, inplace=False, backup='', bufsize=0, mode='r', openhook=None)

```python
files:         #文件的路径列表，默认是stdin方式，多文件[``'1.txt'``,``'2.txt'``,...]
inplace:        #用于指定是否将标准输出的结果写回到文件，此参数默认值为 False；
backup:         #备份文件的扩展名，只指定扩展名，如.bak。如果该文件的备份文件已存在，则会自动覆盖。
bufsize:        #缓冲区大小，默认为``0``，如果文件很大，可以修改此参数，一般默认即可
mode:          #打开文件的格式，默认为 r（只读模式）；
openhook:        #该钩子用于控制打开的所有文件，比如说编码方式等;
```

### 【常用函数】

| 函数名                  | 功能描述                                        |
| ----------------------- | ----------------------------------------------- |
| fileinput.input()       | 返回能够用于for循环遍历的对象                   |
| fileinput.filename()    | 返回当前正在读取的文件名称。                    |
| fileinput.fileno()      | 返回当前正在读取文件的文件描述符。              |
| fileinput.lineno()      | 返回当前已经读取的行的数量（或者序号）          |
| fileinput.filelineno()  | 返回当前正在读取的内容位于当前文件中的行号。    |
| fileinput.isfirstline() | 判断当前读取的内容在当前文件中是否位于第 1 行。 |
| fileinput.isstdin()     | 判断最后一行是否从stdin中读取                   |
| fileinput.nextfile()    | 关闭当前正在读取的文件，并开始读取下一个文件。  |
| fileinput.close()       | 关闭 FileInput 对象。                           |

## 示例

#### 例子1: 利用fileinput读取一个文件所有行

```python
import fileinput
for line in fileinput.input('data.txt'):
    print(line)
#输出结果
Python
Java 
C/C++
Shell
```

命令行方式:

```python
#test.py
import fileinput
for line in fileinput.input():
    print(fileinput.filename(),'|','Line Number:',fileinput.lineno(),'|: ',line)
 
c:>python test.py data.txt
data.txt | Line Number: 1 |:  Python
data.txt | Line Number: 2 |:  Java
data.txt | Line Number: 3 |:  C/C++
data.txt | Line Number: 4 |:  Shell
```

#### 例子2: 利用fileinput对多文件操作，并原地修改内容

```python
#test.py
c:Python27>type 1.txt
first
second
 
c:Python27>type 2.txt
third
fourth
#---样本文件---
import fileinput
 
def process(line):
    return line.rstrip() + ' line'
 
for line in fileinput.input(['1.txt','2.txt'],inplace=True):
    print process(line)
 
#---结果输出---
c:Python27>type 1.txt
first line
second line
 
c:Python27>type 2.txt
third line
fourth line
```

命令行方式:

```python
#test.py
import fileinput
 
def process(line):
    return line.rstrip() + ' line'
 
for line in fileinput.input(inplace = True):
    print process(line)
 
#执行命令
c:Python27>python test.py 1.txt 2.txt
```

#### 例子3: 利用fileinput实现文件内容替换，并将原文件作备份

```python
#样本文件:
#data.txt
Python
Java
C/C++
Shell
 
#FileName: test.py
import fileinput
 
for line in fileinput.input('data.txt',backup='.bak',inplace=True):
    print(line.rstrip().replace('Python','Perl'))
    line.replace('Python','Perl'),
     
#最后结果:
#data.txt
Python
Java
C/C++
Shell
#并生成:
#data.txt.bak文件
```

#### 例子5: 利用fileinput对文件简单处理

```python
#test.py
import sys
import fileinput
 
for line in fileinput.input(r'C:Python27info.txt'):
    sys.stdout.write('=> ')
    sys.stdout.write(line)
```

#### 例子06: 利用fileinput批处理文件

```python
#---测试文件: test.txt test1.txt test2.txt test3.txt---
#---脚本文件: test.py---
import fileinput
import glob
 
for line in fileinput.input(glob.glob(test*.txt)):
    if fileinput.isfirstline():
        print('-'*20, 'Reading %s...' % fileinput.filename(), '-'*20)
    print(str(fileinput.lineno()) + ': ' + line.upper())
     
     
#---输出结果:
-------------------- Reading test.txt... --------------------
1: AAAAA
2: BBBBB
3: CCCCC
4: DDDDD
5: FFFFF
-------------------- Reading test1.txt... --------------------
6: FIRST LINE
7: SECOND LINE
-------------------- Reading test2.txt... --------------------
8: THIRD LINE
9: FOURTH LINE
-------------------- Reading test3.txt... --------------------
10: THIS IS LINE 1
11: THIS IS LINE 2
12: THIS IS LINE 3
13: THIS IS LINE 4
```



#### 例子07: 利用fileinput及re做日志分析: 提取所有含日期的行

```python
#--样本文件--
aaa
1970-01-01 13:45:30  Error: **** Due to System Disk spacke not enough...
bbb
1970-01-02 10:20:30  Error: **** Due to System Out of Memory...
ccc
 
#---测试脚本---
import re
import fileinput
import sys
 
pattern = 'd{4}-d{2}-d{2} d{2}:d{2}:d{2}'	#模式
 
for line in fileinput.input('error.log',backup='.bak',inplace=True):
    if re.search(pattern,line):
        sys.stdout.write(=> )
        sys.stdout.write(line)
 
#---测试结果---
=> 1970-01-01 13:45:30  Error: **** Due to System Disk spacke not enough...
=> 1970-01-02 10:20:30  Error: **** Due to System Out of Memory...
```

#### 例子08: 利用fileinput及re做分析: 提取符合条件的电话号码

```python
#---样本文件: phone.txt---
010-110-12345
800-333-1234
010-99999999
05718888888
021-88888888
 
#---测试脚本: test.py---
import re
import fileinput
 
pattern = '[010|021]-d{8}'  #提取区号为010或021电话号码，格式:010-12345678
 
for line in fileinput.input('phone.txt'):
    if re.search(pattern,line):
        print('=' * 50)
        print('Filename:'+ fileinput.filename()+' | Line Number:'+str(fileinput.lineno())+' | '+line)
 
#---输出结果:---
==================================================
Filename:phone.txt | Line Number:3 | 010-99999999
==================================================
Filename:phone.txt | Line Number:5 | 021-88888888 
```

#### 例子09:利用fileinput实现类似于grep的功能

```python
import sys
import re
import fileinput

pattern= re.compile(sys.argv[1])	# 生成正则对象
for line in fileinput.input(sys.argv[2]):
    if pattern.match(line):
    print(fileinput.filename(), fileinput.filelineno(), line)
```