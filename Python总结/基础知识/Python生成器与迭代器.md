# Python生成器与迭代器

## 前言

首先，来让我们弄清楚可迭代对象

### 可迭代对象

> 在python中，可迭代对象并不是指某种具体的数据类型，它是指存储了元素的一个容器对象
>
> 也就是说，如果容器里面没有存储数据，那它就不是可迭代对象，并不是所有的容器都是可迭代对象，容器包含但并不仅限于可迭代对象

**注意**

- 很多容器都是可迭代对象（容器包含了可迭代对象）
- 一个可迭代对象是不能独立的进行迭代的，迭代是通过for来完成的，凡是可迭代对象都可以直接使用for循环进行访问

**例子**

for循环的执行过程

```c
1.使用 __iter__() 返回1个迭代器

2.使用 __next__() 获取迭代器中的每一个元素。
```

**代码实现**

```python
l = [1,2,3,4]
# for i in l:
#     print(i)
ite =l.__iter__() #接收一下ietr()干了什么

print(ite)  #打印，不可超过总的迭代次数，否则会报错

print(ite.__next__())    #for循环干第2件事情的时候做的第1步
print(ite.__next__())    #for循环干第2件事情的时候做的第2步
print(ite.__next__())    #for循环干第2件事情的时候做的第3步
print(ite.__next__())    #for循环干第2件事情的时候做的第4步
```

**分析**

> 可以看出来，如果我们去掉哪行打印ite的代码，执行效果就是跟for循环输出列表里面的每一个元素是一样的，for循环里面限定了范围是4次，实际上就执行了1次__iter__()和4次__next__()，也就是说for循环访问迭代对象的本质就是通过这么去实现的。
>
> 而且，for循环本质上干的那两件事情，缺一不可，也就是说如果没有__iter__()先返回了迭代器，__next()__也无法获取到元素，恰恰说明了前面说要注意的两点中的第2点：一个可迭代对象是不能独立的进行迭代的。
>
> 有两个内置函数跟它们原理是一样的，本质相同，一般要用的话用内置函数要方便一些，起码不用写那么多下划线

````basic
内置函数 iter() 的本质是 __inter__() ，也是返回一个迭代器。

内置函数 next（） 的本质是 __next__()，也是有了迭代器之后获取元素。
````

## 生成器

引言

> 通过列表生成式，我们可以直接创建一个列表。但是，受到内存限制，列表容量肯定是有限的。而且，创建一个包含100万个元素的列表，不仅占用很大的存储空间，如果我们仅仅需要访问前面几个元素，那后面绝大多数元素占用的空间都白白浪费了。
>
> 所以，如果列表元素可以按照某种算法推算出来，那我们是否可以在循环的过程中不断推算出后续的元素呢？这样就不必创建完整的list，从而节省大量的空间。在Python中，这种一边循环一边计算的机制，称为生成器：generator。

在 Python 中，使用了 yield 的函数被称为生成器（generator）。跟普通函数不同的是，生成器是一个返回迭代器的函数，只能用于迭代操作，更简单点理解生成器就是一个迭代器。

在调用生成器运行的过程中，每次遇到 yield 时函数会暂停并保存当前所有的运行信息，返回 yield 的值, 并在下一次执行 next() 方法时从当前位置继续运行。调用一个生成器函数，返回的是一个迭代器对象。



要创建一个generator，有很多种方法。第一种方法很简单，只要把一个列表生成式的`[]`改成`()`，就创建了一个generator：

```python
>>> L = [x * x for x in range(10)]
>>> L
[0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
>>> g = (x * x for x in range(10))
>>> g
<generator object <genexpr> at 0x1022ef630>
```

> 注：要访问 g 中元素，可使用 next() 方法



这就是**定义generator的另一种方法**。如果一个函数定义中包含`yield`关键字，那么这个函数就不再是一个普通函数，而是一个

generator：

```python
>>> f = fib(6)
>>> f
<generator object fib at 0x104feaaa0>
```

这里，最难理解的就是generator和函数的执行流程不一样。函数是顺序执行，遇到`return`语句或者最后一行函数语句就返回。而变成

generator的函数，在每次调用`next()`的时候执行，遇到`yield`语句返回，**再次执行时从上次返回的`yield`语句处继续执行**。



但是用`for`循环调用generator时，发现拿不到generator的`return`语句的返回值。如果想要拿到返回值，必须捕获`StopIteration`错误，返回值包含在`StopIteration`的`value`中：

```python
>>> g = fib(6)
>>> while True:
...     try:
...         x = next(g)
...         print('g:', x)
...     except StopIteration as e:
...         print('Generator return value:', e.value)
...         break
...
g: 1
g: 1
g: 2
g: 3
g: 5
g: 8
Generator return value: done
```

### 小结

generator是非常强大的工具，在Python中，可以简单地把列表生成式改成generator，也可以通过函数实现复杂逻辑的generator。

要理解generator的工作原理，它是在`for`循环的过程中不断计算出下一个元素，并在适当的条件结束`for`循环。对于函数改成的generator来说，遇到`return`语句或者执行到函数体最后一行语句，就是结束generator的指令，`for`循环随之结束。

请注意区分普通函数和generator函数，普通函数调用直接返回结果：

```python
>>> r = abs(6)
>>> r
6
```

generator函数的“调用”实际返回一个generator对象：

> def fib(max):
> n, a, b = 0, 0, 1
> while n < max:
> yield b
> a, b = b, a + b
> n = n + 1
> return 'done'

```python
>>> g = fib(6)
>>> g
<generator object fib at 0x1022ef948>
```

------

## 迭代器

> 我们已经知道，可以直接作用于`for`循环的数据类型有以下几种：
>
> 一类是集合数据类型，如`list`、`tuple`、`dict`、`set`、`str`等；
>
> 一类是`generator`，包括生成器和带`yield`的generator function。
>
> 这些可以直接作用于`for`循环的对象统称为可迭代对象：`Iterable`。
>
> 你可能会问，为什么`list`、`dict`、`str`等数据类型不是`Iterator`？

这是因为Python的`Iterator`对象表示的是一个数据流，Iterator对象可以被`next()`函数调用并不断返回下一个数据，直到没有数据时抛出`StopIteration`错误。可以把这个数据流看做是一个有序序列，但我们却不能提前知道序列的长度，只能不断通过`next()`函数实现按需计算下一个数据，所以`Iterator`的计算是惰性的，只有在需要返回下一个数据时它才会计算。

`Iterator`甚至可以表示一个无限大的数据流，例如全体自然数。而使用list是永远不可能存储全体自然数的。

### 小结

凡是可作用于`for`循环的对象都是`Iterable`类型；

凡是可作用于`next()`函数的对象都是`Iterator`类型，它们表示一个惰性计算的序列；

集合数据类型如`list`、`dict`、`str`等是`Iterable`但不是`Iterator`，不过可以通过`iter()`函数获得一个`Iterator`对象。

Python的`for`循环本质上就是通过不断调用`next()`函数实现的，例如：

```python
for x in [1, 2, 3, 4, 5]:
    pass
```

实际上完全等价于：

```python
# 首先获得Iterator对象:
it = iter([1, 2, 3, 4, 5])
# 循环:
while True:
    try:
        # 获得下一个值:
        x = next(it)
    except StopIteration:
        # 遇到StopIteration就退出循环
        break
```

## 总结

![在这里插入图片描述](https://img-blog.csdnimg.cn/2c3491d099cc406cb78a7338a4a492e8.jpg?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA5b2h6ZqF,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)

## reference

> [稳扎稳打学Python！_那些疯狂到以为自己可以改变世界的人-CSDN博客](https://sslljy.blog.csdn.net/article/details/120700554)

>https://www.liaoxuefeng.com/wiki/1016959663602400/1017323698112640