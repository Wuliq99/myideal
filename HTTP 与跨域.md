# HTTP 与跨域

## 原因

同源政策的目的，是为了保证用户信息的安全，防止恶意的网站窃取数据。所谓"同源"指的是"三个相同": 协议相同、域名相同、端口相同。

随着互联网的发展，"同源政策"越来越严格。目前，如果非同源，共有三种行为受到限制。

- Cookie、LocalStorage和IndexDB无法读取

- DOM无法获得
- AJAX请求不能发送

## 解决方法

跨域方法大概以下几种：

document.domain + iframe(只有在主域相同的时候才能使用该方法)
动态创建script(JSONP)
location.hash + iframe
window.name + iframe
postMessage
CORS
websockets
现在的话，应该是 CORS 的使用会更广泛吧。实现 CORS 通信的关键是服务器。只要服务器实现了 CORS 接口，就可以跨源通信。