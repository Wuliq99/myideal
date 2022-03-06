## 安装环境

> Windows10专业版
>

## maven下载地址

> http://maven.apache.org
>

## 环境变量配置

1.在系统变量下新建 MAVEN_HOME，其值为maven的保存路径,举例如下

``` shell
D:\apache-maven-3.8.3		我电脑的maven保存路径
```

2.在系统Path环境变量里添加

``` shell
%MAVEN_HOME%\bin
```

3.在系统变量下新建 M2_HOME，其值如下,举例如下

```shell
D:\apache-maven-3.8.3\bin		我电脑的maven保存路径
```

4.保存退出，在cmd命令下输入下列命令后，显示版本号则maven安装成功

``` shell
mvn -version
```

## 配置settings文件

### 修改 `jar` 包保存的位置

在如下可以找到settings文件

```shell
D:\apache-maven-3.8.3\conf
```

找到第52行，这里是maven默认的仓库


我们复制第53行

```xml
<localRepository>/path/to/local/repo</localRepository>
```


将它拿到注释外并将中间的内容改成你需要的路径，

```xml
<localRepository>F:/repository</localRepository>
```

这里的路径随便设置，注意这里是正斜杠

### 修改下载源

因为国外的服务器下载jar包很慢所以我们改为阿里云服务器（大约在150行左右），这两个仓库只用选一个

```xml
 <!-- 阿里云仓库 -->
<mirror>
    <id>alimaven</id>
    <mirrorOf>central</mirrorOf>
    <name>aliyun maven</name>
    <url>http://maven.aliyun.com/nexus/content/repositories/central/</url>
</mirror>
     或者
<mirror>
    <id>nexus-aliyun</id>
    <mirrorOf>central</mirrorOf>
    <name>Nexus aliyun</name>
    <url>http://maven.aliyun.com/nexus/content/groups/public</url>
</mirror>
```

### jdk配置

配置jdk，也要夹在两个profiles标签之间(我这里使用的为jdk8)

```xml
<!-- java版本 --> 
<profile>
    <id>jdk-1.8</id>
    <activation>
        <activeByDefault>true</activeByDefault>
        <jdk>1.8</jdk>
    </activation>
    <properties>
        <maven.compiler.source>1.8</maven.compiler.source>
        <maven.compiler.target>1.8</maven.compiler.target>
        <maven.compiler.compilerVersion>1.8</maven.compiler.compilerVersion>
    </properties>
</profile>
```

## 测试

​		配置完成，在命令行输入mvn help:system测试，看到下载链接里面是ailiyun的链接表示配置成功

