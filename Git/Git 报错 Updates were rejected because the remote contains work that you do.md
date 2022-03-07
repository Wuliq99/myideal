# Git 报错 Updates were rejected because the remote contains work that you do

### 报错信息

```shell
 ! [rejected]        master -> master (fetch first)
error: failed to push some refs to 'github.com:Wuliq99/myideal.git'
hint: Updates were rejected because the remote contains work that you do
hint: not have locally. This is usually caused by another repository pushing
hint: to the same ref. You may want to first integrate the remote changes
hint: (e.g., 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```

### 原因

​		本地库和GitHub中的库不同步

### 解决方法

方法一(不要轻易使用)

加上 `-f`，强制推送上去，这时你的GitHub上的库会以本地同步，

```shell
git push -f
```

方法二（推荐）

使用`git pull --rebase origin master`合并 GitHub 和 本地 的库，本地会多出之前不同步的文件，再使用 `git push -u origin master` 推送到 GitHub 库中。

```shell
git pull --rebase origin master
git push origin master
```