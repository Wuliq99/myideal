## 一 创建虚拟Python虚拟环境

**Python的虚拟环境管理工具有很多，我使用的是virtualenv。**

**如果安装了anaconda ，其也能方便的创建和管理虚拟环境，具体使用方法自行搜索了解**

1. 安装virtualenv

    ```Linux
    pip install virtualenv
    11
    ```

2. 创建虚拟环境

    ```Linux
    # virtualenv 虚拟环境名称
    virtualenv venv
    
    # 不出意外的话，系统Python环境已经被你安装了很多包
    # 如果不想使用系统的包,加上–no-site-packeages参数
    virtualenv  --no-site-packages 创建路径名
    123456123456
    ```

3. 启动虚拟环境

    > Linux

    ```Linux
    $ cd venv
    $ source ./bin/activate
    1212
    ```

    > Windows 10

    ```Windows
    > cd venv
    > .\Scripts\activate.bat
    1212
    ```

4. 退出虚拟环境

    > Linux

    ```Linux
    $ deactivate
    11
    ```

    > Windows 10

    ```Windows
    > .\Scripts\deactivate.bat
    11
    ```

5. 删除虚拟环境

    > 环境未启用时或者未使用其他扩展包的话，直接删除虚拟环境文件夹即可删除虚拟环境

6. 启用虚拟环境后，终端会有提示

    ```Linux
    (test_venv) [kelvin@kelvin-manjaro ~]$ 
    11
    ```

- 此部分参考文章: [最全的Python虚拟环境使用方法](https://zhuanlan.zhihu.com/p/60647332)

## 二 将虚拟环境运行路径添加到python文件

> 查看虚拟环境位置（在虚拟环境已经运行中的情况下）

```Linux
(test_venv) [kelvin@kelvin-manjaro ~]$ which python3
/home/kelvin/Applications/Virtualenv/test_venv/bin/python3
1212
```

> 将虚拟环境运行路径写入python文件
> 一般应将其写在想要执行的python文件的受行

```python
#!/home/kelvin/Applications/Virtualenv/test_venv/bin/python3
print('hello world')
1212
```

*如果你的python文件真的只想输出hello world的话，到这里差不多就可以运行了*

**但是你应该使用了很多模块和包**

所以，应该为虚拟环境安装这些模块何包，不然100%会报错。

## 三 为虚拟环境安装必要的包和模块

1. 在本地编写环境导出requirements.txt

    > 以Pycharm为例：打开Terminal终端,输入：

    ```Terminal
    (venv) [kelvin@kelvin-manjaro]$ pip freeze > requirements.txt
    11
    ```

    > 其他编写环境的方法也大致差不多，找到对应的终端输入命令即可。（如遇到问题自己举一反三）

    > 之后在项目文件夹的顶级目录中就会生成（更新）一份requirements.txt文件，这份文件就是该项目的运行环境所需包（模块）配置文件。
    >
    > 记住这份文件的位置或者复制到一个你记得住的位置。（下面要用)

2. 打开虚拟环境（如未启用虚拟环境参见 一. 3）根据配置文件安装所需模块

    > 记得把那个requirements.txt的位置找准咯，上面说了这里要用。

    ```Linux
    (test_venv) [kelvin@kelvin-manjaro ~]$ pip install -r requirements.txt
    
    1212
    ```

    > 安装完成后记得 **pip list** 检查一下

## 四 为Python文件设置权限

> 可别忘了Linux严格的权限管理机制，程序想要跑起来，还到有对应的权限。

根据你的意图设置对应的权限等级，我这里直接来个所有用户可访问并执行。

```Linux
(test_venv) [kelvin@kelvin-manjaro ~]$ chmod a+x test.py
11
```

## 五 终于，可以运行了

> 额，一般的可执行文件应该都是以 . 表示开始运行的

> 原文件

```python
#!/home/kelvin/Applications/Virtualenv/test_venv/bin/python3

print('hello, world')
print('welcome to weiguang19.xyz')

1234512345
```

> 终端效果

```Linux
(test_venv) [kelvin@kelvin-manjaro Others]$ ./test.py 
hello, world
welcome to weiguang19.xyz

12341234
```

麻烦吗？折腾就是了，其实只要第一次创建了此虚拟环境，以后只用在需要的时候开启使用就是了，如果偶尔缺少一两个包或者模块，也可以直接在虚拟环境终端中**pip install 包名** 安装即可。