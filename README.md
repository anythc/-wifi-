# -wifi-
项目四
改造普通灯变成WiFi控制灯
一、目的
将普通灯改造为wifi灯。
二、环境
1、NodeMCU（ESP8266）开发板一块
2、高低电平继电器模块一个
3、普通USB灯一个
4、220V-5V变压器（根据具体情况选型）
5、开发环境Arduino
6、相应的驱动安装（CH341SerSetup）
7、在arduino中安装esp8266的库
8、手机一台
三、基本原理
1.ESP8266：
ESP8266 是一个非常强大的 WIFI 模块，可以利用串口与单片机进行通讯，从而编程实现控制 ESP8266。利用 ESP8266 可以访问一些 API，获取天气信息或者完成网络授时，也可以连接云平台进行开发。不过因为是串口传输，速度较慢，不能用来传输图像、视频这些大容量的数据，可传传感器数据。
一般而言的 ESP8266 是指 ESP8266 WIFI 模块，它是物联网和嵌入式开发常用的模块，其中 ESP8266 是 WIFI 模块的芯片型号。
ESP8266有ESP-01/01S/07/07S/12E/12F/12S 等规格，还有正点原子自研的 ATK-ESP8266 （修改了固件及模组引脚）。
2.NodeMCU：
开源物联网硬件开发板，支持WiFi功能，可以使用Arduino IDE进行开发操作。
NodeMCU是基于ESP8266为核心的开发板，其上有两排插针，和ESP8266芯片引脚相连，一端配有USB接口，可接入电脑连接端口。
主要有三种模式：
1.AP模式
提供无线接入服务，允许其他无线设备接入，提供数据访问。比如路由器。
2.STA模式
类似于无线终端，station本身并不接受无线的接入，可以连接到AP。就像无线网卡、手机一样，搜索到无线网后连接。
3.AP+STA模式
两者合一。
NodeMCU开发板引脚的输入输出电压限制为3.3v，过大电压可能造成损伤。
连接时需注意操作引脚对应名称。
3.HTTP：
HTTP(HyperText Transfer Protocol)即超文本传输协议。是一个简单的请求-响应协议，通常运行在TCP之上,运行于应用层。它指定了客户端可能发送给服务器什么样的消息以及得到什么样的响应。请求和响应消息的头以ASCII码形式给出.
HTTP是一种无状态的协议，Web浏览器与服务器之间不需要建立持久的连接，这意味着当一个客户端向服务器端发出请求，然后Web服务器返回响应，连接就此关闭，在服务器端不保留连接的有关信息。即HTTP请求只能由客户端发起。
HTTP协议工作于客户端-服务端架构上。客户端向服务端即WEB服务器发送请求。 默认端口号为80。
四、步骤与结果
1.连接线路
2.安装串口驱动模块
安装好NodeMCU的串口驱动模块，使得开发板可以连接上Arduino。
3.下载Arduino
进入官网SOFTWARE界面，根据自身电脑配置下载最新版Arduino。
4.配置ESP8266开发环境
打开Arduino IDE，在文件-首选项界面找到附加开发板管理器地址（Additional Board Manager URLs）。在开发板管理器界面搜索esp8266，下载得到esp8266的板级支持包。这种方法使用时可能因为国外源问题下载速度非常慢甚至导致失败，可在网上找其他镜源或找安装包。
5.项目开发过程和代码展示
使用开发板附带的USB接口连接电脑，通过串口驱动模块连接到Arduino。
6.代码展示：在Arduino上编写程序，实现利用WIFI在网页上实现对普通灯的开关
7。程序烧录
代码编译上传，等待连接。
五、总结分析
本次实验使用硬件和软件融合操作，通过开发板、继电器等原件等形成回路，在Arduino进行代码编写搭建服务器，通过设置高低电平在连线中修改继电器状态，函数响应网页请求，最终在网页实现交互需求，WIFI控制点亮普通USB灯。
