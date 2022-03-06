## 前言

对于任何一个python文件来说，当python解释器运行一个py文件，会自动将一些内容加载到内置的属性中；一个模块我们可以看做是一个比类更大的对象。

## 查看模块的内置属性

我们先创建一个典型的py文件

```python
# test.py
# -*- coding: utf-8 -*-
"""
some doc
"""
import os
var1 = None
class Person(object):
    pass

if __name__ == "__main__":
    print(dir()) # ['Person', '__annotations__', '__builtins__', '__cached__', '__doc__', '__file__', '__loader__', '__name__', '__package__', '__spec__', 'os', 'var1']
```

通过dir()方法我们可以获取到该模块的所有的显式或隐式的属性或方法；可看到隐式的属性有__annotations__,__builtins__,__cached__,__annotations__,__doc__,__file__,__loader__,__name__;

我们打印一下每个魔法属性：

```python
print(__name__) # __main__
print(__annotations__) # {}
print(__builtins__) # <module 'builtins' (built-in)>
print(__cached__) # None
print(__doc__) # some doc
print(__file__) # .../test.py
print(__loader__) # <_frozen_importlib_external.SourceFileLoader object at 0x000002398E831F28>
print(__package__) # None
print(__spec__) # None

# 其中__name__、__doc__、__file__、__package__是可以直接使用的，其它的内置属性一般不允许直接使用。
```

## 内置魔法属性

- _*name*_

该属性代表当前模块的名字，每个py文件默认的属性，如果当前模块是主程序，值为“__main__”，如果不是主程序，值为模块名。这个属性经常用来区分主程序和作为被导入模块的程序。

- _*builtins*_

该属性代表内置模块builtins，即所有的内建函数、内置类型、内置异常等；在python执行一个py文件时，会将内置模块赋值给这个属性；如果不是主程序，那么这个属性是一个builtins模块所有方法的字典。

- \_*doc*_

模块的说明文档，py文件初始化时，将文件开始的说明字符串赋值给这个属性。

- \_*file*_

该属性代表文件的绝对路径，任何一个模块使用这个属性就可获得本模块的绝对路径；**但是该属性只在windows环境下可用，在linux环境下不可用。**

- \_*cached*_

缓存文件，如果是主程序，那么该属性为None，其他模块的该属性指向该模块的pyc字节文件，这样在py文件不发生修改的情况下可以减少编译的时间，更快地加载上下文环境。

- \_*annotations*_

该属性对于模块文件来说，没有开放给用户使用；但对于函数来说，这个方法用来记录参数的类型和返回值。

```python
def get_sum(x,y):
    return x + y
print(get_sum.__annotations__) # {}

def get_sum(x, y: int) -> int:
    return x + y
print(get_sum.__annotations__) # {'y': <class 'int'>, 'return': <class 'int'>}
```

函数的参数和返回值如果在定义的时候指定了类型，那么它们就会以键值对的形式记录到函数的__annotations__属性中，但对于匿名函数来说，这个属性是不存在的。

- \_*loader*_

该属性py3.3之前没有，引用了本模块的加载器对象，即该模块的上下文是由这个加载器加载到内存中的。

- \_*package*_

该属性是一个文件是否是包的标志，在主程序中该属性的值永远是None，不要使用它；当一个包被导入到主程序中，该包的__package__属性为包的名字。

```python
# test
    --__init__.py

# main.py
import test

print(test.__package__) # test
```

- _*spec*_

该属性记录一个模块的详细信息，是一个ModuleSpec对象，

## 其他魔法属性

- _*author*_

该属性用来定义模块的作者信息，可以是字符串，也可以是列表、字典等数据结构。

```python
# test.py

__author__ = {'auth':'tianyuzhiyou';'bg':'https://www.cnblogs.com/cwp-bg/'}
```

- _*all*_

该属性不是模块默认的，需要手动定义，它的功能有二：

1. 记录一个模块有哪些重要的、对外开发的类、方法或变量等，或记录一个包哪些对外开放的模块；
2. 限制导入，当使用“from xxx import *”形式导入时，实际导入的只有__all__属性中的同名的对象而不是所有，但对于“from xxx import xxx”指定了具体的名字则all属性被忽略。

## 魔法方法

- _*import*_

该魔法方法是import触发，即import os 相当于os = __import__('os')，也可以直接使用，主要用于模块延迟加载，或重载模块。

- 参数：

```
name:模块的名字；
global:包含全局变量的字典，采用默认值 global()
local:包含局部变量的字典，采用默认值 local()
fromlist:被导入的子模块的名称
level:指定使用绝对导入还是相对导入，0表示只执行绝对导入。
```

- 实例

```python
# 设有文件目录
testx
    --__init__.py
    --name.py
    --test
        --__init__.py
        --name.py

t = __import__('testx',fromlist=['name','test2']) # 导入testx包以及包内的name、test2模块
print(t.name) # t变量代表testx包，如果name不再fromlist中则不可用

t = __import__('testx.test2', fromlist=['name']) # 导入testx包的子包
print(t.name) # 代表testx.test2.name
```

**__import__函数返回的是一个变量，代表一个模块，所有后续方法的调用都要在这个变量的基础上。**

## 总结

1. 对于众多的模块属性，python最常用的是__name__,__doc__,__author__,__all__.
2. python在执行import语句时，调用__import__方法，同时也做了对被导入模块的一些初始化工作，如：将被导入模块的名字赋值给被导入模块__name__，将被导入模块的绝对路径赋值给被导入模块__file__，将builtins模块的globals()赋值给被导入模块__builtins__,将被导入模块的说明赋值给被导入模块的_*doc_*,将被导入模块的编译字节文件路径赋值给被导入模块__cached__,创建一个ModuleSpec对象赋值给被导入模块的__spec__,如果被导入的是包，将包的名字赋值__package__属性.

参考

[python进阶之py文件内置属性 - 倥偬时光 - 博客园 (cnblogs.com)](https://www.cnblogs.com/cwp-bg/p/9856339.html)