#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "ferocious";  // WiFi SSID
const char* password = "qweasdzxc";  // WiFi密码


ESP8266WebServer server(80);// 创建web server服务器对象，端口号默认为80

const int relayPin = 5;  // D1引脚对应的GPIO编号为5
// 网站根目录设置
void handleRoot() {
  String html = "<html>\
                 <head>\
                   <title>ESP8266 Light Control</title>\
                   <style>\
                     body { font-family: Arial; text-align: center; margin-top: 50px; }\
                     button { font-size: 30px; padding: 10px 20px; margin: 20px; }\
                   </style>\
                 </head>\
                 <body>\
                   <h1>Control Light</h1>\
                   <button onclick=\"location.href='/on'\">Turn ON</button>\
                   <button onclick=\"location.href='/off'\">Turn OFF</button>\
                 </body>\
                 </html>";
  server.send(200, "text/html", html); // 调用函数生成并发送http响应信息
}                                      // 状态响应码，响应内容类型，响应内容
// 开灯
void handleOn() {
  digitalWrite(relayPin, HIGH);  // 高电平激活
  server.sendHeader("Location", "/"); //跳转网页到根目录
  server.send(303); // 303常用于将POST请求重定向到GET请求
}
// 关灯
void handleOff() {
  digitalWrite(relayPin, LOW);  // 低电平关闭继电器
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200); // 启动串口通讯，波特率115200
  pinMode(relayPin, OUTPUT);  // 设置输出端
  digitalWrite(relayPin, LOW);  // 低电平，启动时灯是关闭的

  Serial.println(); // 连接成功后串口监视器输出
  Serial.println("Connecting to WiFi...");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP()); // 成功连接，打印ip地址

  server.on("/", handleRoot); // 设置http请求回调函数，调用函数生成网站首页发送给浏览器
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();  // 处理http服务器访问，检查是否发送http请求
}                         // 放在loop中确保经常被调用，以稳定执行网络服务