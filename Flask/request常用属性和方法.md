request常用属性和方法

| 属性或方法   | 说明                                                         |      |
| ------------ | ------------------------------------------------------------ | ---- |
| form         | 一个字典,存储请求提交的所有表单字段                          |      |
| args         | 一个字典,存储通过URL查询字符串传递的所有参数                 |      |
| environ      | 请求的原始WSG环境字典                                        |      |
| remote_addr  | 客户端的IP地址                                               |      |
| base_url     | 同urL,但没有查询字符串部分                                   |      |
| url          | 客户端请求的完整URL                                          |      |
| full_path    | URL的路径和查询字符串部分                                    |      |
| query_string | URL的查询字符串部分,返回原始二进制值                         |      |
| path         | URL的路径部分                                                |      |
| host         | 请求定义的主机名,如果客户端定义了端口号,还包括端口号         |      |
| scheme       | URL方案 URL(http  https)或https)                             |      |
| method       | HTTP请求方法,例如GET或POST                                   |      |
| is_secure()  | 通过安全的连接( (HTTPS)True)发送请求时返回True               |      |
| endpoint     | 处理请求的 Flask端点的名称; Flask把视图函数的名称用作路由端点的名称 |      |
| blueprint    | 处理请求的 Flask蓝本的名称;蓝本在第7章介绍                   |      |
| headers      | 一个字典,存储请求的所有HTTP首部                              |      |
| files        | 一个字典,存储请求上传的所有文件                              |      |
| values       | 一个字典,form和args的合集                                    |      |
| get_data()   | 返回请求主体缓冲的数据                                       |      |
| get_json()   | 返回一个 Python字典,包含解析请求主体后得到的JSON             |      |
| cookies      | 一个字典,存储请求的所有 cookie                               |      |

tips：

> request.args与request.form的区别就是：
>
> request.args是获取url中的参数
>
> request.form是获取form表单中的参数
