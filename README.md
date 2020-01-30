# daytime-Tcp-client
## 需知
环境：CentOS 6
协议：IPv4、TCP
*参考书籍：UNIX 网络编程 卷1*
***
## 简单介绍
一个用于获取daytime并显示的客户端代码。
使用包了裹函数使主干代码便于理解。
实现了标准错误处理函数：
函数 | strerror(errno)? | 结束语句 | syslog级别
-----|-----|-----|-----|-----
err_dump | 是 | abort(); | LOG_ERR
err_msg | 否 | return; | LOG_INFO
err_quit | 否 | exit(1); | LOG_ERR
err_ret | 是 | return; | LOG_INFO
err_sys | 是 | exit(1); | LOG_ERR
***
## 使用
> // 示例
> make
> ./st 127.0.0.1
