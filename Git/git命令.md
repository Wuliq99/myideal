Git 的工作就是创建和保存你项目的快照及与之后的快照进行对比

Git 常用的是以下 6 个命令：**git clone**、**git push**、**git add** 、**git commit**、**git checkout**、**git pull**

### 用户信息

配置个人的用户名称和电子邮件地址：

```` shell
git config --global user.name "用户名"
````

``` shell
git config --global user.email "你的邮箱"
```

如果用了 **--global** 选项，那么更改的配置文件就是位于你用户主目录下的那个，以后你所有的项目都会默认使用这里配置的用户信息。

如果要在某个特定的项目中使用其他名字或者电邮，只要去掉 --global 选项重新配置即可，新的设定保存在当前项目的 .git/config 文件里。



### 文本编辑器

设置Git默认使用的文本编辑器, 一般可能会是 Vi 或者 Vim。如果你有其他偏好，比如 Emacs 的话，可以重新设置：

```shell
git config --global core.editor 文本编辑器名字
```

### 差异分析工具

还有一个比较常用的是，在解决合并冲突时使用哪种差异分析工具。比如要改用 vimdiff 的话：

```shell
git config --global merge.tool vimdiff
```

Git 可以理解 kdiff3，tkdiff，meld，xxdiff，emerge，vimdiff，gvimdiff，ecmerge，和 opendiff 等合并工具的输出信息。

### 查看配置信息

要检查已有的配置信息，可以使用 git config --list 命令

``` shell
git config --list #查看git配置
```

有时候会看到重复的变量名，那就说明它们来自不同的配置文件（比如 /etc/gitconfig 和 ~/.gitconfig），不过最终 Git 实际采用的是最后一个。

这些配置我们也可以在 **~/.gitconfig** 或 **/etc/gitconfig** 看到，如下所示：

```
vim ~/.gitconfig 
```

显示内容如下所示：

```
[http]
    postBuffer = 2M
[user]
    name = runoob
    email = test@runoob.com
```

也可以直接查阅某个环境变量的设定，只要把特定的名字跟在后面即可，像这样：

``` basic
git config user.name
```



```
git add *.c
git add README
git commit -m '初始化项目版本'
```

以上命令将目录下以 .c 结尾及 README 文件提交到仓库中。

> **注：** 在 Linux 系统中，commit 信息使用单引号 **'**，Windows 系统，commit 信息使用双引号 **"**。
>
> 所以在 git bash 中 **git commit -m '提交说明'** 这样是可以的，在 Windows 命令行中就要使用双引号 **git commit -m "提交说明"**。



#### git clone

我们使用 **git clone** 从现有 Git 仓库中拷贝项目（类似 **svn checkout**）。

克隆仓库的命令格式为：

```
git clone <repo>
```

如果我们需要克隆到指定的目录，可以使用以下命令格式：

```
git clone <repo> <directory>
```

**参数说明：**

- **repo:**Git 仓库。
- **directory:**本地目录。

比如，要克隆 Ruby 语言的 Git 代码仓库 Grit，可以用下面的命令：

```
git clone git://github.com/schacon/grit.git
```

执行该命令后，会在当前目录下创建一个名为grit的目录，其中包含一个 .git 的目录，用于保存下载下来的所有版本记录。

如果要自己定义要新建的项目目录名称，可以在上面的命令末尾指定新的名字：

```
git clone git://github.com/schacon/grit.git mygrit
```



## 配置

git 的设置使用 **git config** 命令。

显示当前的 git 配置信息：

```
$ git config --list
credential.helper=osxkeychain
core.repositoryformatversion=0
core.filemode=true
core.bare=false
core.logallrefupdates=true
core.ignorecase=true
core.precomposeunicode=true
```

编辑 git 配置文件:

```
git config -e    # 针对当前仓库 
```

或者：

```
git config -e --global   # 针对系统上所有仓库
```

设置提交代码时的用户信息：

```
git config --global user.name "runoob"
git config --global user.email test@runoob.com
```

如果去掉 **--global** 参数只对当前仓库有效。





查看分支：`git branch`

创建分支：`git branch <name>`

切换分支：`git checkout <name>`或者`git switch <name>`

创建+切换分支：`git checkout -b <name>`或者`git switch -c <name>`

合并某分支到当前分支：`git merge <name>`

删除分支：`git branch -d <name>`













## 常用命令

### 创建仓库

``` basic
git init	#将当前目录下将当前目录初始化为 git 仓库
```

``` basic
git clone		 #拷贝仓库
git clone /path/to/repository	#拷贝本地仓库
git clone username@host:/path/to/repository	#拷贝一份远程仓库，也就是下载一个项目
```

 ``` basic
 git help 命令名		#获取某个命令的帮助
 ```

### 提交与修改

``` basic
git status			#查看仓库当前的状态，显示有变更的文件
```

``` basic
git add 文件名    #添加跟踪文件
```

``` basic
git diff			#比较文件的不同，即暂存区和工作区的差异
```

``` basic
git commit -m "本次提交的说明"			#提交暂存区到本地仓库
```

``` basic
git rm		#删除工作区文件
```

``` basic
git reset		#回退版本
```

``` basic
git mv			#移动或重命名工作区文件
```

```basic
#将本地库的所有内容推送到远程仓库的master分支
git push -u origin master	
```



### 提交日志

``` basic
git log		#查看历史提交记录
```

``` basic
git blame		#以列表形式查看指定文件的历史修改记录
```

#### **git log和git reflog的区别**

1.Git log查询的是commit id，作者以及提交时间和提交信息，但是不包括之前删除的历史记录

2.git reflog查询的是简洁的commit id和提交信息，也会包含之前删除的历史记录

### 远程操作

```shell
git remote		#远程仓库操作
#关联一个远程库时必须给远程库指定一个名字，origin是默认习惯命名
git remote add origin git@github.com:michaelliao/learngit.git
```

``` shell
git fetch		#从远程获取代码库
```

``` shell
git pull		#下载远程代码并合并
```

``` shell
git push		#上传远程代码并合并
git push -u origin master #将改动提交到远程仓库（即提交到master分支）
```

### 分支操作

``` shell
git branch (branchname)		#创建分支.没有参数时，git branch 会列出你在本地的分支
```

``` shell
git checkout (branchname)		#切换分支
```

``` shell
git merge 		#合并分支
```

git标签

``` shell
git tag tagname branchID			#	git tag 1.0.0 1b2e1d63ff
```



a 选项意为"创建一个带注解的标签"。 不用 -a 选项也可以执行的，但它不会记录这标签是啥时候打的，谁打的，也不会让你添加个标签的注解。 我推荐一直创建带注解的标签

### 用户相关

```shell
git config --global --unset user.name 用户名		# 删除指定用户
```







## 实际场景

场景一

> 创建一个叫做 `feature_x` 的分支，并切换过去：
> `git checkout -b feature_x`
> 切换回主分支：
> `git checkout master`
> 再把新建的分支删掉：
> `git branch -d feature_x`
> 除非你将分支推送到远端仓库，不然该分支就是 *不为他人所见的*：
> `git push origin <branch>`

场景二

> 如果你想了解本地仓库的历史记录，最简单的命令就是使用:
> `git log`
> 你可以添加一些参数来修改他的输出，从而得到自己想要的结果。 只看某一个人的提交记录:
> `git log --author=bob`
> 一个压缩后的每一条提交记录只占一行的输出:
> `git log --pretty=oneline`
> 或者你想通过 ASCII 艺术的树形结构来展示所有的分支, 每个分支都标示了他的名字和标签:
> `git log --graph --oneline --decorate --all`
> 看看哪些文件改变了:
> `git log --name-status`
> 这些只是你可以使用的参数中很小的一部分。更多的信息，参考：
> `git log --help`

场景三

> 假如你操作失误（当然，这最好永远不要发生），你可以使用如下命令替换掉本地改动：
> `git checkout -- <filename>`
> 此命令会使用 HEAD 中的最新内容替换掉你的工作目录中的文件。已添加到暂存区的改动以及新文件都不会受到影响。
>
> 假如你想丢弃你在本地的所有改动与提交，可以到服务器上获取最新的版本历史，并将你本地主分支指向它：
> `git fetch origin`
> `git reset --hard origin/master`

场景四

> ​	 git init //把这个目录变成Git可以管理的仓库
>
> 　　git add README.md //文件添加到仓库
>
> 　　git add . //不但可以跟单一文件，还可以跟通配符，更可以跟目录。一个点就把当前目录下所有未追踪的文件全部add了 
>
> 　　git commit -m "first commit" //把文件提交到仓库,双引号内的内容是注释
>
> 　　git remote add origin git@github.com:wangjiax9/practice.git //关联远程仓库
>
> 　　git push -u origin master //把本地库的所有内容推送到远程库上

场景五

> 当你改乱了工作区某个文件的内容，想直接丢弃工作区的修改时，用命令`git checkout -- filename`

场景六

> 当你不但改乱了工作区某个文件的内容，还添加到了暂存区时，想丢弃修改，分两步，第一步用命令`git reset HEAD filename`，就回到了场景五，第二步按场景五操作。

场景七

> 已经提交了不合适的修改到版本库时，想要撤销本次提交，可以进行版本回退
>
> `git reset --hard 版本号`

场景八

> 当你不小心误删了工作区的文件时，使用命令`git checkout -- filename`进行恢复（只能恢复到最新版本）

场景九

> 修复bug时，我们会通过创建新的bug分支进行修复，然后合并，最后删除；
>
> 当手头工作没有完成时，先把工作现场`git stash`一下，然后去修复bug，修复后，再`git stash pop`，回到工作现场；
>
> 在master分支上修复的bug，想要合并到当前dev分支，可以用`git cherry-pick <commit>`命令，把bug提交的修改“复制”到当前分支，避免重复劳动。

## 实用小贴士

> ## 								实用小贴士
>
> 内建的图形化 git：
> `gitk`
> 彩色的 git 输出：
> `git config color.ui true`
> 显示历史记录时，每个提交的信息只显示一行：
> `git config format.pretty oneline`
> 交互式添加文件到暂存区：
> `git add -i`

**git是不能管理空的文件夹的，文件夹里必须有文件才能add**

推荐教程

> Github 简明教程：http://www.runoob.com/w3cnote/git-guide.html
>
> Github 简明指南：http://rogerdudler.github.io/git-guide/index.zh.html
>
> 如何高效利用GitHub:http://www.yangzhiping.com/tech/github.html
>
> GitHub 使用教程图文详解：http://www.linuxidc.com/Linux/2014-09/106230.htm
>
> git命令：https://www.cnblogs.com/rswl/p/8607747.html
