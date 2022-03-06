# C语言可变参数--借助stdarg.h

## 简介

**stdarg.h** 头文件定义了一个变量类型 **va_list** 和三个宏，这三个宏可用于在参数个数未知（即参数个数可变）时获取函数中的参数。

可变参数的函数通在参数列表的末尾是使用省略号(,...)定义的。



## 使用模板

```c

	int val=0;
	int i=0;

    va_list ap; /*定义一个va_list*/
	

    va_start(ap, num_args);/*开始,num_args为要计算的参数的个数*/ 
    for(i = 0; i < num_args; i++)
    {
        val += va_arg(ap, int);/*每次循环取一个*/ 
    }
    va_end(ap);/*结束，可以省略，但最好不要省，省略后结果未定义*/ 

```



## 各部分介绍

### va_start()

#### 描述

> C 库宏 **void va_start(va_list ap, last_arg)** 初始化 **ap** 变量，它与 **va_arg** 和 **va_end** 宏是一起使用的。**last_arg** 是要计算的参数的个数

**这个宏必须在使用 va_arg 和 va_end 之前被调用**

#### 声明

```
void va_start(va_list ap, last_arg);
```

#### 参数

- **ap** -- 这是一个 **va_list** 类型的对象，它用来存储通过 **va_arg** 获取额外参数时所必需的信息。
- **last_arg** -- 要计算的参数的个数。

#### 返回值

NA

### va_arg()

#### 描述

> C 库宏 **type va_arg(va_list ap, type)** 检索函数参数列表中类型为 **type** 的下一个参数。**它无法判断检索到的参数是否是传给函数的最后一个参数**

#### 声明

```
type va_arg(va_list ap, type)
```

#### 参数

- **ap** -- 这是一个 **va_list** 类型的对象，存储了有关额外参数和检索状态的信息。该对象应在第一次调用 va_arg 之前通过调用 va_start 进行初始化。
- **type** -- 这是一个类型名称。表示要计算的参数的类型

#### 返回值

该宏返回下一个额外的参数，是一个类型为 type 的表达式



### va_end()

#### 描述

> C 库宏 **void va_end(va_list ap)** 允许使用了 **va_start** 宏的带有可变参数的函数返回。如果在从函数返回之前没有调用 **va_end**，则结果为未定义。

#### 声明

下面是 va_end() 宏的声明。

```
void va_end(va_list ap)
```

#### 参数

- **ap** -- 这是之前由同一函数中的 va_start 初始化的 va_list 对象。

返回值

该宏不返回任何值。



## 实例

```c
#include<stdarg.h>
#include<stdio.h>

int sum(int, ...);

int main(void)
{
    printf("10、20 和 30 的和 = %d\n",  sum(3, 10, 20, 30) );
    printf("4、20、25 和 30 的和 = %d\n",  sum(4, 4, 20, 25, 30) );

    return 0;
}

int sum(int num_args, ...)
{
    int val = 0;
    va_list ap;/*定义一个va_list,类似与数组*/ 
    int i;

    va_start(ap, num_args);/*开始*/ 
    for(i = 0; i < num_args; i++)
    {
        val += va_arg(ap, int);/*每次循环取一个*/ 
    }
    va_end(ap);/*结束*/ 

    return val;
}
```