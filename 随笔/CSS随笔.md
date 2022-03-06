# CSS随笔

### CSS实际上是修饰网页的外观

总结一句话：HTML用于控制网页的结构，CSS用于控制网页的外观，JavaScript用于控制网页的行为。

#### 1.CSS的引入方式

##### 1.1 外部样式表

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		
		
		<!-- href 中填写 CSS 的路径 -->
		<link rel="stylesheet" type="text/css" href=""/>
		
		
	</head>
	<body>
	</body>
</html>

```

#### 1.2 内部样式表

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		
		<!--直接在 style 标签内编写-->
		<style type="text/css">
			/* 这里写CSS代码 */
		</style>
		
	</head>
	<body>
		
	</body>
</html>

```

#### 1.3 行内样式表

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		
	</head>
	<body>
		
		<!-- 直接写在标签中 -->
		<div style="color: #FFFF00;">这是CSS修饰后的文本</div>
		
	</body>
</html>

```

### 2.CSS的常用标签
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/f78809d2664a9d5939c0c92bde4eddd6.png#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/8bd9eaa2c5f82c55af8d69b034655bb3.png#pic_center)