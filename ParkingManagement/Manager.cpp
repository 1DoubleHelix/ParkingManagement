#include "Manager.h"

int Manager::Login(Manager* _Login)
{
	string tmp_ID;
	string tmp_key;
	cout << "�������û���������" << endl;
	cin >> tmp_ID;
	cin >> tmp_key;

	if (tmp_ID == _Login->ID && tmp_key == _Login->key)//��֤�˺����룬��ȷ����1�����󷵻�0
	{
		return 1;
	}
	else
	{
		cout << "�û������������" << endl;
		return 0;
	}
}