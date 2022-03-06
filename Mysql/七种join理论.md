七种join理论



**建表语句：**

``` mysql
CREATE TABLE tbl_dep(id INT(11) NOT NULL AUTO_INCREMENT,
deptName VARCHAR(22) DEFAULT NULL,
addr VARCHAR(22) DEFAULT NULL,
PRIMARY KEY(id)
)ENGINE = INNODB DEFAULT CHARSET=utf8;

CREATE TABLE tbl_emp(
`id` INT(11) NOT NULL AUTO_INCREMENT,
`name` VARCHAR(22) DEFAULT NULL,
`deptId` VARCHAR(22) DEFAULT NULL,
PRIMARY KEY (`id`),
#constraint `fk_deptId` foreign key (`deptId`) references tbl_dep(id);
)engine=innodb default charset =utf8;
```

七种join理论
内连接(两表的共有部分)
SELECT * FROM tbl_dep d INNER JOIN tbl_emp e ON d.id=e.deptId;

左连接（左表的全部，右表不满足补NULL）
SELECT * FROM tbl_dep d LEFT JOIN tbl_emp e ON d.id=e.deptId;

右连接（右表的全部，左表不满足的补NULL）
SELECT * FROM tbl_dep d RIGHT JOIN tbl_emp e ON d.id=e.deptId;

特殊的左连接，（显示为左表的独有的数据）
说明：查询tbl_dep 表中跟tbl_emp 表无关联关系的数据，即tbl_dep 独占，且tbl_emp 表的显示列补NULL；
SELECT * FROM tbl_dep d LEFT JOIN tbl_emp e ON d.id=e.deptId WHERE e.deptId IS NULL;

特殊的右连接（显示为右表的独有的数据 ）
说明：查询tbl_emp 表中跟tbl_dep 表无关联关系的数据，即tbl_emp 独占，且tbl_dep 表的显示列补NULL；
SELECT * FROM tbl_dep d RIGHT JOIN tbl_emp e ON d.id=e.deptId WHERE d.id IS NULL;

全连接（显示全部数据）（mysql 不支持 full outer join）
UNION ：有去重的功能。
SELECT * FROM tbl_dep d LEFT JOIN tbl_emp e ON d.id=e.deptId UNION
SELECT * FROM tbl_dep d RIGHT JOIN tbl_emp e ON d.id=e.deptId;

显示两表的独有的数据
SELECT * FROM tbl_dep d LEFT JOIN tbl_emp e ON d.id=e.deptId WHERE e.deptId IS NULL UNION
SELECT * FROM tbl_dep d RIGHT JOIN tbl_emp e ON d.id=e.deptId WHERE d.id IS NULL;



------

## JOIN的使用

### JOIN 理论

![img](https://filescdn.proginn.com/0e1656225977919363e704c662c92332/d93202aac70388f4f8ab66caecd63c7c.webp)

### MySQL 七种 JOIN 的 SQL 编写

#### 环境搭建

```
# 创建部门表
CREATE TABLE tbl_dept (
  id INT NOT NULL AUTO_INCREMENT,
  deptName VARCHAR (30) DEFAULT NULL,
  locAdd VARCHAR (40) DEFAULT NULL,
  PRIMARY KEY (id)
) ENGINE = INNODB AUTO_INCREMENT = 1 DEFAULT chharset = utf8 ;

# 创建员工表
CREATE TABLE tbl_emp (
  id INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR (20) DEFAULT NULL,
  deptId INT (11) DEFAULT NULL,
  PRIMARY KEY (id),
  KEY fk_dept_id (deptId) CONSTRAINT fk_dept_id FORREIGN KEY (deptId) REFERENCES tbl_dept (id)
) ENGINE = INNODB AUTO_INCREMENT = 1 DEFAULT CHARSET = uttf8 ;

# 插入部门信息
INSERT INTO tbl_dept(deptName,locAdd) VALUES('RD',11),('HR',12),('MK',13),('MIS',14),('FD',15);

# 插入员工信息
INSERT INTO tbl_emp(`name`,deptId) VALUES('z3',1),('z4',1),('z5',1),('w5',2),('w6',2),('s7',3),('s8',4),('s9',51);
```

#### 1.内连接（INNER JOIN）

##### 语句

```
SELECT * FROM tbl_dept a INNER JOIN tbl_emp b ON a.id = b.deptId;
```

##### 有图有真相

![img](https://filescdn.proginn.com/98f6bef29ec6a2a4c3f775d3a88a14de/5a6314df8953585daa01d801c8cb3940.webp)

##### 理解

- 可以理解为两个集合的交集

#### 2.左(外)连接（LEFT JOIN）

##### 语句

```
SELECT * FROM tbl_dept a LEFT JOIN tbl_emp b ON a.id = b.deptId;
```

##### 有图有真相

![img](https://filescdn.proginn.com/6c4b3419aba51e4b9dac5d366babfc2a/a89ae5357033c21872d8e32238caa291.webp)

##### 理解

- `LEFT JOIN` 返回左表的全部行和右表满足 `ON` 条件的行，如果左表的行在右表中没有匹配，那么这一行右表中对应数据用 `NULL` 代替

#### 3.右(外)连接（RIGHT JOIN）

##### 语句

```
SELECT * FROM tbl_dept a RIGHT JOIN tbl_emp b ON a.id = b.deptId;
```

##### 有图有真相

![img](https://filescdn.proginn.com/6c77e609d7cd4bdb126f26ccffcfdf10/5de55eb1a900b756258cbfd44ea5b787.webp)

##### 理解

- `RIGHT JOIN` 返回右表的全部行和左表满足 `ON` 条件的行，如果右表的行在左表中没有匹配，那么这一行左表中对应数据用 `NULL` 代替。

#### 4.左表独有

##### 语句

```
SELECT * FROM tbl_dept a LEFT JOIN tbl_emp b ON a.id = b.deptId WHERE b.deptId IS NULL;
```

##### 有图有真相

![img](https://filescdn.proginn.com/2fafb6b5ff26d8422e93d5c0cdc9f3bc/385397ac2450e948bf93de5c0998d494.webp)

##### 理解

- 查询左表独有的数据 (注意：左表独有，右表 key 为空)

#### 5.右表独有

##### 语句

```
SELECT * FROM tbl_dept a RIGHT JOIN tbl_emp b ON a.id = b.deptId WHERE a.id IS NULL;
```

##### 有图有真相

![img](https://filescdn.proginn.com/0c17e66bebeb555f66e83146ee311bfb/36ed501f769584586737a7ecd8f36baa.webp)

##### 理解

- 查询右表独有的数据 (注意：右表独有，左表 key 为空)

#### 6.全连接

##### 语句

```
SELECT * FROM tbl_dept a LEFT JOIN tbl_emp b ON a.id = b.deptId 
UNION
SELECT * FROM tbl_dept a RIGHT JOIN tbl_emp b ON a.id = b.deptId;
```

##### 有图有真相

![img](https://filescdn.proginn.com/677210d5ea1eb67dec44f7c14b7056da/1a11a1d405b59c3903ddd818c33909b2.webp)

##### 理解

- 在 `mysql` 中不支持 `FULL JOIN` 进行全连接，可以用 一个左连接 `UNION` 一个右连接

#### 7.左右表独有

##### 语句

```
SELECT * FROM tbl_dept a LEFT JOIN tbl_emp b ON a.id=b.deptId WHERE b.deptId IS NULL
UNION
SELECT * FROM tbl_dept a RIGHT JOIN tbl_emp b ON a.id=b.deptId WHERE a.id IS NULL;
```

##### 有图有真相

![img](https://filescdn.proginn.com/284661a896e0724d798f3e9679aee2c8/5262b55df9bcb82ef6e754157f8e30cd.webp)

##### 理解

- 左右表独有 = 左表独有 + 右表独有

    