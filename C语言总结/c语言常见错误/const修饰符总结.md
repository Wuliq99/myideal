## 总结

> - const位于 * 前，可以改变指针所指的变量 ,但不可改变指针所指变量的值
> - const位于 * 后，不可以改变指针所指的变量 ，但可以改变所指变量的值
> - const同时位于 * 前和 * 后，既不可以改变指针所指的变量 ,也不可改变指针所指变量的值 

## 示例

### 错误示例

#### 错误一

```c
#include<stdio.h>
int main(){
	int a=4,b=3;
	const int *p=&a;
	*p=8;	// const位于 * 前，可以改变指针所指的变量 ,但不可改变指针所指变量的值 
	printf("%d",*p);
	return 0; 
}
```

#### 错误二

```c
#include<stdio.h>
int main(){
	int a=4,b=3;
	int * const p=&a;
	p=&b;		// const位于 * 后，不可以改变指针所指的变量 ，但可以改变所指变量的值 
	printf("%d",*p);
	return 0;
}
```

#### 错误三

```c
#include<stdio.h>
int main(){
	int a=4,b=3;
	const int * const p=&a;
	*p=8;	// const同时位于 * 前和 * 后，既不可以改变指针所指的变量 ,也不可改变指针所指变量的值 
	printf("%d",*p);
	return 0;
}
```

#### 错误四

```c
#include<stdio.h>
int main(){
	int a=4,b=3;
	const int * const p=&a;
	p=&b;	// const同时位于 * 前和 * 后，既不可以改变指针所指的变量 ,也不可改变指针所指变量的值 
	printf("%d",*p);
	return 0;
}
```

### 正确实例

#### 示例一

```c
#include<stdio.h>
int main(){
	int a=4,b=3;
	const int *p=&a;
	p=&b;				// const位于 * 前，可以改变指针所指的变量 
	printf("%d",*p);
	return 0;
}
```

#### 示例二

```c
#include<stdio.h>
int main(){
	int a=4,b=3;
	int * const p=&a;
	*p=8;		// const位于 * 后，不可以改变指针所指的变量 ，但可以改变所指变量的值 
	printf("%d",*p);
	return 0;
}
```

