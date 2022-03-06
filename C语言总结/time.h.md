## 简介

**time.h** 头文件定义了四个变量类型、两个宏和各种操作日期和时间的函数。



## 库变量

下面是头文件 time.h 中定义的变量类型：

| 序号 | 变量 & 描述                                                 |
| :--- | :---------------------------------------------------------- |
| 1    | **size_t** 是无符号整数类型，它是 **sizeof** 关键字的结果。 |
| 2    | **clock_t** 这是一个适合存储处理器时间的类型。              |
| 3    | **time_t is** 这是一个适合存储日历时间类型。                |
| 4    | **struct tm** 这是一个用来保存时间和日期的结构。            |

``` c
struct tm {
   int tm_sec;         /* 秒，范围从 0 到 59        */
   int tm_min;         /* 分，范围从 0 到 59        */
   int tm_hour;        /* 小时，范围从 0 到 23        */
   int tm_mday;        /* 一月中的第几天，范围从 1 到 31    */
   int tm_mon;         /* 月，范围从 0 到 11        */
   int tm_year;        /* 自 1900 年起的年数        */
   int tm_wday;        /* 一周中的第几天，范围从 0 到 6    */
   int tm_yday;        /* 一年中的第几天，范围从 0 到 365    */
   int tm_isdst;       /* 夏令时                */
};
```



## 库宏

下面是头文件 time.h 中定义的宏：

| 序号 | 宏 & 描述                                           |
| :--- | :-------------------------------------------------- |
| 1    | **NULL** 这个宏是一个空指针常量的值。               |
| 2    | **CLOCKS_PER_SEC** 这个宏表示每秒的处理器时钟个数。 |



## 常用函数

| 函数原型                                | 说明                                                         |
| --------------------------------------- | ------------------------------------------------------------ |
| char *asctime(const struct tm *timeptr) | 返回一个指向字符串的指针，它代表了结构 **struct timeptr** 的日期和时间。 |
| clock_t clock(void)                     | 返回处理器时钟的时间                                         |
| char *ctime(const time_t *timer)        | 返回一个表示当地时间的字符串，当地时间是基于参数 **timer**   |



## 代码示例

``` c
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){
   struct tm t;

   t.tm_sec    = 10;
   t.tm_min    = 10;
   t.tm_hour   = 6;
   t.tm_mday   = 25;
   t.tm_mon    = 2;
   t.tm_year   = 89;
   t.tm_wday   = 6;
    
   puts(asctime(&t));
   return(0);
}
```

