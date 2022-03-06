next()实现

``` c
#include<stdio.h>
void Getnext(int next[],char *t)
{
   int j=0,k=-1;
   next[0]=-1;
   while(j<4)
   {
      if(k == -1 || t[j] == t[k])
      {
         j++;k++;
         next[j] = k;
      }
      else k = next[k];
   }
}

int main(){
	int next[5];
	Getnext(next,"ababc");
	for(int i=0;i<5;i++)
		printf("%d ",next[i]);
}
```





完整实现

``` c
#include<stdio.h>
#include<string.h>

void GetNext(int next[],char *t)
{
   int j=0,k=-1;
   next[0]=-1;
   while(j<4)
   {
      if(k == -1 || t[j] == t[k])
      {
         j++;k++;
         next[j] = k;
      }
      else k = next[k];
   }
}

int CompareString(char *s,char *t){

    int j=0,n=strlen(s);
	int m=strlen(t);
    int next[10];
    GetNext(next,t);
    for(int i=0;i<n;i++){
        while (j>0&&s[i]!=t[j]){
            j=next[j-1]+1;
        }
        if(s[i]==t[j]){
            j++;
        }
        if(j==m){
            return i-m+1+1;
        }
    }
    return -1;
}/*s为主串，t为模式串*/


int main(){
	char a[]="qwereteradsffewresdfsd",b[20];
	int next[10];
	while(1){
		gets(b); 
	printf("%d \n",CompareString(a,b));
	}
	return 0;
} 
```

