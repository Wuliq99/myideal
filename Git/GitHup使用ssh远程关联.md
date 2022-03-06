# GitHup使用ssh远程关联

## 密匙创建

1.首先在本地创建`ssh key；`

```shell
ssh-keygen -t rsa -C "your_email"
```

后面的`your_email`改为你在github上注册的邮箱，之后会要求确认路径和输入密码（密码可以不用输入，避免每次使用密匙都要输入密码），我们这使用默认的一路回车就行。成功的话会在`~/`下生成`.ssh`文件夹，进去，打开`id_rsa.pub`，复制里面的`key`。

完成之后，回到github上，进入 Settings，左边选择SSH Keys，Add SSH Key,title随便填，粘贴在你电脑上生成的key。

2.验证是否成功，在git bash下输入：

```shell
ssh -T git@github.com
```

如果是第一次的会提示是否continue，输入yes就会看到：You've successfully authenticated, but GitHub does not provide shell access 。这就表示已成功连上github。

## 将git与远程仓库连接

1.首先进行git相关信息的配置

```shell
git config --global user.name "your name"
git config --global user.email "your_email@youremail.com"
#	每次commit时GitHub都会记录上述信息
```

2.关联远程仓库，必须关联远程仓库才能将代码保存到远程服务器

进入要上传的仓库，右键git bash，添加远程地址：

```shell
git remote add origin 远程仓库地址
```

## 后记

### 1.git提交或克隆报错

报错信息：

> ```shell
> fatal: unable to access 'https://github.com/xxx/autowrite.git/': 
> OpenSSL SSL_read: Connection was reset, errno 10054
> ```
>
> 或者
>
> ```
> fatal: unable to access 'https://github.com/xxx/autowrite.git/':
> Failed to connect to github.com port 443: Timed out
问题分析

> 原因一
>
> > git在拉取或者提交项目时，中间会有git的http和https代理，但是我们本地环境本身就有SSL协议了，所以取消git的https代理即可，不行再取消http的代理。
>
> 原因二
>
> > 当前代理网速过慢，所以偶尔会成功，偶尔失败

解决方法

方案一

> 修改git配置，取消git本身的https代理，使用自己本机的代理，如果没有配置，使用git默认代理
>
> ```
> //取消http代理
> git config --global --unset http.proxy
> //取消https代理 
> git config --global --unset https.proxy
> ```

方案二

> 科学上网，从根本解决 time out 443
