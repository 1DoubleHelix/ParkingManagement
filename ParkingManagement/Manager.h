#pragma once
#include<iostream>
#include<string>
using namespace std;

class Manager
{
public:
	const string ID = "admin";//�˺�
	const string key = "admin";//����
	int AllCost;//�շ��ۼ�

	Manager() :AllCost(0) {}
	~Manager() {};
	int Login(Manager*);//У���¼
};