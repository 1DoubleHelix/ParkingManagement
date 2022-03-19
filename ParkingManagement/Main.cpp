#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include"Car.h"
#include"Manager.h"
using namespace std;

void add();//执行入场操作
void del();//执行出场操作
void show();//显示车辆信息
void LoadList(Car*);//加载文件
void SaveList(Car*);//动态数组存储到文件
void LoadAdmin(Manager*);//加载管理员收费累计
void SaveAdmin(Manager*);//保存管理员收费累计

int N = 0;//记录在场车辆数
Car* CarList = new Car[5];//运行时后存放停车信息的容器
Manager Admin;//运行时存放管理员信息

int main()
{
	LoadList(CarList);//加载CarList.txt和numnber.txt
	LoadAdmin(&Admin);//加载Admin.txt中的收费累计到Admin->AllCost中

	while (1)
	{
		cout << "欢迎使用停车场管理系统" << endl;
		if (Admin.Login(&Admin))//Login()返回1继续，返回0重新验证
		{
			while (1)//出入场管理循环
			{

				if (N == 0)
				{
					int x = 0;
					cout << "停车场为空" << endl << "0.退出 1.入场 2.查询可用车位 3.查询收款总额 4.显示所有车辆" << endl << "输入数字后按回车继续" << endl;
					cin >> x;

					switch (x)
					{
					case 0:delete[] CarList; return 0;//释放空间并退出
					case 1:add(); break;
					case 2:cout << "剩余" << 5 - N << "个车位" << endl << "==========================" << endl; break;
					case 3:cout << "收款总额为" << Admin.AllCost << "元" << endl << "==========================" << endl; break;
					case 4:show(); break;
					}
				}
				else if (N < 5)
				{
					int x = 0;
					cout << "0.退出 1.出场 2.入场 3.查询可用车位 4.查询收款总额 5.显示所有车辆" << endl << "输入数字后按回车继续" << endl;
					cin >> x;

					switch (x)
					{
					case 0:delete[] CarList; return 0;//释放空间并退出
					case 1:del(); break;//出场
					case 2:add(); break;//入场
					case 3:cout << "剩余" << 5 - N << "个车位" << endl << "==========================" << endl; break;
					case 4:cout << "收款总额为" << Admin.AllCost << "元" << endl << "==========================" << endl; break;
					case 5:show(); break;
					}
				}
				else if (N == 5)
				{
					int x = 0;
					cout << "停车场已满" << endl << "0.退出 1.出场 2.查询可用车位 3.查询收款总额 4.显示所有车辆" << endl << "输入数字后按回车继续" << endl;
					cin >> x;

					switch (x)
					{

					case 0:delete[] CarList; return 0;//释放空间并退出
					case 1:del(); break;//出场
					case 2:cout << "剩余" << 5 - N << "个车位" << endl << "==========================" << endl; break;
					case 3:cout << "收款总额为" << Admin.AllCost << "元" << endl << "==========================" << endl;
					case 4:show(); break;
					}
				}
			}
		}
	}
}

void add()//执行入场操作
{
	if (N < 5)
	{
		cout << "请输入车牌号、车型、入场时间、单价" << endl;
		cin >> CarList[N].number >> CarList[N].model >> CarList[N].enterTime >> CarList[N].price;//输入车辆信息
		N++;//在场车辆数+1
		SaveList(CarList);//写入车辆信息到文件
		cout << "==========================" << endl;
	}
}

void del()//执行出场操作
{
	int x;//记录要寻找的车牌号
	cout << "请输入出场车辆的车牌" << endl;
	cin >> x;

	for (int i = 0; i < N; i++)//查找元素并进行出场操作
	{
		if (CarList[i].number == x)
		{
			cout << "请输入出场时间" << endl;
			cin >> CarList[i].quitTime;
			cout << "停车时间为：" << CarList[i].quitTime - CarList[i].enterTime << endl;
			cout << "停车费用为" << CarList[i].price * (CarList[i].quitTime - CarList[i].enterTime) << "元" << endl;

			Admin.AllCost += (CarList[i].price * (CarList[i].quitTime - CarList[i].enterTime));//累加收款金额
			SaveAdmin(&Admin);

			for (int j = i; j < N; j++)//整理数据，将删除位置之后的元素前移
			{
				CarList[j] = CarList[j + 1];
			}
			N--;
			SaveList(CarList);//写入车辆信息到文件
			cout << "==========================" << endl;
		}
	}
}

void show()
{
	cout << "车牌号" << setw(6) << "车型" << setw(10) << "入场时间" << setw(6) << "单价" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << setw(6) << CarList[i].number << setw(6) << CarList[i].model << setw(10) << CarList[i].enterTime << setw(6) << CarList[i].price << endl;
	}
	cout << "==========================" << endl;
}

void LoadList(Car* _LoadList)//加载文件
{
	ifstream ReadNum;
	ReadNum.open("number.txt");//打开number.txt
	ReadNum >> N;//将停车场车辆数读取到N
	ReadNum.close();

	ifstream Load;
	Load.open("CarList.txt");//打开CarList.txt
	int i = 0;
	while (!Load.eof())//如果没有遇到文件尾就继续
	{
		Load >> _LoadList[i].number >> _LoadList[i].model >> _LoadList[i].enterTime >> _LoadList[i].quitTime >> _LoadList[i].price >> _LoadList[i].cost;
	}
	Load.clear();
	Load.close();
}

void SaveList(Car* _SaveList)//动态数组存储到文件
{
	ofstream Save;
	Save.open("CarList.txt");

	for (int i = 0; i < N; i++)
	{
		Save << _SaveList[i].number << endl << _SaveList[i].model << endl << _SaveList[i].enterTime << endl << _SaveList[i].quitTime << endl << _SaveList[i].price << endl << _SaveList[i].cost << endl;
	}
	Save.clear();
	Save.close();

	ofstream SaveNum;
	SaveNum.open("number.txt");
	SaveNum << N;//将停车场车辆数记录在number.txt中
	SaveNum.clear();
	SaveNum.close();
}

void LoadAdmin(Manager* _LoadAdmin)//加载管理员收费累计
{
	ifstream Load;
	Load.open("Admin.txt");//打开Admin.txt
	Load >> _LoadAdmin->AllCost;
	Load.clear();
	Load.close();
}

void SaveAdmin(Manager* _SaveAdmin)//保存管理员收费累计
{
	ofstream Save;
	Save.open("Admin.txt");
	Save << _SaveAdmin->AllCost;
	Save.clear();
	Save.close();
}