```c
#include<stdio.h>
int main(){
	int i=0;
	int a[3]={0};
	for(;i<=3;i++){
		a[i]=0;
		printf("hello world\n");
	}
	return 0;
}
```

**错因**

对 **数组 a** 进行了越界访问，而访问的地址正是 **变量 i** 在内存中的地址，在第四次循环时又将 **变量i** 的值置为 0 ,因此程序会陷入无限循环