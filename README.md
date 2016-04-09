
# 重庆高校 Linux 上网客户端 openkeeper

## 安装

#### 安装依赖软件

###### Ubuntu 
**`$ sudo apt-get install build-essential libssl-dev pppoe git`**

###### Fedora
**`$ sudo dnf install gcc libssl-devl make rp-pppoe git`**

###### Arch Linux
**`$ sudo pacman -S gcc openssl rp-pppoe make git`**

#### 安装 openkeeper
**`$ cd /tmp && git clone https://github.com/Eventide/openkeeper-cli.git && cd openkeeper-cli && make && sudo make install `**

## 配置
###### 查看有线网口
*终端执行 `ip link` ，查看输出，有线网口名称一般为 eth0 ， enp1s0 等.*
###### 填写配置文件
**`$ sudo ok-config`**

## 拨号
**`$ sudo ok`**
## 下线
**`$ sudo ok-stop`**

## 卸载
**`$ cd /tmp/openkeeper-cli && sudo make uninstall`**

##### 问题反馈
*Email: rain_of_mem@163.com*

*Email: nanjingzr@yahoo.com*
