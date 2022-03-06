Flask

- 在使用Flask时，返回值会被浏览器自动处理（尽量返回字符串）
- Flask不允许返回None
- Flask可实现多URL的路由

### 修改Flask的配置

``` python
app = Flask(__name__)
```

上面的代码中，[python](https://so.csdn.net/so/search?from=pc_blog_highlight&q=python)内置变量`__name__`的值是字符串`__main__` 。Flask类将这个参数作为程序名称。当然这个是可以自定义的，比如`app = Flask("my-app")`。

Flask默认使用`static`目录存放静态资源，`templates`目录存放模板，这是可以通过设置参数更改的

### 调试模式

上面的server.py中以`app.run()`方式运行，这种方式下，如果服务器端出现错误是不会在客户端显示的。但是在开发环境中，显示错误信息是很有必要的，要显示错误信息，应该以下面的方式运行Flask：

``` pythoon
app.run(debug=True)
```

将`debug`设置为`True`的另一个好处是，程序启动后，会自动检测源码是否发生变化，若有变化则自动重启程序。这可以帮我们省下很多时间。

##  获取 URL 参数

URL参数是出现在url中的键值对，例如`http://127.0.0.1:5000/?disp=3`中的url参数是`{'disp':3}`

**request.args只获取地址栏中参数 ，不分get请求方式还是post请求方式**

### 获取**某个**指定的URL参数 request.args.get

``` python
from flask import Flask, request
 
app = Flask(__name__)
 
@app.route('/')
def hello_world():
    return request.args.get('info')
 
if __name__ == '__main__':
    app.run(port=5000)
```

获取**同名**一系列URL参数request.args.getlist



## JSON响应

### 响应JSON-方案1

响应JSON时，除了要把响应体改成JSON格式，响应头的`Content-Type`也要设置为`application/json`。

``` python
from flask import Flask, request, Response
import json
 
app = Flask("my-app")
 
 
@app.route('/')
def hello_world():
    return 'Hello World!'
 
 
@app.route('/add', methods=['POST'])
def add():
    result = {'sum': request.json['a'] + request.json['b']}
    return Response(json.dumps(result),  mimetype='application/json')
 
 
if __name__ == '__main__':
    app.run(host='127.0.0.1', port=5000, debug=True)
```

### 响应JSON-方案2

使用 jsonify 工具函数即可。

``` python
from flask import Flask, request, jsonify
 
app = Flask("my-app")
 
 
@app.route('/')
def hello_world():
    return 'Hello World!'
 
 
@app.route('/add', methods=['POST'])
def add():
    result = {'sum': request.json['a'] + request.json['b']}
    return jsonify(result)
 
 
if __name__ == '__main__':
    app.run(host='127.0.0.1', port=5000, debug=True)
```



## 使用Jinja2模板引擎

模板引擎负责MVC中的V（view，视图）这一部分。Flask默认使用Jinja2模板引擎。

Flask与模板相关的函数有：

- flask.render_template(template_name_or_list, **context)
  Renders a template from the template folder with the given context.
- flask.render_template_string(source, **context)
  Renders a template from the given template source string with the given context.
- flask.get_template_attribute(template_name, attribute)
  Loads a macro (or variable) a template exports. This can be used to invoke a macro from within Python code.



##  使用redirect重定向网址

``` python
from flask import Flask, url_for, redirect
 
app = Flask(__name__)
 
@app.route('/')
def hello_world():
    return 'hello world'
 
@app.route('/test1')
def test1():
    print('this is test1')
    return redirect(url_for('test2'))
 
@app.route('/test2')
def test2():
    print('this is test2')
    return 'this is test2'
 
if __name__ == '__main__':
    app.run(debug=True)
```

