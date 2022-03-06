#include<stdio.h>

void selectSort(int a[],int length){
	for(int i=0;i<length-1;i++){
		int index=i;
		for(int j=i+1;j<length;j++){
			if(a[j]<a[index]){
				index=j;
			}
		}
		if(i!=index){
			int temp=a[i];a[i]=a[index];a[index]=temp;
		}
	}
} 
int main(){
	int a[]={34,23,65,88,23,786,43,23,67};	//以此数组为例，长度为九
	selectSort(a,9); 
	 for(int i=0;i<9;i++)
	 	printf("%d ",a[i]);
	return 0;
}
