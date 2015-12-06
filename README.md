# openkeeper-cli 重庆高校电信上网拨号程序的Linux实现。

## 依赖关系
rp-pppoe, iproute2, tcpdump

## 编译

> $ make

## 安装

> $ sudo make install

## 配置

可以使用

> $ sudo ok-config

设置用户名、密码、网络接口。

用户名、密码即为在电信高校客户端中填写的用户名、密码。

网络接口为拨号所使用的网络端口，请通过

> $ ip link

查询。

# 拨号

使用

> $ sudo ok

即可拨号。

# 卸载
> $ sudo make uninstall
