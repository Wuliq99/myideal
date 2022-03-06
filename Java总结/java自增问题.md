java自增

```` java
public class selfAdd {
    public static void main(String[] args) {
        int count = 0;
        int num = 0 ;
        for(int i=0;i<=100;i++){
            num=num+i;
            count=count++;
        }
        System.out.println(num);
        System.out.println("num * count = "+(num*count));
    }
}
````

自增解释

``` java
count=count++;

等价于
    
temp=count;
count++;
count=temp;
```



参考

[java基础(二) 自增自减与贪心规则 - jinggod - 博客园 (cnblogs.com)](https://www.cnblogs.com/jinggod/p/8424808.html)
