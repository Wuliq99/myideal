> https://blog.csdn.net/chuxinchangcun/article/details/120219122?spm=1001.2014.3001.5501

注意
**strlen() 与 sizeof 的返回类型均为 size_t**

sizeof()返回类型造成的坑

```c
int i ;	//全局变量未初始化系统默认为0
int main()
{
    i--;	//i变成-1
    if(i > sizeof(i))
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }
    return 0;
}
```
打印结果: >

注意：sizeof(i)和i比较时，sizeof返回类型为size_t 而i的类型为int，最终是用size_t比较，对于-1的补码为：全1序列，如果看成是无符号数的话，对于的值比sizeof(i) = 4大