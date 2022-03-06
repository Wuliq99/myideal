## 关键字 + stars

``` c
1.大于等于
  语法： 关键字 stars:>= 数量 forks:>=数量 
  例子： springboot stars:>=5000 //搜索springboot有关star数>=5000的内容
        springboot stars:>=5000 forks:>=5000//搜索springboot 的star>=5000，且fork数>=5000的内容
    可单独搜索，也可组合搜索，中间用空格隔开，是&（且）的关系。

```

``` c
2.范围查询
  语法： 关键字 stars:范围1..范围2
  例子： springboot stars:4000..5000 
    //搜索star数在 4000到500的springboot相关内容，..相当于mysql中between and 的作用。
```

## 关键字 + in

搜索关键字在github上发布的位置 ，主要以下3个位置

- name （发布的仓库名称）
- description（指的是文章的摘要部分）
- Readme (说明文档)

``` c
语法 ：关键字 in:
例子 ：netty in:name //查找名称中包含netty的内容
      netty in:name,description
      //逗号分隔，是 || (或)的关系，指的是查询名称，或者描述中包含netty的内容
```

## awesome + 关键字

一般是指的学习，书籍，工具类，插件类相关的系列的集合。可以有效节约时间，找到别人收集好的内容。

awesome 指的是了不起的，碉堡了。

``` c
github 官方解释：
An awesome list is a list of awesome things curated by the community.
大致意思：社区组织维护的一系列非常棒的东西的集合。（差不多吧，哈哈，水平有限，谷歌翻译了解一下）
```

## user

查询某位用户的相关内容，比如某位大佬

``` c
语法：user:名称

user:ityouknow
```

## 搜索人物

``` c
location:Beijing language:java 
查找在北京，使用语言是java的人
```

##  实现某行，某块代码高亮

在与其他人协作开发时，沟通时在给别人指出某行，或者某块代码，可以在github链接后面加上

``` c
1.#L23  //某行高亮
如：
https://github.com/unofficial-openjdk/openjdk/blob/jdk/jdk/test/jdk/sun/misc/GetSunMiscUnsafe.java#L36
```

``` c
2.#L23-35  //某个代码块
如：
https://github.com/unofficial-openjdk/openjdk/blob/jdk/jdk/test/jdk/sun/misc/GetSunMiscUnsafe.java#L36-L40
```

## 常用快捷键

在github上 按 ？可调出快捷键页面，查看所有快捷键

在github 学习某个框架时，如果包的结构层级特别多，嫌一层层点进去麻烦，用 t ，该框架所有的类以列表形式平铺展开，方便查看

在github上 按 s 键，帮助快速聚焦在搜索框里，提高效率
