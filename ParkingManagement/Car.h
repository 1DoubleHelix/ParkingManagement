#pragma once
#include<iostream>
#include<string>
using namespace std;
class Car
{
public:
	int number;//车牌号
	string model;//车型
	int enterTime;//入场时间
	int quitTime;//出场时间
	int price;//每小时收费
	int cost;//费用

	Car() :number(0), model("default"), enterTime(0), quitTime(0), price(0), cost(0) {}//初始化Car类的对象
	~Car() {}
	int CountCost();//计算并返回费用
};