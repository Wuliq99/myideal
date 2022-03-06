#include<stdio.h>

void selectSort(int a[],int length){
	/*��ʼ����ˡ��Ҷ�Ԫ������*/
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
   
	/*�Ƚ�����С*/ 
    if(min!=left){
    	int temp=a[min];a[min]=a[left];a[left]=temp;
	}
	
	if(max!=right){
		/*�˴���������Сֵ��λ�ã����Եÿ������ֵ��arr[max]������Сλ�ã�left�������*/
		if(max==left)
		max=min;
		int temp=a[max];a[max]=a[right];a[right]=temp;
	}
    
    /*ÿ�˱�����Ԫ���ܸ�������2�����Ҷ˸�����1��left��right�����ֱ������ƶ�1*/
    left++;
    right--;
}

} 
int main(){
	int a[]={34,23,65,88,23,786,43,23,67};	//�Դ�����Ϊ��������Ϊ��
	selectSort(a,9); 
	 for(int i=0;i<9;i++)
	 	printf("%d ",a[i]);
	return 0;
}
