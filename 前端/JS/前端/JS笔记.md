

# JS笔记

- 把脚本置于 **<body>** 元素的底部，可改善显示速度，因为脚本编译会拖慢显示。

- 所有字符串方法都会返回新字符串。它们不会修改原始字符串。正式地说：**字符串是不可变的,字符串不能更改，只能替换。**

- ``` html
  <!DOCTYPE html>
  <html>
  	<head>
  		<meta charset="utf-8">
  		<title></title>
  		<script type="text/javascript">
  			var te="HELLO";
  			document.write(te.toLowerCase());
  			document.write(te);
  		</script>
  	</head>
  	<body>
  	</body>
  </html>
  ```

- ```html
  var str = "HELLO WORLD";
  str[0] = "A";             // 不产生错误，但不会工作
  str[0];                   // 返回 H
  ```

- 不同的对象无法进行比较。JavaScript 对象无法进行对比，比较两个 JavaScript 对象将始终返回 false。

- 在 HTML 中，JavaScript 程序由 web 浏览器执行。

- 在计算机程序中，被声明的变量经常是不带值的。值可以是需被计算的内容，或是之后被提供的数据，比如数据输入。

- 不带有值的变量，它的值将是 undefined。

- HTML 事件是发生在 HTML 元素上的“事情”。当在 HTML 页面中使用 JavaScript 时，JavaScript 能够“应对”这些事件。

- 其他六个 JavaScript 中有效的转义序列：

| 代码 | 结果       |
| :--- | :--------- |
| \b   | 退格键     |
| \f   | 换页       |
| \n   | 新行       |
| \r   | 回车       |
| \t   | 水平制表符 |
| \v   | 垂直制表符 |

这六个转义字符最初设计用于控制打字机、电传打字机和传真机。它们在 HTML 中没有任何意义。

- 长代码行换行

为了最佳可读性， 程序员们通常会避免每行代码超过 80 个字符串。

如果某条 JavaScript 语句不适合一整行，那么最佳换行位置是某个运算符之后：

### 实例

```
document.getElementById("demo").innerHTML =
"Hello Kitty.";
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_statements_linebreak)



您也可以*在字符串中*换行，通过一个反斜杠即可：

### 实例

```
document.getElementById("demo").innerHTML = "Hello \
Kitty!";
```



\ 方法并不是 ECMAScript (JavaScript) 标准。

某些浏览器也不允许 \ 字符之后的空格。

对长字符串换行的最安全做法（但是有点慢）是使用字符串加法：

### 实例

```
document.getElementById("demo").innerHTML = "Hello" + 
"Kitty!";
```

您不能通过反斜杠对代码行进行换行：

### 实例

```
<!DOCTYPE html>
<html>
<body>

<h1>JavaScript 语句</h1>

<p id="demo">您不能用反斜杠对代码行进行折行。</p>

<script>
document.getElementById("demo").innerHTML = \
"Hello Kitty";
</script>

</body>
</html>

```

## JavaScript 显示方案

JavaScript 能够以不同方式“显示”数据：

- 使用 window.alert() 写入警告框

``` html
<!DOCTYPE html>
<html>
<body>
<h1>我的第一张网页</h1>
<p>我的第一个段落</p>
    
<script>
window.alert(5 + 6);
</script>

</body>
</html> 
```

- 使用 document.write() 写入 HTML 输出

``` html
<!DOCTYPE html>
<html>
<body>

<h1>我的第一张网页</h1>

<p>我的第一个段落</p>

<script>
document.write(5 + 6);
</script>

</body>
</html> 
```

- 使用 innerHTML 写入 HTML 元素

```html
<!DOCTYPE html>
<html>
<body>

<h1>我的第一张网页</h1>

<p>我的第一个段落</p>

<p id="demo"></p>

<script>
 document.getElementById("demo").innerHTML = 5 + 6;
</script>

</body>
</html> 
```

- 使用 console.log() 写入浏览器控制台（将数据写入到浏览器控制台）

``` html
<!DOCTYPE html>
<html>
<body>

<h1>我的第一张网页</h1>

<p>我的第一个段落</p>

<script>
console.log(5 + 6);
</script>

</body>
</html>
```

## JavaScript 关键词

JavaScript 语句常常通过某个关键词来标识需要执行的 JavaScript 动作。

下面的表格列出了一部分将在教程中学到的关键词：

| 关键词        | 描述                                              |
| :------------ | :------------------------------------------------ |
| break         | 终止 switch 或循环。                              |
| continue      | 跳出循环并在顶端开始。                            |
| debugger      | 停止执行 JavaScript，并调用调试函数（如果可用）。 |
| do ... while  | 执行语句块，并在条件为真时重复代码块。            |
| for           | 标记需被执行的语句块，只要条件为真。              |
| function      | 声明函数。                                        |
| if ... else   | 标记需被执行的语句块，根据某个条件。              |
| return        | 退出函数。                                        |
| switch        | 标记需被执行的语句块，根据不同的情况。            |
| try ... catch | 对语句块实现错误处理。                            |
| var           | 声明变量。                                        |

**注释：**JavaScript 关键词指的是保留的单词。保留词无法用作变量名。

## JavaScript 注释

并非所有 JavaScript 语句都被“执行”。

双斜杠 // 或 /* 与 **/* 之间的代码被视为*注释*。

注释会被忽略，不会被执行：

``` html
var x = 7;   // 会执行

// var x = 8;   不会执行
```

## JavaScript 标识符

标识符是名称。

在 JavaScript 中，标识符用于命名变量（以及关键词、函数和标签）。

在大多数编程语言中，合法名称的规则大多相同。

在 JavaScript 中，首字符必须是字母、下划线（-）或美元符号（$）。

连串的字符可以是字母、数字、下划线或美元符号。

构造变量名称（唯一标识符）的通用规则是：

- 名称可包含字母、数字、下划线和美元符号
- 名称必须以字母开头
- 名称也可以 $ 和 _ 开头（但是在本教程中我们不会这么做）
- 名称对大小写敏感（y 和 Y 是不同的变量）
- 保留字（比如 JavaScript 的关键词）无法用作变量名称

**提示：**数值不可以作为首字符。这样，JavaScript 就能轻松区分标识符和数值。

## JavaScript 与驼峰式大小写

历史上，程序员曾使用三种把多个单词连接为一个变量名的方法：

### 连字符：

```
first-name, last-name, master-card, inter-city.
```

**注释：**JavaScript 中不能使用连字符。它是为减法预留的。

### 下划线：

```
first_name, last_name, master_card, inter_city.
```

### 驼峰式大小写（Camel Case）：

```
FirstName, LastName, MasterCard, InterCity.
```

![camelCase](https://www.w3school.com.cn/i/camelcase.png)

JavaScript 程序员倾向于使用以小写字母开头的驼峰大小写：

```
firstName, lastName, masterCard, interCity
```

## JavaScript 字符集

JavaScript 使用 *Unicode* 字符集。

Unicode 覆盖世界上几乎所有的字符、标点和符号。

## JavaScript 类型运算符

| 运算符     | 描述                                  |
| :--------- | :------------------------------------ |
| typeof     | 返回变量的类型。                      |
| instanceof | 返回 true，如果对象是对象类型的实例。 |

## JavaScript 位运算符

位运算符处理 32 位数。

该运算中的任何数值运算数都会被转换为 32 位的数。结果会被转换回 JavaScript 数。

| 运算符 | 描述         | 例子    | 等同于       | 结果 | 十进制 |
| :----- | :----------- | :------ | :----------- | :--- | :----- |
| &      | 与           | 5 & 1   | 0101 & 0001  | 0001 | 1      |
| \|     | 或           | 5 \| 1  | 0101 \| 0001 | 0101 | 5      |
| ~      | 非           | ~ 5     | ~0101        | 1010 | 10     |
| ^      | 异或         | 5 ^ 1   | 0101 ^ 0001  | 0100 | 4      |
| <<     | 零填充左位移 | 5 << 1  | 0101 << 1    | 1010 | 10     |
| >>     | 有符号右位移 | 5 >> 1  | 0101 >> 1    | 0010 | 2      |
| >>>    | 零填充右位移 | 5 >>> 1 | 0101 >>> 1   | 0010 | 2      |

上例使用 4 位无符号的例子。但是 JavaScript 使用 32 位有符号数。

因此，在 JavaScript 中，~ 5 不会返回 10，而是返回 -6。

~00000000000000000000000000000101 将返回 11111111111111111111111111111010。



## 这两种方法是不相等的。区别在于：

- search() 方法无法设置第二个开始位置参数。
- indexOf() 方法无法设置更强大的搜索值（正则表达式）。

# JavaScript 数据

**字符串值，数值，布尔值，数组，对象。**

## JavaScript 数据类型

JavaScript 变量能够保存多种*数据类型*：数值、字符串值、数组、对象等等：

```
var length = 7;                             // 数字
var lastName = "Gates";                      // 字符串
var cars = ["Porsche", "Volvo", "BMW"];         // 数组
var x = {firstName:"Bill", lastName:"Gates"};    // 对象 
```

## 数据类型的概念

在编程过程中，数据类型是重要的概念。

为了能够操作变量，了解数据类型是很重要的。

如果没有数据类型，计算机就无法安全地解决这道题：

```
var x = 911 + "Porsche";
```

给 "Volvo" 加上 911 有意义吗？这么做会发生错误还是会产生一个结果？

JavaScript 会这样处理上面的例子：

```
var x = "911" + "Porsche";
```

当数值和字符串相加时，JavaScript 将把数值视作字符串。

### 实例

```
var x = 911 + "Porsche";
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_addstrings_1)

### 实例

```
var x = "Porsche" + 911;
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_addstrings_2)

JavaScript 从左向右计算表达式。不同的次序会产生不同的结果：

### JavaScript：

```
var x = 911 + 7 + "Porsche";
```

结果：

```
918Porsche
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_addstrings_3)

### JavaScript：

```
var x = "Porsche" + 911 + 7;
```

结果：

```
Porsche9117
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_addstrings_4)

在第一个例子中，JavaScript 把 911 和 7 视作数值，直到遇见 "Porsche"。

在第二个例子中，由于第一个操作数是字符串，因此所有操作数都被视为字符串。

## JavaScript 拥有动态类型

JavaScript 拥有动态类型。这意味着相同变量可用作不同类型：

### 实例

```
var x;               // 现在 x 是 undefined
var x = 7;           // 现在 x 是数值
var x = "Bill";      // 现在 x 是字符串值
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_dynamic)

## JavaScript 字符串值

字符串（或文本字符串）是一串字符（比如 "Bill Gates"）。

字符串被引号包围。您可使用单引号或双引号：

### 实例

```
var carName = "Porsche 911";   // 使用双引号
var carName = 'Porsche 911';   // 使用单引号
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_string_quotes)

您可以在字符串内使用引号，只要这些引号与包围字符串的引号不匹配：

### 实例

```
var answer = "It's alright";             // 双引号内的单引号
var answer = "He is called 'Bill'";    // 双引号内的单引号
var answer = 'He is called "Bill"';    // 单引号内的双引号
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_string)

您将在本教程中学到更多有关字符串的知识。

## JavaScript 数值

JavaScript 只有一种数值类型。

写数值时用不用小数点均可：

### 实例

```
var x1 = 34.00;     // 带小数点
var x2 = 34;        // 不带小数点
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_number)

超大或超小的数值可以用科学计数法来写：

### 实例

```
var y = 123e5;      // 12300000
var z = 123e-5;     // 0.00123
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_number_large)

您将在本教程中学到更多有关数值的知识。

## JavaScript 布尔值

布尔值只有两个值：true 或 false。

### 实例

```
var x = true;
var y = false;
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_bolean)

布尔值经常用在条件测试中。

您将在本教程中学到更多有关条件测试的知识。

## JavaScript 数组

JavaScript 数组用方括号书写。

数组的项目由逗号分隔。

下面的代码声明（创建）了名为 cars 的数组，包含三个项目（汽车品牌）：

### 实例

```
var cars = ["Porsche", "Volvo", "BMW"];
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_array)

数组索引基于零，这意味着第一个项目是 [0]，第二个项目是 [1]，以此类推。

您将在本教程中学到更多有关数组的知识。

## JavaScript 对象

JavaScript 对象用花括号来书写。

对象属性是 *name*:*value* 对，由逗号分隔。

### 实例

```
var person = {firstName:"Bill", lastName:"Gates", age:62, eyeColor:"blue"};
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_object)

上例中的对象（person）有四个属性：firstName、lastName、age 以及 eyeColor。

您将在本教程中学到更多有关对象的知识。

## typeof 运算符

您可使用 JavaScript 的 typeof 来确定 JavaScript 变量的类型：

typeof 运算符返回变量或表达式的类型：

### 实例

```
typeof ""                  // 返回 "string"
typeof "Bill"              // 返回 "string"
typeof "Bill Gates"          // 返回 "string"
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_typeof_string)

### 实例

```
typeof 0                   // 返回 "number"
typeof 314                 // 返回 "number"
typeof 3.14                // 返回 "number"
typeof (7)                 // 返回 "number"
typeof (7 + 8)             // 返回 "number"
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_typeof_number)

typeof 运算符对数组返回 "object"，因为在 JavaScript 中数组属于对象。

## Undefined

在 JavaScript 中，没有值的变量，其值是 undefined。typeof 也返回 undefined。

### 实例

```
var person;                  // 值是 undefined，类型是 undefined
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_undefined_1)

任何变量均可通过设置值为 undefined 进行清空。其类型也将是 undefined。

### 实例

```
person = undefined;          // 值是 undefined，类型是 undefined
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_undefined_2)

## 空值

空值与 undefined 不是一回事。

空的字符串变量既有值也有类型。

### 实例

```
var car = "";                // 值是 ""，类型是 "string"
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_empty)

## Null

在 JavaScript 中，null 是 "nothing"。它被看做不存在的事物。

不幸的是，在 JavaScript 中，null 的数据类型是对象。

您可以把 null 在 JavaScript 中是对象理解为一个 bug。它本应是 null。

您可以通过设置值为 null 清空对象：

### 实例

```
var person = null;           // 值是 null，但是类型仍然是对象
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_null)

您也可以通过设置值为 undefined 清空对象：

### 实例

```
var person = undefined;     // 值是 undefined，类型是 undefined
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_undefined_3)

## Undefined 与 Null 的区别

Undefined 与 null 的值相等，但类型不相等：

```
typeof undefined              // undefined
typeof null                   // object
null === undefined            // false
null == undefined             // true
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_undefined_4)

## 原始数据

原始数据值是一种没有额外属性和方法的单一简单数据值。

typeof 运算符可返回以下原始类型之一：

- string
- number
- boolean
- undefined

### 实例

```
typeof "Bill"              // 返回 "string"
typeof 3.14                // 返回 "number"
typeof true                // 返回 "boolean"
typeof false               // 返回 "boolean"
typeof x                   // 返回 "undefined" (假如 x 没有值)
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_typeof_primitive)

## 复杂数据

typeof 运算符可返回以下两种类型之一：

- function
- object

typeof 运算符把对象、数组或 null 返回 object。

typeof 运算符不会把函数返回 object。

### 实例

```
typeof {name:'Bill', age:62} // 返回 "object"
typeof [1,2,3,4]             // 返回 "object" (并非 "array"，参见下面的注释)
typeof null                  // 返回 "object"
typeof function myFunc(){}   // 返回 "function"
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_datatypes_typeof_complexdata)

typeof 运算符把数组返回为 "object"，因为在 JavaScript 中数组即对象。

# JavaScript this 关键词

- [JS 严格模式](https://www.w3school.com.cn/js/js_strict.asp)
- [JS Let](https://www.w3school.com.cn/js/js_let.asp)

## 实例

```
var person = {
  firstName: "Bill",
  lastName : "Gates",
  id       : 678,
  fullName : function() {
    return this.firstName + " " + this.lastName;
  }
};
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_this_method)

## this 是什么？

JavaScript this 关键词指的是它所属的对象。

它拥有不同的值，具体取决于它的使用位置：

- 在方法中，this 指的是所有者对象。
- 单独的情况下，this 指的是全局对象。
- 在函数中，this 指的是全局对象。
- 在函数中，严格模式下，this 是 undefined。
- 在事件中，this 指的是接收事件的元素。

像 call() 和 apply() 这样的方法可以将 this 引用到任何对象。

## 方法中的 this

在对象方法中，this 指的是此方法的“拥有者”。

在本页最上面的例子中，this 指的是 person 对象。

person 对象是 fullName 方法的拥有者。

```
fullName : function() {
  return this.firstName + " " + this.lastName;
}
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_this_method)

## 单独的 this

在单独使用时，拥有者是全局对象，因此 this 指的是全局对象。

在浏览器窗口中，全局对象是 [object Window]：

### 实例

```
var x = this;
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_this)

在严格模式中，如果单独使用，那么 this 指的是全局对象 [object Window]：

### 实例

```
"use strict";
var x = this;
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_this_alone)

## 函数中的 this（默认）

在 JavaScript 函数中，函数的拥有者默认绑定 this。

因此，在函数中，this 指的是全局对象 [object Window]。

### 实例

```
function myFunction() {
  return this;
}
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_this_function)

## 函数中的 this（严格模式）

JavaScript 严格模式不允许默认绑定。

因此，在函数中使用时，在严格模式下，this 是未定义的（undefined）。

### 实例

```
"use strict";
function myFunction() {
  return this;
}
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_this_strict)

## 事件处理程序中的 this

在 HTML 事件处理程序中，this 指的是接收此事件的 HTML 元素：

### 实例

```
<button onclick="this.style.display='none'">
  点击来删除我！
</button>
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_this_event)

## 对象方法绑定

在此例中，this 是 person 对象（person 对象是该函数的“拥有者”）：

### 实例

```
var person = {
  firstName  : "Bill",
  lastName   : "Gates",
  id         : 678,
  myFunction : function() {
    return this;
  }
};
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_this_object)

### 实例

```
var person = {
  firstName: "Bill",
  lastName : "Gates",
  id       : 678,
  fullName : function() {
    return this.firstName + " " + this.lastName;
  }
};
```

[亲自试一试](https://www.w3school.com.cn/tiy/t.asp?f=js_this_method)

换句话说，*this.firstName* 意味着 *this*（person）对象的 *firstName* 属性。

## 显式函数绑定

call() 和 apply() 方法是预定义的 JavaScript 方法。

它们都可以用于将另一个对象作为参数调用对象方法。

您可以在本教程后面阅读有关 call() 和 apply() 的更多内容。

在下面的例子中，当使用 person2 作为参数调用 person1.fullName 时，this 将引用 person2，即使它是 person1 的方法：

### 实例

```html
var person1 = {
  fullName: function() {
    return this.firstName + " " + this.lastName;
  }
}
var person2 = {
  firstName:"Bill",
  lastName: "Gates",
}
person1.fullName.call(person2);  // 会返回 "Bill Gates"
```

# JavaScript 能够做什么？

事件处理程序可用于处理、验证用户输入、用户动作和浏览器动作：

- 每当页面加载时应该做的事情
- h当页面被关闭时应该做的事情
- 当用户点击按钮时应该被执行的动作
- 当用户输入数据时应该被验证的内容
- 等等

让 JavaScript 处理事件的不同方法有很多：

- HTML 事件属性可执行 JavaScript 代码
- HTML 事件属性能够调用 JavaScript 函数
- 您能够向 HTML 元素分配自己的事件处理函数
- 您能够阻止事件被发送或被处理
- 等等

# ==与===

**=== 运算符需要类型和值同时相等才成立,而 == 运算符仅需要值相等就成立。**

代码如下：

``` html
<!DOCTYPE html>
<html>
<body>

<h1>绝不要把字符串创建为对象</h1>

<p>字符串与对象无法安全地比较。</p>

<p id="demo"></p>

<script>
var x = "Bill";              // x 是字符串
var y = new String("Bill");  // y 是对象
document.getElementById("demo").innerHTML = (x===y);
</script>

</body>
</html>

```

# 字符串方法和属性

原始值，比如“Bill Gates”，无法拥有属性和方法（因为它们不是对象）。

但是通过 JavaScript，方法和属性也可用于原始值，因为在执行方法和属性时 JavaScript 将原始值视为对象。
