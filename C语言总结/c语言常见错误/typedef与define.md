对于 #define

```c
//只会进行简单替换
#include<stdio.h>
#define b int *

int main(){
	int a=3;
	b p,q;
	p=&a;	// p 为 int* 型
	q=a;	// q 为 int 型
	printf("%d %d",*p,q);
}
/*
结果：3 3
*/
```



对于typedef

```c
//不是简单的替换
#include<stdio.h>
typedef int* b;

int main(){
	int a=3;
	b p,q;		// p、q 都为指针
	p=&a;
	q=&a;
	printf("%d %d",*p,*q);
}
/*
结果：3 3
*/
```

总结

define只是简单的替换，而typedef不是这样。