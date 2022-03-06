

# source

**source[命令](https://www.linuxcool.com/)是一个内置的[shell](https://www.linuxcool.com/)[命令](https://www.linuxcool.com/)，用于从当前shell会话中的文件读取和执行命令。source命令通常用于保留、更改当前shell中的环境变量。简而言之，source一个[脚本](https://www.linuxcool.com/)，将会在当前shell中运行execute命令。**

`source`命令可用于：

- 刷新当前的shell环境
- 在当前环境使用source执行Shell[脚本](https://www.linuxcool.com/)
- 从脚本中导入环境中一个Shell函数
- 从另一个Shell脚本中读取变量

**source命令的语法**

`source`命令它需要一个文件，如果提供了参数，那么将用作传递脚本的位置参数。

```
source FILENAME [ARGUMENTS]
```

也可以使用`.`替代`source`命令：

```
. FILENAME [ARGUMENTS]
```

**如何使用source命令**

**1. 刷新当前的shell环境**

可以在当前的shell环境中定义一个别名。为`ls -al`定义一个别名为`ll`：

```
[root@localhost ~]# echo "alias ll='ls -al'" >> ~/.bashrc 
```

在~/.bashrc文件中定义完别名，可以使用source命令刷新当前shell环境：

```
[root@localhost ~]# source ~/.bashrc 
```

现在可以使用`ll`别名列出当前目录里所有文件了，包括隐藏文件。
![Linux中source命令的使用方式Linux中source命令的使用方式](https://www.linuxprobe.com/wp-content/uploads/2021/03/image1-1.png)

**2. 在当前环境使用source执行Shell脚本**

Shell脚本不知道你在当前Shell环境中定义的变量。source命令可用于在当前会话中执行你的Shell脚本。

下面在定义一个变量：

```
[root@localhost ~]# website=https://www.linuxprobe.com
```

![Linux中source命令的使用方式Linux中source命令的使用方式](https://www.linuxprobe.com/wp-content/uploads/2021/03/image2-1.png)
创建一个脚本：

```
[root@localhost ~]# vim web.sh 

#!/bin/bash
echo $website
```

![Linux中source命令的使用方式Linux中source命令的使用方式](https://www.linuxprobe.com/wp-content/uploads/2021/03/image3-1.png)
使用`source`在当前shell会话中执行它：

```
[root@localhost ~]# source web.sh 
https://www.linuxprobe.com
```

![Linux中source命令的使用方式Linux中source命令的使用方式](https://www.linuxprobe.com/wp-content/uploads/2021/03/image4-1.png)
当使用sh运行脚本时，找不到环境中定义的变量：
![Linux中source命令的使用方式Linux中source命令的使用方式](https://www.linuxprobe.com/wp-content/uploads/2021/03/image5.png)

**3. 从脚本中导入环境中一个Shell函数**

首先创建一个脚本，定义一个函数：

```
[root@localhost ~]# vim func.sh

#!/bin/bash
foo(){
  echo "test function!"
}
```

![Linux中source命令的使用方式Linux中source命令的使用方式](https://www.linuxprobe.com/wp-content/uploads/2021/03/image6.png)
要在当前的shell会话中导入上述脚本的功能，使用下面命令：

```
[root@localhost ~]# source func.sh 
```

下面在终端中执行以下func.sh脚本中的`foo`函数试试：

```
[root@localhost ~]# foo
test function!
```

![Linux中source命令的使用方式Linux中source命令的使用方式](https://www.linuxprobe.com/wp-content/uploads/2021/03/image7.png)
source完脚本之后，可以看到在当前回话的终端中可以执行脚本里面的函数。

**4. 从另一个Shell脚本中读取变量**

首先创建带有一些变量的shell脚本，请输入：

```
[root@localhost ~]# vim var.sh

#!/bin/bash
a=1
b=2
c=3
```

![Linux中source命令的使用方式Linux中source命令的使用方式](https://www.linuxprobe.com/wp-content/uploads/2021/03/image8.png)
再创建一个脚本，该脚本读取上一个脚本`var.sh`中的变量：

```
[root@localhost ~]# vim read.sh 

#!/bin/bash
source ~/var.sh
echo $a
echo $b
echo $c
```

在脚本中首先使用source将`var.sh`中的变量到处到当前回话，然后echo显示变量值。下面执行`read.sh`看一下：
![Linux中source命令的使用方式Linux中source命令的使用方式](https://www.linuxprobe.com/wp-content/uploads/2021/03/image9.png)

**5. 读取并执行命令**

`source`命令可以从文件读取和执行命令。下面的一个文本文件中带有两个命令，使用source命令运行该文件，看看是否会执行里面的命令。

下面创建一个文件cmd.txt，保存两个命令：

```
[root@localhost ~]# cat cmd.txt 
ip ad
date
```

下面使用`source`执行这个文件：

```
[root@localhost ~]# source cmd.txt 
```

![Linux中source命令的使用方式Linux中source命令的使用方式](https://www.linuxprobe.com/wp-content/uploads/2021/03/image10.png)

**总结**

`source`命令在当前shell中执行脚本，而`exec`命令在新的shell中运行。

------

source命令（从 C Shell 而来）是bash shell的内置命令。点命令，就是个点符号，（从Bourne Shell而来）是source的另一名称。 source命令通常用于重新执行刚修改的初始化文件，使之立即生效，而不必注销并重新登录。

source返回文件最后一个命令的返回值，如果文件不能读取则会失败。

**语法格式：**source [文件]

**参考实例**

读取和执行/root/.bash_profile文件：

```
[root@linuxcool ~]# source ~/.bash_profile
```

执行刚修改的初始化文件，使之立即生效：

```
[root@linuxcool ~]# source /etc/bash_profile 
```

在一些工具的执行过程中，会把环境变量设置以”export XXX=XXXXXX”或”declare XXX=XXXXXX”的形式导出到 一个文件中，然后用source加载该文件内容到执行环境中:

```
[root@linuxcool ~]# vi /etc/profile 
[root@linuxcool ~]# source /etc/profile
```

如果把这些命令做成一个文件，让它自动顺序执行，对于需要多次反复编译系统核心的用户来说会很方便，而用source命令就可以做到这一点，它的作用就是把一个文件的内容当成shell来执行，先在linux的源代码目录下（如/usr/src/linux-2.4.20）建立一个文件，如 make_command，在其中输入一下内容：

make mrproper &&

make menuconfig &&

make dep &&

make clean &&

make bzImage &&

make modules &&

make modules_install &&

cp arch/i386/boot/bzImage /boot/vmlinuz_new &&

cp System.map /boot &&

vi /etc/lilo.conf &&

lilo -v

文件建立好之后，每次编译核心的时候，只需要在/usr/src/linux-2.4.20下输入：

```
[root@linuxcool ~]# source make_command
```



### 与该功能相关的Linux命令：

- [setenv命令 – 查询或显示环境变量](https://www.linuxcool.com/setenv)
- [bsdtar命令 – 读取和写入磁带存档文件](https://www.linuxcool.com/bsdtar)
- [xzgrep命令 – 在xz压缩文件上搜索正则表达式](https://www.linuxcool.com/xzgrep)
- [rpmbuild命令 – 创建软件包](https://www.linuxcool.com/rpmbuild)
- [blkid命令 – 显示关于可用块设备的信息](https://www.linuxcool.com/blkid)
- [hping3命令 – 测试网络及主机的安全](https://www.linuxcool.com/hping3)
- [manpath命令 – 查看man手册页的查询路径](https://www.linuxcool.com/manpath)
- [smbd命令 – Samba服务器程序](https://www.linuxcool.com/smbd)
- [alias命令 – 设置命令别名](https://www.linuxcool.com/alias)
- [traceroute命令 – 追踪数据包在网络上的传输时的全部路径](https://www.linuxcool.com/traceroute)