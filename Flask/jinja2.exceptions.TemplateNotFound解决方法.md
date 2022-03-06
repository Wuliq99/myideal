jinja2.exceptions.TemplateNotFound解决方法

关于这个问题的解决方法，总共有以下几种解决方法

1、项目下面是否有templates文件夹，你的html文件是否放进了里面；
2、templates文件夹是否和你运行的py文件在同一级目录；
3、render_template('*.html')这里面的名字是否正确，别打错了；
4、没有遵循 flask 的默认规则，flask 默认模板文件夹名为 `templates`（如果没有自己进行指定的话）

```python
def __init__(
        self,
        import_name: str,
        static_url_path: t.Optional[str] = None,
        static_folder: t.Optional[t.Union[str, os.PathLike]] = "static",
        static_host: t.Optional[str] = None,
        host_matching: bool = False,
        subdomain_matching: bool = False,
        template_folder: t.Optional[str] = "templates",
        instance_path: t.Optional[str] = None,
        instance_relative_config: bool = False,
        root_path: t.Optional[str] = None,
    )
```

