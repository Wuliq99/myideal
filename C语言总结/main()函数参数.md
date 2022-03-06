## 原因

​		由于C程序必须有main()函数为入口,而且它不能被其他函数调用(可以调用自身),因此不能再程序内部取得实际值.那么在何处把实参赋值给main函数的形参呢？这就需要调用"运行"或"DOS提示符",在调用可执行程序exe时,编译器会帮助我们将输入参数的信息放入main函数的参数列表中传参.

## 详细含义

通常我们在写主函数时会写成以下形式

```c
void main()
或
int main()
```

但ANSI-C(美国国家标准协会,C的第一个标准ANSI发布)在C89/C99中main()函数主要形式为

```c
int main(void)
或
int main(int argc,char *argv[])			//也可写成 int main(int argc,char **argv).
```


其参数argc和argv用于运行时,把命令行参数传入主程序.其中arg是指arguments,即参数.具体含义如下:

argc

> 英文名为 `arguments count`,是一个整型变量，用于记录命令行参数总个数，包括可执行程序名,其中当argc=1时表示只有一个程序名称,此时存储在argv[0]中

argv

> 英文名为 `arguments value`，是一个字符串数组，用来存放指向字符串参数的指针数组,每个元素指向一个参数，空格分隔参数,其长度为argc。数组下标从0开始，含义如下
>
> - argv[0] 指向程序名称
> - argv[1] 指向程序在DOS命令中执行程序名后的第一个字符串
> - argv[2] 指向执行程序名后的第二个字符串
> - argv[argc] 为NULL.

## 程序示例

### 示例一

```c
//C 输出参数个数
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	printf("参数个数=%d\n",argc);
	system("PAUSE");
	return 0;
}

//C++ 输出参数个数
#include <iostream>
using namespace std;
int main(int argc,char *argv[]){
	cout<<"参数个数="<<argc<<endl;
	system("PAUSE");
	return 0;
}
```

​		在命令行中输入"G:\test.exe"会输出"参数个数=1",此时存储的就是执行程序名.输入"G:\test.exe 2 hello good"输出"参数个数=4":

### 示例二

```c
//C 查看argv存储参数值及对应序号
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
	int i;
	printf("参数个数=%d\n",argc);
	for(i=0; i<argc; i++){
		printf("参数序号=%d ",i);
		printf("参数值=%s\n",argv[i]);
	}
	system("PAUSE");
	return 0;
}

//C++ 查看argv存储参数值及对应序号
#include <iostream>
using namespace std;
int main(int argc,char *argv[]){
	cout<<"参数个数="<<argc<<endl;
	for(int i=0; i<argc; i++){
		cout<<"参数序号="<<i<<" ";
		cout<<"参数值="<<argv[i]<<endl;     
	}
	system("PAUSE");
	return 0;
}
```

