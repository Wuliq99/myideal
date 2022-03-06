常用的SQLAlchemy列类型

| 类型名       | Python类型         | 说明                                                |
| ------------ | ------------------ | --------------------------------------------------- |
| Integer      | int                | 普通整数,通常是32位                                 |
| SmallInteger | int                | 取值范围小的整数,通常是16位                         |
| BigInteger   | int或Long          | 不限制精度的整数                                    |
| Float        | float              | 浮点数                                              |
| Numeric      | decimal.Decimal    | 定点数                                              |
| String       | str                | 变长字符串                                          |
| Text         | str                | 变长字符串,对较长或不限长度的字符串做了优化         |
| Unicode      | unicode            | 变长 Unicode字符串                                  |
| UnicodeText  | unicode            | 变长 Unicode字符串,对较长或不限长度的字符串做了优化 |
| Boolean      | bool               | 布尔值                                              |
| Date         | datetime.date      | 日期                                                |
| Time         | datetime.time      | 时间                                                |
| DateTime     | datetime.datetime  | 日期和时间                                          |
| Interval     | datetime.timedelta | 时间间隔                                            |
| Enum         | str                | 一组字符串                                          |
| PickleType   | 任何 Python对象    | 自动使用 Pickle序列化                               |
| LargeBinary  | str                | 二进制blob                                          |

