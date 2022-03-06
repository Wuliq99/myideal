DOM对象与jQuery对象

DOM对象

通过JavaScript中的getElementsByTagName或者getElementById来获取元素节点，这样获得的DOM元素就是DOM对象

jQuery对象

jQuery对象就是通过jQuery包装DOM对象后产生的对象

注意

jQuery对象和DOM对象的方法不能混用

DOM对象与jQuery对象的相互转换

Query对象转DOM对象

1.jQuery对象是一个数组对象，可以通过[index]的方法得到相应的DOM对象

``` javascript
var $a = $("#a")		//jQuery对象
var a=$a[0]		//DOM对象
alert(a.checked)	//检测是否被选中
```

2.使用jQuery对象本身提供的方法，即 get() 方法

``` js
var $a = $("#a")		//jQuery对象
var a=$a.get(0)		//DOM对象
alert(a.checked)		//检测是否被选中
```



DOM对象转jQuery对象

对于一个DOM对象，只需要用 $() 把DOM对象包装起来

``` js
var cr=document.getElementById("cr");	//DOM对象
var $cr = $(cr);		//jQuery对象
```





































































