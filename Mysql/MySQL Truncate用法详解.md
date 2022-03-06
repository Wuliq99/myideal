# MySQL Truncate用法详解

2021-10-11 09:24:05分类：[编程](https://www.html.cn/softprog/) / [数据库](https://www.html.cn/softprog/database/)阅读(9105)评论(0)

> 这篇文章主要介绍了MySQL Truncate用法的相关资料，帮助大家更好的理解和使用MySQL，感兴趣的朋友可以了解下



##### 目录

- [MySQL Truncate用法](https://www.html.cn/softprog/database/181324.html#_label0)

- - [一、Truncate语法](https://www.html.cn/softprog/database/181324.html#_lab2_0_0)
    - [二、Truncate使用注意事项](https://www.html.cn/softprog/database/181324.html#_lab2_0_1)
    - [三、不能对以下表使用 TRUNCATE TABLE
        ](https://www.html.cn/softprog/database/181324.html#_lab2_0_2)
    - [四、TRUNCATE、Drop、Delete区别](https://www.html.cn/softprog/database/181324.html#_lab2_0_3)

- [MYSQL中TRUNCATE和DELETE的区别](https://www.html.cn/softprog/database/181324.html#_label1)

- - [1. 条件删除](https://www.html.cn/softprog/database/181324.html#_lab2_1_4)
    - [2. 事务回滚](https://www.html.cn/softprog/database/181324.html#_lab2_1_5)
    - [3. 清理速度
        ](https://www.html.cn/softprog/database/181324.html#_lab2_1_6)
    - [4. 高水位重置](https://www.html.cn/softprog/database/181324.html#_lab2_1_7)

- [MySQL Truncate用法补充](https://www.html.cn/softprog/database/181324.html#_label2)

- - [1.truncate使用语法](https://www.html.cn/softprog/database/181324.html#_lab2_2_8)
    - [2.truncate与drop,delete的对比](https://www.html.cn/softprog/database/181324.html#_lab2_2_9)
    - [3.truncate使用场景及注意事项](https://www.html.cn/softprog/database/181324.html#_lab2_2_10)

删除表中的数据的方法有delete,truncate, 其中TRUNCATE TABLE用于删除表中的所有行，而不记录单个行删除操作。TRUNCATE TABLE 与没有 WHERE 子句的 DELETE 语句类似；但是，TRUNCATE TABLE 速度更快，使用的系统资源和事务日志资源更少。下面介绍SQL中Truncate的用法

当你不再需要该表时， 用 drop；当你仍要保留该表，但要删除所有记录时， 用 truncate；当你要删除部分记录时（always with a WHERE clause), 用 delete.

Truncate是一个能够快速清空资料表内所有资料的SQL语法。并且能针对具有自动递增值的字段，做计数重置归零重新计算的作用。



## MySQL Truncate用法



### 一、Truncate语法

[ { database_name.[ schema_name ]. | schema_name . } ]
table_name
[ ; ]

参数

database_name
数据库的名称。

schema_name
表所属架构的名称。

table_name
要截断的表的名称，或要删除其全部行的表的名称。



### 二、Truncate使用注意事项

1、TRUNCATE TABLE 在功能上与不带 WHERE 子句的 DELETE 语句相同：二者均删除表中的全部行。但 TRUNCATE TABLE 比 DELETE 速度快，且使用的系统和事务日志资源少。

2、DELETE 语句每次删除一行，并在事务日志中为所删除的每行记录一项。TRUNCATE TABLE 通过释放存储表数据所用的数据页来删除数据，并且只在事务日志中记录页的释放。

3、TRUNCATE TABLE 删除表中的所有行，但表结构及其列、约束、索引等保持不变。新行标识所用的计数值重置为该列的种子。如果想保留标识计数值，请改用 DELETE。如果要删除表定义及其数据，请使用 DROP TABLE 语句。

4、对于由 FOREIGN KEY 约束引用的表，不能使用 TRUNCATE TABLE，而应使用不带 WHERE 子句的 DELETE 语句。由于 TRUNCATE TABLE 不记录在日志中，所以它不能激活触发器。

5、TRUNCATE TABLE 不能用于参与了索引视图的表。

6、对用TRUNCATE TABLE删除数据的表上增加数据时，要使用UPDATE STATISTICS来维护索引信息。

7、如果有ROLLBACK语句，DELETE操作将被撤销，但TRUNCATE不会撤销。



### 三、不能对以下表使用 TRUNCATE TABLE 

1、由 FOREIGN KEY 约束引用的表。（您可以截断具有引用自身的外键的表。）

2、参与索引视图的表。

3、通过使用事务复制或合并复制发布的表。

4、对于具有以上一个或多个特征的表，请使用 DELETE 语句。

5、TRUNCATE TABLE 不能激活触发器，因为该操作不记录各个行删除。



### 四、TRUNCATE、Drop、Delete区别

1.drop和delete只是删除表的数据(定义),drop语句将删除表的结构、被依赖的约束(constrain)、触发器 (trigger)、索引(index);依赖于该表的存储过程/函数将保留,但是变为invalid状态。
2.delete语句是DML语言,这个操作会放在rollback segement中,事物提交后才生效;如果有相应的触发器(trigger),执行的时候将被触发。truncate、drop是DDL语言,操作后即 生效,原数据不会放到rollback中,不能回滚,操作不会触发trigger。

3.delete语句不影响表所占用的extent、高水线(high watermark)保持原位置不动。drop语句将表所占用的空间全部释放。truncate语句缺省情况下将空间释放到minextents的 extent,除非使用reuse storage。truncate会将高水线复位(回到最初)。

4.效率方面:drop > truncate > delete

5.安全性:小心使用drop与truncate,尤其是在 没有备份的时候,想删除部分数据可使用delete需要带上where子句,回滚段要足够大,想删除表可以用drop,想保留表只是想删除表的所有数据、 如果跟事物无关可以使用truncate,如果和事物有关、又或者想触发 trigger,还是用delete,如果是整理表内部的碎片，可以用truncate跟上reuse stroage，再重新导入、插入数据。

6.delete是DML语句,不会自动提交。drop/truncate都是DDL语句,执行后会自动提交。

7、drop一般用于删除整体性数据 如表，模式，索引，视图，完整性限制等；delete用于删除局部性数据 如表中的某一元组

8、DROP把表结构都删了；DELETE只是把数据清掉

9、当你不再需要该表时， 用 drop；当你仍要保留该表，但要删除所有记录时， 用 truncate；当你要删除部分记录时（always with a WHERE clause), 用 delete.



## MYSQL中TRUNCATE和DELETE的区别

MYSQL中TRUNCATE和DELETE都能够清理表中的数据，但是他们有什么区别呢？我们从下面的几点来分析：

![img](https://ss.html.cn/article/4c/99/0d/4c990dc1c41aaafe5850756b539a3483.jpg-600)



### 1. 条件删除

这个比较好理解，因为DELETE是可以带WHERE的，所以支持条件删除；而TRUNCATE只能删除整个表。

```
 # delete - 条件删除 DELETE FROM student WHERE id = 1; # delete - 删除整个表的数据 DELETE FROM student; # truncate - 删除整个表的数据 TRUNCATE TABLE student;
```



### 2. 事务回滚

由于DELETE是数据操作语言（DML - Data Manipulation Language），操作时原数据会被放到 rollback segment中，可以被回滚；而TRUNCATE是数据定义语言（DDL - Data Definition Language)，操作时不会进行存储，不能进行回滚。

![img](https://ss.html.cn/article/fd/dc/14/fddc14bfdfd74e7d09c822d0152a24fa.jpg-600)

可以看到DELETE是可以回滚成功的。

![img](https://ss.html.cn/article/19/4f/8e/194f8e7a74e93f997f6441f21651776b.jpg-600)

可以看到TRUNCATE是不能回滚成功的。



### 3. 清理速度 

在数据量比较小的情况下，DELETE和TRUNCATE的清理速度差别不是很大。但是数据量很大的时候就能看出区别。由于第二项中说的，TRUNCATE不需要支持回滚，所以使用的系统和事务日志资源少。DELETE 语句每次删除一行，并在事务日志中为所删除的每行记录一项，固然会慢，但是相对来说也较安全。



### 4. 高水位重置

随着不断地进行表记录的DML操作，会不断提高表的高水位线（HWM），DELETE操作之后虽然表的数据删除了，但是并没有降低表的高水位，随着DML操作数据库容量也只会上升，不会下降。所以如果使用DELETE，就算将表中的数据减少了很多，在查询时还是很和DELETE操作前速度一样。
而TRUNCATE操作会重置高水位线，数据库容量也会被重置，之后再进行DML操作速度也会有提升。



## MySQL Truncate用法补充

前言：

当我们想要清空某张表时，往往会使用truncate语句。大多时候我们只关心能否满足需求，而不去想这类语句的使用场景及注意事项。本篇文章主要介绍truncate语句的使用方法及注意事项。



### 1.truncate使用语法

truncate的作用是清空表或者说是截断表，只能作用于表。truncate的语法很简单，后面直接跟表名即可.

例如：`truncate table tbl_name` 或者 `truncate tbl_name `。

执行truncate语句需要拥有表的drop权限，从逻辑上讲，truncate table类似于delete删除所有行的语句或drop table然后再create table语句的组合。为了实现高性能，它绕过了删除数据的DML方法，因此，它不能回滚。尽管truncate table与delete相似，但它被分类为DDL语句而不是DML语句。



### 2.truncate与drop,delete的对比

上面说过truncate与delete，drop很相似，其实这三者还是与很大的不同的，下面简单对比下三者的异同。

- truncate与drop是DDL语句，执行后无法回滚；delete是DML语句，可回滚。
- truncate只能作用于表；delete，drop可作用于表、视图等。
- truncate会清空表中的所有行，但表结构及其约束、索引等保持不变；drop会删除表的结构及其所依赖的约束、索引等。
- truncate会重置表的自增值；delete不会。
- truncate不会激活与表有关的删除触发器；delete可以。
- truncate后会使表和索引所占用的空间会恢复到初始大小；delete操作不会减少表或索引所占用的空间，drop语句将表所占用的空间全释放掉。



### 3.truncate使用场景及注意事项

通过前面介绍，我们很容易得出truncate语句的使用场景，即该表数据完全不需要时可以用truncate。如果想删除部分数据用delete，注意带上where子句；如果想删除表，当然用drop；如果想保留表而将所有数据删除且和事务无关，用truncate即可；如果和事务有关，或者想触发trigger，还是用delete；如果是整理表内部的碎片，可以用truncate然后再重新插入数据。

无论怎样，truncate表都是高危操作，特别是在生产环境要更加小心，下面列出几点注意事项，希望大家使用时可以做下参考。

- truncate无法通过binlog回滚。
- truncate会清空所有数据且执行速度很快。
- truncate不能对有外键约束引用的表使用。
- 执行truncate需要drop权限，不建议给账号drop权限。
- 执行truncate前一定要再三检查确认，最好提前备份下表数据。



以上就是MySQL Truncate用法详解的详细内容，更多请关注html中文网其它相关文章！