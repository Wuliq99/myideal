模拟实现

```
#include<stdio.h>
size_t strlen(char *string){
	int length=0;
	/*依次访问字符串的内容，直到遇到 NULL 终止符*/
	while(*string++!='\0'){
		length++;
	}
	return length;
}
```

