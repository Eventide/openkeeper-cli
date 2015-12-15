# 重庆高校 Linux 上网客户端 openkeeper

## 安装

#### Ubuntu
###### 安装依赖软件
**`$ sudo apt-get install build-essential pppoe git`**
###### 安装 openkeeper
**`$ cd /tmp && git clone https://github.com/RainMark/openkeeper-cli.git && cd openkeeper-cli && git checkout ipv6 && make && sudo make install`**

#### Fedora
###### 安装依赖软件
**`$ sudo dnf install gcc gcc-c++ make rp-pppoe git`**
###### 安装 openkeeper
**`$ cd /tmp && git clone https://github.com/RainMark/openkeeper-cli.git && cd openkeeper-cli && git checkout ipv6 && make && sudo make install`**

#### Arch Linux
###### 安装依赖软件
**` $ sudo pacman -S gcc ppp rp-pppoe make git `**
###### 安装 openkeeper
**`$ cd /tmp && git clone https://github.com/RainMark/openkeeper-cli.git && cd openkeeper-cli && git checkout ipv6 && make && sudo make install`**

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
**`$ cd /tmp/openkeeper-cli && sudo make uninstall `**

##### 问题反馈
*Email: rain_of_mem@163.com*
