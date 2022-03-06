#include<stdio.h>

void selectSort(int a[],int length){
	/*初始化左端、右端元素索引*/
int left = 0;
int right = length - 1;
while (left < right){
    
    int min = left;
    int max = right;
    for (int i = left; i <= right; i++){
        
        if (a[i] < a[min])
            min = i;
        if (a[i] > a[max])
            max = i;
    }
   
	/*先交换最小*/ 
    if(min!=left){
    	int temp=a[min];a[min]=a[left];a[left]=temp;
	}
	
	if(max!=right){
		/*此处是先排最小值的位置，所以得考虑最大值（arr[max]）在最小位置（left）的情况*/
		if(max==left)
		max=min;
		int temp=a[max];a[max]=a[right];a[right]=temp;
	}
    
    /*每趟遍历，元素总个数减少2，左右端各减少1，left和right索引分别向内移动1*/
    left++;
    right--;
}

} 
int main(){
	int a[]={34,23,65,88,23,786,43,23,67};	//以此数组为例，长度为九
	selectSort(a,9); 
	 for(int i=0;i<9;i++)
	 	printf("%d ",a[i]);
	return 0;
}
