python变量范围

``` python
global_var='this  var  on  global space' 
'''
申明global_var这个位置就是全局域，也就是教程中所说的全局作用域，
同时它也是直接声明在文件中的，而不是声明在函数中或者类中的变量
'''
class demo():
  class_demo_local_var='class member' 
  '''
  虽然class_demo_local_var在这里是局部变量，这个局部变量的域相对于var_locals是外部域，
  所以可以直接被var_locals所在的更小的局部域访问
  '''
  def localFunc(self):
    var_locals='local_func_var'
    '''
    这里也是局部变量，但是相对于class_demo_local_var变量，却是更小的域，
    因此class_demo_local_var所在的哪个域无法访问到当前域来
    '''
    print(self.class_demo_local_var)#到这里会查找当前域中有没有class_demo_local_var这个变量，然后再到相对于当前域的外部域去查找变量
```



nonlocal

用于闭包，即在函数中封装函数时使用

``` python
count = 1

def a():
    count = 'a函数里面'  　　#如果不事先声明，那么函数b中的nonlocal就会报错
    def b():
        nonlocal count
        print(count)
        count = 2
    b()
    print(count)

if __name__ == '__main__':
    a()
    print(count)
```



以下两段代码会报错

``` python
count = 1

def a():
    #nonlocal count    #这种声明方法肯定报错，
    def b():
        nonlocal count    #在a()函数中没有提前声明，所以报错
        print(count)
        count = 2
    b()
    print(count)

if __name__ == '__main__':
    a()
    print(count)
```





``` python
count = 1

def a():
    global count
    count = 'a函数里面'
    def b():
        nonlocal count
        print(count)
        count = 2
    b()
    print(count)

if __name__ == '__main__':
    a()
    print(count)
```























示例

``` python
a = 10
def test():
    a = a + 1#此处报错，因为解释器认为等号左边的a未定义
    print(a)
test()
```

分析

由于python定义变量的方式，编译器会认为等号左边的a未定义

解决

``` python
a = 10
def test(a):
    a = a + 1
    print(a)
test(a)
```

``` python
a = 10
def test():
    global a
    a = a + 1
    print(a)
test()
```



``` python
num = 1
def fun1():
    global num  # 需要使用 global 关键字声明,不然第五行会报错
    print(num) 
    num = 123
    print(num)
fun1()
print(num)
```



如果要修改嵌套作用域（enclosing 作用域，外层非全局作用域）中的变量则需要 nonlocal 关键字了

``` python
def outer():
    num = 10
    def inner():
        nonlocal num   # nonlocal关键字声明，不然第五行报错
        num = 100
        print(num)
    inner()
    print(num)
outer()
```

