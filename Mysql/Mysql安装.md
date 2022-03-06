Mysql-8.0.26压缩包安装

## 安装环境

> Windows10专业版

重要的事情说三遍：

> 管理员模式下运行！！！
>
> 管理员模式下运行！！！
>
> 管理员模式下运行！！！

## 安装步骤

1.配置环境变量

将解压后的Mysql的bin目录添加到Path环境变量中（环境变量还不会配的请自行百度）

2.在解压后的 MySQL 的 bin 目录下新建配置文件 my.ini（该文件实际为txt文件），内容如下

``` c
[mysqld]
basedir=D:\mysql-8.0.26-winx64\mysql-8.0.26-winx64\
datadir=D:\mysql-8.0.26-winx64\mysql-8.0.26-winx64\data\
port=3306
#配置完后注释掉，注释方法：在前面加 #
skip-grant-tables
```

3.进入 cmd 模式，顺序输入如下配置命令

先进入Mysql的bin目录

``` c
cd /d Mysql的bin目录
```



进入后输入如下命令，安装Mysql

``` c
mysqld --install
```



再输入如下命令，初始化数据文件（可能会等待一段时间）

``` c
mysqld --initialize-insecure --user=mysql
```



然后输入如下命令，启动Mysql

``` c
net start mysql
```



然后输入如下命令，进入Mysql (**p 后无空格**)

``` c
mysql -u root -p
```



然后输入如下命令，修改密码

```c
 ALTER USER 'root'@'localhost' IDENTIFIED BY '123456';
```



然后输入如下命令，刷新权限

``` c
flush privileges;
```



最后进入 my.ini 修改内容，注释掉跳过密码部分



## 后记

如果安装过程中出现异常，运行如下命令后再重新按上面的步骤执行

``` c
sc delete mysql  清空服务
```

可能出现以下情况

![image-20220102202318709](C:\Users\QingTian\AppData\Roaming\Typora\typora-user-images\image-20220102202318709.png)

解决方案
访问https://cn.dll-files.com/vcruntime140_1.dll.html，下载VCRUNTIME140_1.DLL最新的版本

下载后将此文件直接放入MySQL的bin子目录下即可

## 日常指令

``` c
exit 退出Mysql
net stop mysql  停止Mysql
net start mysql		启动MySQL服务
```

