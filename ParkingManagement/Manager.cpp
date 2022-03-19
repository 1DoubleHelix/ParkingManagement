#include "Manager.h"

int Manager::Login(Manager* _Login)
{
	string tmp_ID;
	string tmp_key;
	cout << "请输入用户名和密码" << endl;
	cin >> tmp_ID;
	cin >> tmp_key;

	if (tmp_ID == _Login->ID && tmp_key == _Login->key)//验证账号密码，正确返回1，错误返回0
	{
		return 1;
	}
	else
	{
		cout << "用户名或密码错误！" << endl;
		return 0;
	}
}