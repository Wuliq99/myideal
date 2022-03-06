> 以Windows10环境为例，介绍Anaconda的下载及使用



## Anaconda介绍



Anaconda指的是一个开源的[Python](https://baike.baidu.com/item/Python)发行版本，其包含了[conda](https://baike.baidu.com/item/conda/4500060)、Python等180多个科学包及其依赖项。因为包含了大量的科学包，Anaconda 的下载文件比较大（约 531 MB），如果只需要某些包，或者需要节省带宽或[存储空间](https://baike.baidu.com/item/存储空间/10657950)，也可以使用**Miniconda**这个较小的发行版（仅包含conda和 Python）

其内置：

- **Anaconda Navigtor** ：用于管理工具包和环境的图形用户界面，后续涉及的众多管理命令也可以在 Navigator 中手工实现。
- **Jupyter notebook** ：基于web的交互式计算环境，可以编辑易于人们阅读的文档，用于展示数据分析的过程。
- **qtconsole** ：一个可执行 IPython 的仿终端图形界面程序，相比 Python Shell 界面，qtconsole 可以直接显示代码生成的图形，实现多行代码输入执行，以及内置许多有用的功能和函数。
- **spyder** ：一个使用Python语言、跨平台的、科学运算集成开发环境。



## Anaconda下载地址

> https://www.anaconda.com/products/individual-d#Downloads



## 添加环境变量

为了能在 cmd 下运行 conda 命令，需要配置环境变量

在Path环境变量下添加如下内容

``` python
Anaconda安装目录
Anaconda安装目录\Scripts
Anaconda安装目录\Library\bin
```



## 更换源

安装需要的Python包非常方便，但是官方服务器在国外，下载太慢，因此我们可以换源

### 方法一

###### 添加国内清华镜像源

``` python
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/conda-forge 
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/msys2/
 
# 【添加完毕一定要设置一下】设置搜索时显示通道地址
conda config --set show_channel_urls yes
```

######  **添加中科大源**

``` python
conda config --add channels https://mirrors.ustc.edu.cn/anaconda/pkgs/main/
conda config --add channels https://mirrors.ustc.edu.cn/anaconda/pkgs/free/
conda config --add channels https://mirrors.ustc.edu.cn/anaconda/cloud/conda-forge/
conda config --add channels https://mirrors.ustc.edu.cn/anaconda/cloud/msys2/
conda config --add channels https://mirrors.ustc.edu.cn/anaconda/cloud/bioconda/
conda config --add channels https://mirrors.ustc.edu.cn/anaconda/cloud/menpo/
 
conda config --set show_channel_urls yes
```

###### **还原原始镜像**

``` python
conda config --remove-key channels
```

### 方法二

打开 .condarc 文件，直接在文件中更改，该文件的路径位于

``` python
C://users//user
```



## conda更新

下载后的conda，版本及自带的包可能比较老，因此我们可以对conda及相应的包进行更新

先更新conda

``` python
conda update conda
```

再更新第三方所有包

``` python
conda upgrade --all
```

## Anaconda使用

示例

``` python
# 创建一个名为python34的环境，指定Python版本是3.4（不用管是3.4.x，conda会为我们自动寻找3.4.x中的最新版本）
 
conda create --name python34 python=3.4
#或者conda create -n python34 python=3.4
 
# 安装好后，使用activate激活某个环境，也可以用于切换环境
 
activate python34 # for Windows
 
source activate python34 # for Linux & Mac
 
# 激活后，会发现terminal输入的地方多了python34的字样，实际上，此时系统做的事情就是把默认2.7环境从PATH中去除，再把3.4对应的命令加入PATH
 
# 此时，再次输入
 
python --version
 
# 可以得到`Python 3.4.5 :: Anaconda 4.1.1 (64-bit)`，即系统已经切换到了3.4的环境
 
# 如果想返回默认的python 2.7环境，运行
 
deactivate python34 # for Windows
source deactivate python34 # for Linux & Mac


#查看所有环境,下面两条命令都可以
conda env list
conda info --envs

#退出虚拟环境
conda deactivate

#复制虚拟环境
conda create --name new_env_name --clone copied_env_name

# 删除一个已有的环境
conda remove --name python34 --all
```

总结

> activate // 切换到base环境
>
> activate learn // 切换到learn环境
>
> conda create -n learn python=3 // 创建一个名为learn的环境并指定python版本为3(的最新版本)
>
> conda env list // 列出conda管理的所有环境
>
> conda list // 列出当前环境的所有包
>
> conda install requests 安装requests包
>
> conda remove requests 卸载requets包
>
> conda remove -n learn --all // 删除learn环境及下属所有包
>
> conda update requests 更新requests包
>
> conda env export > environment.yaml // 导出当前环境的包信息
>
> conda env create -f environment.yaml // 用配置文件创建新的虚拟环境



参考

https://www.cnblogs.com/yanghongtao/p/10928218.html