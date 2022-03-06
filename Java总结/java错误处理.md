java错误处理

``` java
package ttt;
public class Example6_5 {
    public static int check(String agestr) throws Throwable{
        int age=Integer.parseInt(agestr);
        if(age<0){
            throw new Exception("age can`t be an -number");
        }
        return age;
    }

    public static void main(String[] args) {
       try {
           int stuage=check("-20");
           System.out.println(stuage);
       }
        //此处存在错误
       catch (Exception e){
           System.out.println("data error");
           System.out.println("case: "+e.getMessage());
       }
    }
}
```

分析

错误处理时，生成的错误处理对象不一致时，会进行隐式类型转换(因为错误对象都是相互继承而来)，但只能子类向父类转（即范围小的向范围大的转）



``` java
package Inclass.cheapter6;

public class Chap6_1 {
    public static void main(String[] args) {
        try {
            int[] ints = {1, 2, 3, 4};
            System.out.println("异常出现前");
            System.out.println(ints[4]);
            System.out.println("我还有幸执行到吗?");

        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(e.getMessage());
        } catch (Exception r) {

        }
    }
}
```

分析

进行异常捕获时，要注意捕获的顺序，即异常的范围要**从小到大**排列



throws

为啥要用throws来抛出异常？

使用throw抛出异常，表示程序中必须要有该异常的处理语句（即使该异常不会发生）

``` java

class MyException extends Exception{
    private String str;
    MyException(String str){
        this.str=str;
    }
    public String getMessage(){
        return str;
    }
}

public class ddd {
    public static int check(String agestr) throws Exception{
        int age=Integer.parseInt(agestr);
        if(age<0){
            throw new MyException("age can`t be an -number");
        }
        return age;
    }

    public static void main(String[] args) {
       /* try {
            int stuage=check("-20");
            System.out.println(stuage);
        }
        catch( Throwable e){
            System.out.println("data error");
            System.out.println("case: "+e.getMessage());
        }*/
        //以下的语句会报错，由于未进行异常处理
        int stuage=check("-20");
        System.out.println(stuage);
    }
}
```

