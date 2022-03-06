## XMLHttpRequest 对象

XMLHttpRequest 对象用于在后台与服务器交换数据。

XMLHttpRequest 对象是**开发者的梦想**，因为您能够：

- 在不重新加载页面的情况下更新网页
- 在页面已加载后从服务器请求数据
- 在页面已加载后从服务器接收数据
- 在后台向服务器发送数据

如需学习更多关于 XMLHttpRequest 对象的知识，请学习我们的 [XML DOM 教程](https://www.runoob.com/dom/dom-tutorial.html)。

------

## XMLHttpRequest 实例

当你在下面的输入字段中键入一个字符，一个 XMLHttpRequest 发送到服务器 - 返回名称的建议（从服务器上的文件）：

在输入框中键入一个字母：首字母 建议:Eva , Eve , Evita , Elizabeth , Ellen



------

## 创建一个 XMLHttpRequest 对象

所有现代浏览器（IE7+、Firefox、Chrome、Safari 和 Opera）都有内建的 XMLHttpRequest 对象。

创建 XMLHttpRequest 对象的语法：

xmlhttp=new XMLHttpRequest();

旧版本的Internet Explorer（IE5和IE6）中使用 ActiveX 对象：

xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");

在下一章中，我们将使用 XMLHttpRequest 对象从服务器取回 XML 信息。