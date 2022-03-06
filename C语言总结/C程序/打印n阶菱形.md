## 题目：打印n阶菱形

​			


  对此，我的思路是先找规律。首先，n阶菱形中的n一定为奇数且菱形是上下对称，应此可以将菱形分成上下两部分。
  然后观察可得，○1菱形最中间一行星号的个数与菱形的阶数相同.○2从上至最中间满足1，3，5……n的规律。○3每一行与星号的个数也存在着关系。

```c
#include<stdio.h>
int main(){
	int n,i,j,k;
	printf("请输入菱形的总行数：");
	scanf("%d",&n);
	for(i=1;i<=(n/2+1);i++){
		for(j=1;j<=n/2+1-i;j++) printf(" ");
		for(k=1;k<=(2*i-1);k++) printf("*");
		printf("\n");
	}
	for(i=1;i<=(n/2);i++){
		for(j=1;j<=i;j++) printf(" ");
		for(k=1;k<=(n-2*i);k++) printf("*");
		printf("\n");
	}
	return 0;
}
```