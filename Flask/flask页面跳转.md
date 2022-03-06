flask页面跳转

1.重定向到其他页面

``` python
@app.route('/baidu')
def baidu():
    return redirect('https://www.baidu.com')
```

2.根据逻辑跳转到相应页面

``` python
from flask import Flask, redirect, url_for
 app = Flask(__name__)
 @app.route('/admin')
 def hello_admin():
     return 'Hello Admin'
 @app.route('/guest/<guest>')
 def hello_guest(guest):
     return 'Hello %s as Guest' % guest
 @app.route('/user/<name>')
 def user(name):
     if name =='admin':
         return redirect(url_for('hello_admin'))
     else:
         return redirect(url_for('hello_guest',guest = name))
```

3.展示相应页面

``` python
from flask import Flask, render_template
 app = Flask(__name__)
 @app.route('/hello/<user>')
 def hello_name(user):
     return render_template('hello.html')
```

