# 停车场管理程序

C++编写的停车场管理程序，年代久远，十分简陋

## 用户名和密码

存放在Manager.h中

* 用户名`admin`
* 密码`admin`

## 文件

* CarList.txt：用于存放车辆信息，文件在登录后被LoadList(Car*)函数加载进一个Car*类型的动态数组里面。在每一次出场操作后SaveList(Car*)读取Car*类型的动态数组的元素写入CarList.txt

* number.txt用于存放停车场的在场车辆数，登录成功后被LoadList(Car*)函数读取，将文件存放的数字赋值给全局变量N。在每一次出场操作后SaveList(Car*)读取全局变量N并写入number.txt

* Admin.txt用于存放管理员的收款总金额，进入主函数后由LoadList(CarManager*)函数加载进一个CarManager类的对象中存放，在每一次出场操作后SaveAdmin(CarManger*)读取CarManager类的对象中的金额并写进Admin.txt
