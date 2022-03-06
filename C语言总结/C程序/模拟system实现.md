#### 头文件

> stdlib.h

#### 函数原型

> int system(const char * command)
>

#### 函数功能

> 执行 dos(windows系统) 或 shell(Linux/Unix系统) 命令，参数字符串command为命令名。另，在windows系统下参数字符串不区分大小写

#### 说明

> 在windows系统中，system函数直接在控制台调用一个command命令。
> 在Linux/Unix系统中，system函数会调用fork函数产生子进程，由子进程来执行command命令，命令执行完后随即返回原调用的进程。

#### 返回值

> 命令执行成功返回0

#### 示例

```c
#include <stdio.h>
#include<stdlib.h>
int main(void)
{
    system("shutdown -s -t 60");/*设置 60 秒后关机*/
    
 	system("shutdown -a");/*取消关机*/
    return 0;
}
```