``` python
pip --version  # 显示版本和路径
pip --help  #获取帮助
pip install -U pip #升级pip
pip install SomePackage #最新版本
pip install SomePackage==1.0.4 #指定版本
pip install SomePackage>=1.0.4 #最小版本
pip install --upgrade SomePackage #升级包，通过使用==，>=, <=, >, < 来指定一个版本号
或 pip install -U SomePackage #升级包
pip uninstall SomePackage #卸载包
pip search SomePackage #搜索包
pip show #显示安装包的信息

pip show -f SomePackage #查看指定包的详细信息

pip list #列出已安装的包
pip list -o #查看可升级的包
pip freeze #查看已经安装的包以及版本信息

pip install SomePackage -i http://pypi.intra.xxx.com/simple/  --trusted-host pypi.intra.xxx.com #安装包时指定下载源及安装路径
    
pip install -r requirements.txt #安装指定文件中的包

##注意事项
#当python2和python3同时有pip,则使用方法如下：
python2 -m pip install xxx #python2
python3 -m pip install xxx #python3

#卸载pip
python -m pip uninstall pip




```



pip常用下载源

> https://pypi.tuna.tsinghua.edu.cn/simple/	# 清华大学
> https://mirrors.aliyun.com/pypi/simple/		# 阿里云
> https://pypi.douban.com/simple/				# 豆瓣
> https://pypi.mirrors.ustc.edu.cn/simple/	# 中国科学技术大学
> https://pypi.hustunique.com/				# 华中科技大学