# 冒泡排序（BubbleSort）

  冒泡排序是比较基础的排序算法之一，其思想是相邻的元素两两比较，较大的数下沉，较小的数冒起来，这样一趟比较下来，最大(小)值就会排列在一端。整个过程如同气泡冒起，因此被称作冒泡排序。
  冒泡排序的步骤是比较固定的：

> 1>比较相邻的元素。如果第一个比第二个大，就交换他们两个。
> 2>每趟从第一对相邻元素开始，对每一对相邻元素作同样的工作，直到最后一对。
> 3>针对所有的元素重复以上的步骤，除了已排序过的元素(每趟排序后的最后一个元素)，直到没有任何一对数字需要比较。

### 一般冒泡排序的写法

```c
#include<stdio.h>
void bul(int *a,int length){
	for(int i=0;i<length-1;i++){
		for(int j=0;j<length-1-i;j++){
			if(a[j]>a[j+1]){
				//交换
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		//输出每一趟
		printf("第%3d 趟：",i);
		for(int j=0;j<length;j++)
			printf("%d ",a[j]);
			printf("\n"); 
	}
	
	printf("结果是：");
	for(int i=0;i<length;i++)
		printf("%d ",a[i]); 
}

int main(){
	int a[]={2,3,4,5,5,4,56454,3,435,534,453453,445,3};	//设测试数组为a长度为13
	bul(a,13);
}
```

## 优化一

> 假设我们现在排序a[]={2,3,4,5,5,4,56454,3,435,534,453453,445,3}这组数据，按照上面的排序方式，第八趟排序后已经有序，接下来的排序就是多余的，什么也没做。所以我们可以在交换的地方加一个标记，如果那一趟排序没有交换元素，说明这组数据已经有序，不用再继续下去。

#### 代码实现：

```c
#include<stdio.h>
void bul(int *a,int length){
	int flag=1;
	for(int i=0;i<length-1;i++){
		for(int j=0;j<length-1-i;j++){
			if(a[j]>a[j+1]){
				//交换
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=0;
			}
		}
		
		if(flag)
			break;
		flag=1;
		//输出每一趟
		printf("第%3d 趟：",i);
		for(int j=0;j<length;j++)
			printf("%d ",a[j]);
			printf("\n"); 
	}
	
	printf("结果是：");
	for(int i=0;i<length;i++)
		printf("%d ",a[i]); 
}

int main(){
	int a[]={2,3,4,5,5,4,56454,3,435,534,453453,445,3};	//设测试数组为a长度为13
	bul(a,13);
}
```

## 优化二

> 优化一仅仅适用于连片有序而整体无序的数据(例如：1， 2，3 ，4 ，7，6，5)。但是对于前面大部分是无序而后边小半部分有序的数据(1，2，5，7，4，3，6，8，9，10)排序效率也不可观，对于种类型数据，我们可以继续优化。既我们可以记下最后一次交换的位置，后边没有交换，必然是有序的，然后下一次排序从第一个比较到上次记录的位置结束即可。

![这里写图片描述](https://img-blog.csdn.net/2018062700091521?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2hhbnNpb256/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

#### 代码实现：

```c
#include<stdio.h>
void bul(int *a,int length){
	int flag=1;
	int position=length-1;
	int k=0;
	for(int i=0;i<length-1;i++){
		for(int j=0;j<position;j++){
			if(a[j]>a[j+1]){
				//交换
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=0;
				k=j;
			}
		}
		position=k;
		if(flag){
			break;
		}
		flag=1;
		//输出每一趟
		printf("第%3d 趟：",i);
		for(int j=0;j<length;j++)
			printf("%d ",a[j]);
			printf("\n"); 
	}
	
	printf("结果是：");
	for(int i=0;i<length;i++)
		printf("%d ",a[i]); 
}

int main(){
	int a[]={2,3,4,5,5,4,56454,3,435,534,453453,445,3};	//设测试数组为a长度为13
	bul(a,13);
}
```

## 优化三

> 优化二的效率有很大的提升，还有一种优化方法可以继续提高效率。大致思想就是一次排序可以确定两个值，正向扫描找到最大值交换到最后，反向扫描找到最小值交换到最前面。例如：排序数据1，2，3，4，5，6，0。这种方法被称为双向冒泡排序，俗称鸡尾酒排序。

![这里写图片描述](https://img-blog.csdn.net/20180627192350535?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2hhbnNpb256/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

#### 代码实现：

```c
#include<stdio.h>
void prebul(int *a,int pre,int last){
	for(int i=0;i<last;i++){
		if(a[i]>a[i+1]){
			int temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
		}
	}
}

void lastbul(int *a,int pre,int last){
	for(int i=last;i>pre;i--){
		if(a[i]<a[i-1]){
			int temp=a[i];
			a[i]=a[i-1];
			a[i-1]=temp;
		}
	}
}
int main(){
	int a[]={2,665,45,574,5,435,56454,3,435,534,453453,445,3};	//设测试数组为a长度为13
	int pre=0,last=13-1;
	while(pre<last){
		prebul(a,pre,last);	//从左到右扫描
		last--;
		lastbul(a,pre,last);	//从右到左扫描
		pre++;
	}
	for(int i=0;i<13;i++){
		printf("%d ",a[i]);
	}
}
```