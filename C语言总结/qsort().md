# 								qsort()

简介

```c
头文件：
    stdlib.h
用 法： 
 void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
参数： 
    base -- 指向要排序的数组的第一个元素的指针。
    nitems -- 由 base 指向的数组中元素的个数。
    size -- 数组中每个元素的大小，以字节为单位。
    compar -- 用来比较两个元素的函数。
    	如果compar返回值小于0（< 0），那么p1所指向元素会被排在p2所指向元素的左面；
    	如果compar返回值等于0（= 0），那么p1所指向元素与p2所指向元素的顺序不确定；
    	如果compar返回值大于0（> 0），那么p1所指向元素会被排在p2所指向元素的右面。
```

示例

```c
#include <stdio.h>  
#include <stdlib.h>  
  
//整数从小到大排序
int cmp1(const void *a, const void *b)  
{  
    return *(int*)a - *(int*)b;  
}  
//整数从大到小排序  
int cmp2(const void *a, const void *b)  
{  
    return *(int*)b - *(int*)a;  
}  
  
int main()  
{  
    int num[8] = {4,11,2,-3,15,4,0,7};    
    int len = 8;  
    int i;  
    printf("整数从小到大排序:\n");  
    qsort(num, len, sizeof(int), cmp1);  
    for(i = 0; i < len; i ++)  
    {  
        printf("%d ", num[i]);  
    }  
    printf("\n\n");  
    printf("整数从大到小排序:\n");  
    qsort(num, len, sizeof(int), cmp2);  
    for(i = 0; i < len; i ++)  
    {  
        printf("%d ", num[i]);  
    }  
    printf("\n");  
    system("PAUSE");
    return 0;  
}

```
二维数组快排

其中按照a[0]的大小进行一个整体的排序，其中a[1]必须和a[0]一起移动交换。//即第一行和第二行（a[0]和a[1]分别代表第一行和第二行的首地址）。使用库函数排序的代码量并不比用[冒泡排序法](https://baike.baidu.com/item/冒泡排序法/9940890)小，但速度却快很多

```c
#include <stdio.h>  
#include <stdlib.h>  
  
//二维数组按照num[i][0]从小到大排序
int cmp(const void *a, const void *b)  
{  
    return ((int*)a)[0] - ((int*)b)[0];  
}  
 
int main()  
{  
    int num[6][2] = {
		4, 1,
	   11, 2,
		2, 3,
	   -3, 4,
	   15, 5,
	    0, 7,
	};    
    int len = 6;  
    int i;  
  
    printf("排序前:\n"); 
	for(i = 0; i < len; i ++)  
    {  
        printf("%4d %4d\n", num[i][0], num[i][1]);  
    } 
	printf("\n"); 
 
    qsort(num, len, sizeof(int)*2, cmp);   
     
    printf("排序后:\n");  
    for(i = 0; i < len; i ++)  
    {  
        printf("%4d %4d\n", num[i][0], num[i][1]);  
    } 
    printf("\n");  
  
	system("PAUSE");
    return 0;  
} 
```

字符串排序

```c
#include <stdio.h>  
#include <stdlib.h>  
  
int cmp(const void *a, const void *b)  
{  
    return *(char*)a - *(char*)b;  
}  
 
int main()  
{  
    char str[7][10] = {
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
	    "Friday",
	    "Staturday",
	    "Sunday"
	};    
    int sum = 7;  
    int i;  
  
    printf("排序前:\n"); 
	for(i = 0; i < sum; i++)  
    {  
        printf("%s\n", str[i]);  
    } 
	printf("\n"); 
 
    qsort(str, sum, sizeof(char)*10, cmp);   
     
    printf("排序后:\n");  
    for(i = 0; i < sum; i++)  
    {  
         printf("%s\n", str[i]);  
    } 
    printf("\n");  
  
	system("PAUSE");
    return 0;  
}   
```

double类型排序

```c
#include <stdio.h>  
#include <stdlib.h>  
  
int cmp(const void *a, const void *b)  
{  
    return *(double*)a > *(double*)b ? 1 : -1;  
}  
 
int main()  
{  
    double num[7] = {
		12.2324,
		-4.3457,
		0.00000,
		5.64375,
	    1.25879,
	    0.00001,
	    7.85435
	};    
    int sum = 7;  
    int i;  
  
    printf("排序前:\n"); 
	for(i = 0; i < sum; i++)  
    {  
        printf("%10f\n", num[i]);  
    } 
	printf("\n"); 
 
    qsort(num, sum, sizeof(double), cmp);   
     
    printf("排序后:\n");  
    for(i = 0; i < sum; i++)  
    {  
         printf("%10f\n", num[i]);  
    } 
    printf("\n");  
  
	system("PAUSE");
    return 0;  
}   
```

结构体排序（按照某一特征）

```c
#include <stdio.h>  
#include <stdlib.h>  
#define N 6  
  
typedef struct  
{  
    char name[15];  
    int  score;  
  
}Student;  
  
int compare1(const void *a,const void *b)  
{  
    return ((Student*)a)->score - ((Student*)b)->score;  
}  
  
int compare2(const void *a,const void *b)  
{  
    return *(((Student*)a)->name) - *(((Student*)b)->name);  
}  
 
int main()  
{  
    Student s[N] =  
    {  
    "Zhang San", 94,  
    "Li Si",     80,  
    "You",       94,  
    "I",        100,  
    "He",        72,  
    "She",       60  
    };  
  
    int i; 
	printf("按照分数排序:\n");
    qsort(s, N, sizeof(Student), compare1);  
    for(i = 0; i < N; i++)  
    {  
        printf("%-15s : %d\n", s[i].name, s[i].score);   
    }  
    printf("\n");  
  
    qsort(s, N, sizeof(Student), compare2);  
	printf("按照姓名排序:\n");
    for(i = 0; i < N; i++)  
    {  
        printf("%-15s : %d\n", s[i].name, s[i].score);   
    }  
	system("PAUSE");
    return 0;  
}  
```

快速排序实现

分治法

```c
void quick_sort1(int s[], int l, int r)  
{  
    if (l < r)  
    {  
        int i = AdjustArray(s, l, r);//先成挖坑填数法调整s[]  
        quick_sort1(s, l, i - 1); // 递归调用   
        quick_sort1(s, i + 1, r);  
    }  
}  
```

挖坑填数

```c
void quick_sort1(int s[], int l, int r)  
{  
    if (l < r)  
    {  
        int i = AdjustArray(s, l, r);//先成挖坑填数法调整s[]  
        quick_sort1(s, l, i - 1); // 递归调用   
        quick_sort1(s, i + 1, r);  
    }  
}  
```

