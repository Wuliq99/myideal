``` python
class pymysql.connections.Connection(
    host=None,                                    
    user=None,                                     
    password='',                                     
    database=None,                                     
    port=0,                                     
    unix_socket=None,                                     
    charset='',                                     
    sql_mode=None,                                      
    read_default_file=None,                                      
    conv=None,                                      
    use_unicode=None, 
    client_flag=0,                                    
    cursorclass=<class'pymysql.cursors.Cursor'>,              
    init_command=None,                                     
    connect_timeout=10,     
    ssl=None, 
    read_default_group=None, 
    compress=None, 
    named_pipe=None, 
    autocommit=False, 
    db=None, 
    passwd=None, 
    local_infile=False, 
    max_allowed_packet=16777216, 
    defer_connect=False, 
    auth_plugin_map=None, 
    read_timeout=None, 
    write_timeout=None, 
    bind_address=None, 
    binary_prefix=False, 
    program_name=None, 
    server_public_key=None
)
```

### 参数

- **host** – 数据库服务器所在的主机

- **user** – 登录的用户名
- **password** – 要使用的密码。
- **database** – 要使用的数据库，None不使用特定的数据库。
- **port** – 要使用的MySQL端口，默认通常都可以。(默认值：3306)
- **bind_address** – 当客户端具有多个网络接口时，请指定从中连接到主机的接口。参数可以是主机名或IP地址。
- **unix_socket** – 您可以选择使用unix套接字而不是TCP / IP。
- **read_timeout** – 以秒为单位读取连接的超时(默认值：无 – 无超时)
- **write_timeout** – 以秒为单位写入连接的超时(默认值：无 – 无超时)
- **charset** – 你要使用的Charset。
- **sql_mode** – 要使用的默认SQL_MODE。
- **read_default_file** – 指定my.cnf文件以从[client]部分下读取这些参数。
- **conv** – 使用转换字典而不是默认字典。这用于提供类型的自定义编组和解组。见转换器。
- **use_unicode** – 是否默认为unicode字符串。对于Py3k，此选项默认为true。
- **client_flag** – 要发送给MySQL的自定义标志。在constants.CLIENT中查找潜在值。
- **cursorclass** – 要使用的自定义游标类。
- **init_command** – 建立连接时要运行的初始SQL语句。
- **connect_timeout** – 连接时抛出异常之前的超时。(默认值：10，最小值：1，最大值：31536000)
- **ssl** – 类似于mysql_ssl_set()参数的参数的dict。
- **read_default_group** – 要在配置文件中读取的组。
- **压缩** – 不支持
- **named_pipe** – 不支持
- **autocommit** – **自动**提交模式。无表示使用服务器默认值。(默认值：False)
- **local_infile** – 允许使用LOAD DATA LOCAL命令的布尔值。(默认值：False)
- **max_allowed_packet** – 发送到服务器的最大数据包大小(以字节为单位)。(默认值：16MB)仅用于限制小于默认值(16KB)的“LOAD LOCAL INFILE”数据包的大小。
- **defer_connect** – 不要在构造上显式连接 – 等待连接调用。(默认值：False)
- **auth_plugin_map** – 插件名称的一个字典，用于处理该插件的类。该类将Connection对象作为构造函数的参数。该类需要一个认证方法，将认证包作为参数。对于对话框插件，可以使用提示(echo，prompt)方法(如果没有authenticate方法)从用户返回字符串。(实验)
- **server_public_key** – SHA256身份验证插件公钥值。(默认：无)
- **db** – 数据库的别名。(与MySQLdb兼容)
- **passwd** – 密码的别名。(与MySQLdb兼容)

- **binary_prefix** – 在字节和bytearray上添加_binary前缀。(默认值：False)