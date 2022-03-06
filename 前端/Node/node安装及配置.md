

## 官网下载地址	

> https://nodejs.org/zh-cn/download/

## 常用命令

> - npm -v：查看npm安装的版本。
> - npm init：会引导你建立一个package.json文件，包括名称、版本、作者等信息。
> - npm list：查看当前目录下已安装的node包。
> - npm ls：查看当前目录下已安装的node包。
> - npm install moduleNames：安装Node模块到本地目录node_modules下。
> - npm install < name > -g：将包安装到全局环境中。
> - npm install < name > --save：安装的同时，将信息写入package.json中，项目路径中若是有package.json文件时，直接使用npm install方法就能够根据dependencies配置安装全部的依赖包，这样代码提交到git时，就不用提交node_modules这个文件夹了。
> - npm install < name> --save-dev：安装的同时，将信息写入package.json中项目路径中若是有package.json文件时，直接使用npm install方法就能够根据devDependencies配置安装全部的依赖包，这样代码提交到git时，就不用提交node_modules这个文件夹了
> - npm uninstall moudleName：卸载node模块

## 环境配置

##### 配置模块存放路径

原因

当我们执行 npm install express [-g] （后面的可选参数-g，g代表global全局安装的意思）语句时，会将安装的模块安装到`C:\Users\用户名\AppData\Roaming\npm\node_modules` 路径中，这样会占用占C盘空间，导致C盘使用空间越来越大。

解决方法

1.在node.js的安装路径下新建两个文件夹`node_global`和`node_cache`

2.执行以下语句

```
npm config set prefix "D:\nodejs\node_global"
npm config set cache "D:\nodejs\node_cache"
```

3.进入环境变量对话框，在【系统变量】下新建【NODE_PATH】，输入`node安装路径\node_global\node_modules`，将【用户变量】下的【Path】中的`C:\Users\用户名\AppData\Roaming\npm`修改为`node安装路径\node_global`

##### 更换下载源

方法一

​		使用淘宝镜像`[淘宝 NPM 镜像](https://npmmirror.com/)`

方法二

​		更换下载源，这里使用阿里国内镜像

```
npm config set registry https://registry.npm.taobao.org
```



## 后记

> .msi和.zip格式区别：
>
> .msi是Windows installer开发出来的程序安装文件，它可以让你安装，修改，卸载你所安装的程序。说白了.msi就是Windows installer的数据包，把所有和安装文件相关的内容封装在一个包里。此外：它还包含有关安装过程自己的信息。例如：安装序列、目标文件夹路径、安装选项和控制安装过程的属性。
> .zip是一个压缩包，解压之后即可，不需要安装