# 			getch()、getche()、kbhit()的使用

| 函数      | 作用                                                         | 是否为标准库函数 | 头文件  |
| --------- | ------------------------------------------------------------ | ---------------- | ------- |
| getch()   | 键盘上读入一个字符，不将读入的字符回显在显示屏幕上           | 否               | conoi.h |
| getche()  | 键盘上读入一个字符，并将读入的字符回显到显示屏幕上。         | 否               | conio.h |
| getchar() | 键盘上读入一个字符，需等待输入直到按回车                     | 是               | stdio.h |
| kbhit()   | 非阻断函数，运行时不会暂停程序，作用是若有键盘输入，则返回输入的值（应该是键值转换），若没有则返回0。 | 否               | conio.h |

**注意：**

> **getch()和getche()函数 都是从键盘上读入一个字符，但getch()函数不将读入的字符回显在显示屏幕上，而getche() 函数却将读入的字符回显到显示屏幕上。**
>
> **而getchar()函数与上述两个函数的区别是：需等待输入直到按回车才结束, 回车前的所有输入字符都会逐个显示在屏幕上，但只有第一个字符作为函数的返回值。**

------

## 详细情况

### getchar()

功能：

> 从控制台取字符，需要回车

原型：

>  int getchar(void); 

作用是从stdin流中读入一个字符，也就是说，如果stdin有数据的话不用输入它就可以直接读取了，第一次getchar()时，确实需要人工的输入，但是如果你输了多个字符，以后的getchar()再执行时就会直接从缓冲区中读取了

有一个int型的返回值.当程序调用getchar时.程序就等着用户按键.用户输入的字符被存放在键盘缓冲区中,直到用户按回车为止(回车字符也放在缓冲区中).当用户键入回车之后,getchar才开始从stdio流中每次读入一个字符.getchar函数的返回值是用户输入的第一个字符的ASCII码,如出错返回-1.

若用户**在按回车之前输入了不止一个字符**,其他字符会保留在键盘缓存区中,等待后续getchar调用读取.注意：已在键盘缓冲区的字符，不用等待用户按回车键就会调用getchar直到缓冲区中的字符读完为后,才等待用户按键.

键盘输入的字符都存到缓冲区内,一旦键入回车,getchar就进入缓冲区读取字符,一次只返回第一个字符作为getchar函数的值,如果有循环或足够多的getchar语句,就会依次读出缓冲区内的所有字符直到'\n'.要理解这一点,之所以你输入的一系列字符被依次读出来,是因为循环的作用使得反复利用getchar在缓冲区里读取字符,而不是getchar可以读取多个字符,事实上getchar每次只能读取一个字符

```c
#include <stdio.h>
int main()
{
int c;
while ((c = getchar()) != '\n') //不断循环调用getchar直至用户键入回车（即换行）
printf("%c", c);
return 0;
}
```



------

 

### **getch()** 

功能：

> 输入后立即从控制台取字符，不以回车为结束(不带回显)

函数原型：

> int getch(void);

用getch();会等待你按下任意键，再继续执行下面的语句；

用ch=getch();会等待你按下[任意键](http://baike.baidu.com/view/807945.htm)之后，把该键[字符](http://baike.baidu.com/view/263416.htm)所对应的ASCII码赋给ch,再执行下面的语句。

```c
#include<stdio.h>
#include<conio.h>
int main()
{
    char c;
    while((c=getch())!='\r') { //每接收到用户键入的一个字符则输出一个*直到按下了回车键
        printf("*");
    }
    return 0;
}
```



------

###  **getche()** 

功能：

> 输入后立即从控制台取字符，不以回车为结束(带回显)

原型：

> int getche(void); 

```c
#include<stdio.h>
#include<conio.h>
int main(void)
{
    char ch;
    printf("please input a character:");
    ch=getche();
    printf("\nyou have input a character '%c'\n",ch);
    return 0;
}
```



**getch()和getche()函数的区别：**

```c
#include <stdio.h>
#include <conio.h>
int main()
{
    char c, ch;
    c=getch(); //从键盘上读入一个字符不回显送给字符变量c
    putchar(c); //输出该字符
    puts(""); //puts()输出内容并换行
    ch=getche(); //从键盘上带回显的读入一个字符送给字符变量ch
    putchar(ch);
    return 0;
}
```

分析：

针对ch=getche()； 运行结果可见会既回显用户键入的字符，又会立即从控制台取字符并由putchar(ch)输出，所以会看到两个重复的字符

------





附(引：[关于kbhit()与getch()组合的猜测 - kohano - 博客园 (cnblogs.com)](https://www.cnblogs.com/kohano/p/14819593.html))：

> kbhit：非阻断函数，运行时不会暂停程序，作用是若有键盘输入，则返回输入的值（应该是键值转换），若没有则返回0。
> getch：阻断函数。等待键盘输入，并在输入后立即返回第一个字符，无需按下回车
>
> 将以下代码嵌套至while(1)内循环:
>
> ```
> void move()
> {
>  char a;
>  bool b;
>  b=kbhit();
>  if(b)
>  {
>      a=getch();
>      cout<<"yes__________________________________________________________________________________-";
>  }
>  else
>  {
>      cout<<"no  "<<a;
>  }
> }
> ```
>
> 能够实现持续获得键盘输入，即类似于贪吃蛇等游戏的实时反馈功能。
>
> 但是如果将代码中的a=getch()删除，或给a赋值任意常量。
>
> 则该功能失效。
>
> 测试过程中发现：
>
> kbhit()与getch()组合时，kbhit()的值初始为false,按键后为true，在经过getch()后再次变为false。
>
> 删除getch()之后，kbhit()的值初始为false,按键后为true，此后一直为true，不再改变。
>
> 
>
> 根据测试过程猜测：
>
> 1.kbhit()会根据某一标准判断是否按键，并根据该标准改变值
>
> 2.由于getch()具有读取键盘缓存区数据的功能,因此推测kbhit()的改变是由于getch()对于缓存区数据读取造成，即：
>
> kbhit对于是否按键的标准为==>键盘缓存区是否有数据存储
>
> 
>
> 这样一来就可以解释为何kbhit()与getch()组合是产生的功能：键盘按键后，键盘缓存区存入数据，kbhit()随之改变值。之后进程调用getch()，getch()读取缓存区内数据，缓存区清零。再次调用kbhit()时，
>
> 此时由于缓存区数据已被getch()读取清零，所以kbhit()再次改变值。
>
> 以上仅为个人猜测。