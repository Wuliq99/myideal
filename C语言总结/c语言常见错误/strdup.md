## 函数简介

### 函数原型

> char *strdup(char const *string)

### 头文件

> string.h

### 作用

> 对输入的字符串进行拷贝

### 返回值

> 返回一个指针,指向为复制字符串分配的空间;如果分配空间失败,则返回NULL值

### 使用注意

> strdup()在内部调用了malloc()为变量分配内存，不需要使用返回的字符串时，需要用free()释放相应的内存空间，否则会造成**内存泄漏**

## 函数详情

### 函数分析

> 该函数返回一个输入字符串的拷贝，该拷贝存储于一块动态分配的内存中。函数首先试图获取足够的内存来存储这份拷贝。内存的容量应该比字符串的长度多一个字节，以便存储字符串结尾的 NULL 。如果内存分配成功，字符串就会被复制到这块新内存。最后，函数会返回一个指向这块内存的指针。即使由于某些原因导致内存分配失败，函数也会返回一个 NULL 指针

### 模拟实现

```c
char *strdup(char const *string)
{
	char *new_string;
	
	new_string=malloc(strlen(string)+1);
	
	//如果得到内存，就复制字符串 
	if(new_string!=NULL){
		strcpy(new_string,string);
	}
	return new_string;
}
```

