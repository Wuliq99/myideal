## 函数详情

**函数原型**

```c
void qsort(
    void *base,
    size_t nmemb,
    size_t size,
    int (*compar)(const void *, const void *)
    );
```

**头文件**

> stdlib.h

**函数功能**

> qsort()函数的功能是对数组进行排序，数组有nmemb个元素，每个元素大小为size

**各参数含义**

> 参数base : base指向数组的起始地址，通常该位置传入的是一个数组名
>
>
> 参数nmemb :nmemb表示该数组的元素个数
>
>
> 参数size :size表示该数组中每个元素的大小（字节数）
>
> 参数(*compar)(const void *, const void *):此为指向比较函数的函数指针，决定了排序的顺序
>

**函数返回值**

> 无

**注意**

> 如果两个元素的值是相同的，那么它们的前后顺序是不确定的。也就是说qsort()是一个不稳定的排序函数



## compar参数

compar参数是qsort函数排序的核心内容，它指向一个比较两个元素的函数，注意**两个形参必须是const void *型**，同时在调用compar 函数（即compar指针所指的函数，该函数名字可以为任何符合标识符的名字）时，**传入的实参被形参接受后，在使用时必须进行强制类型转换**

> 如果compar返回值小于0（< 0），那么p1所指向元素会被排在p2所指向元素的前面
>
> 如果compar返回值等于0（= 0），那么p1所指向元素与p2所指向元素的顺序不确定
>
> 如果compar返回值大于0（> 0），那么p1所指向元素会被排在p2所指向元素的后面
>

```c
//升序排序
int compare (const void * a, const void * b){
	return ( *(int*)a - *(int*)b );
}
//降序排列
int compare (const void * a, const void * b){
	return ( *(int*)b - *(int*)a );
}

```



示例

```c
/* qsort example */
#include <stdio.h>     
#include <stdlib.h>     

int values[] = { 40, 10, 100, 90, 20, 25 };
int compare (const void * a, const void * b){
	return ( *(int*)a - *(int*)b );
}

int main (){
	int n;
	qsort(values, sizeof(values)/sizeof(values[0]), sizeof(int), compare);
	for (n=0; n<sizeof(values)/sizeof(values[0]); n++)
		printf("%d ",values[n]);
	return 0;
}
```
