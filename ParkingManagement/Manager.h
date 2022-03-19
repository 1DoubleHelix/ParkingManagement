#pragma once
#include<iostream>
#include<string>
using namespace std;

class Manager
{
public:
	const string ID = "admin";//账号
	const string key = "admin";//密码
	int AllCost;//收费累计

	Manager() :AllCost(0) {}
	~Manager() {};
	int Login(Manager*);//校验登录
};