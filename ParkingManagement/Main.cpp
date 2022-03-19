#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include"Car.h"
#include"Manager.h"
using namespace std;

void add();//ִ���볡����
void del();//ִ�г�������
void show();//��ʾ������Ϣ
void LoadList(Car*);//�����ļ�
void SaveList(Car*);//��̬����洢���ļ�
void LoadAdmin(Manager*);//���ع���Ա�շ��ۼ�
void SaveAdmin(Manager*);//�������Ա�շ��ۼ�

int N = 0;//��¼�ڳ�������
Car* CarList = new Car[5];//����ʱ����ͣ����Ϣ������
Manager Admin;//����ʱ��Ź���Ա��Ϣ

int main()
{
	LoadList(CarList);//����CarList.txt��numnber.txt
	LoadAdmin(&Admin);//����Admin.txt�е��շ��ۼƵ�Admin->AllCost��

	while (1)
	{
		cout << "��ӭʹ��ͣ��������ϵͳ" << endl;
		if (Admin.Login(&Admin))//Login()����1����������0������֤
		{
			while (1)//���볡����ѭ��
			{

				if (N == 0)
				{
					int x = 0;
					cout << "ͣ����Ϊ��" << endl << "0.�˳� 1.�볡 2.��ѯ���ó�λ 3.��ѯ�տ��ܶ� 4.��ʾ���г���" << endl << "�������ֺ󰴻س�����" << endl;
					cin >> x;

					switch (x)
					{
					case 0:delete[] CarList; return 0;//�ͷſռ䲢�˳�
					case 1:add(); break;
					case 2:cout << "ʣ��" << 5 - N << "����λ" << endl << "==========================" << endl; break;
					case 3:cout << "�տ��ܶ�Ϊ" << Admin.AllCost << "Ԫ" << endl << "==========================" << endl; break;
					case 4:show(); break;
					}
				}
				else if (N < 5)
				{
					int x = 0;
					cout << "0.�˳� 1.���� 2.�볡 3.��ѯ���ó�λ 4.��ѯ�տ��ܶ� 5.��ʾ���г���" << endl << "�������ֺ󰴻س�����" << endl;
					cin >> x;

					switch (x)
					{
					case 0:delete[] CarList; return 0;//�ͷſռ䲢�˳�
					case 1:del(); break;//����
					case 2:add(); break;//�볡
					case 3:cout << "ʣ��" << 5 - N << "����λ" << endl << "==========================" << endl; break;
					case 4:cout << "�տ��ܶ�Ϊ" << Admin.AllCost << "Ԫ" << endl << "==========================" << endl; break;
					case 5:show(); break;
					}
				}
				else if (N == 5)
				{
					int x = 0;
					cout << "ͣ��������" << endl << "0.�˳� 1.���� 2.��ѯ���ó�λ 3.��ѯ�տ��ܶ� 4.��ʾ���г���" << endl << "�������ֺ󰴻س�����" << endl;
					cin >> x;

					switch (x)
					{

					case 0:delete[] CarList; return 0;//�ͷſռ䲢�˳�
					case 1:del(); break;//����
					case 2:cout << "ʣ��" << 5 - N << "����λ" << endl << "==========================" << endl; break;
					case 3:cout << "�տ��ܶ�Ϊ" << Admin.AllCost << "Ԫ" << endl << "==========================" << endl;
					case 4:show(); break;
					}
				}
			}
		}
	}
}

void add()//ִ���볡����
{
	if (N < 5)
	{
		cout << "�����복�ƺš����͡��볡ʱ�䡢����" << endl;
		cin >> CarList[N].number >> CarList[N].model >> CarList[N].enterTime >> CarList[N].price;//���복����Ϣ
		N++;//�ڳ�������+1
		SaveList(CarList);//д�복����Ϣ���ļ�
		cout << "==========================" << endl;
	}
}

void del()//ִ�г�������
{
	int x;//��¼ҪѰ�ҵĳ��ƺ�
	cout << "��������������ĳ���" << endl;
	cin >> x;

	for (int i = 0; i < N; i++)//����Ԫ�ز����г�������
	{
		if (CarList[i].number == x)
		{
			cout << "���������ʱ��" << endl;
			cin >> CarList[i].quitTime;
			cout << "ͣ��ʱ��Ϊ��" << CarList[i].quitTime - CarList[i].enterTime << endl;
			cout << "ͣ������Ϊ" << CarList[i].price * (CarList[i].quitTime - CarList[i].enterTime) << "Ԫ" << endl;

			Admin.AllCost += (CarList[i].price * (CarList[i].quitTime - CarList[i].enterTime));//�ۼ��տ���
			SaveAdmin(&Admin);

			for (int j = i; j < N; j++)//�������ݣ���ɾ��λ��֮���Ԫ��ǰ��
			{
				CarList[j] = CarList[j + 1];
			}
			N--;
			SaveList(CarList);//д�복����Ϣ���ļ�
			cout << "==========================" << endl;
		}
	}
}

void show()
{
	cout << "���ƺ�" << setw(6) << "����" << setw(10) << "�볡ʱ��" << setw(6) << "����" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << setw(6) << CarList[i].number << setw(6) << CarList[i].model << setw(10) << CarList[i].enterTime << setw(6) << CarList[i].price << endl;
	}
	cout << "==========================" << endl;
}

void LoadList(Car* _LoadList)//�����ļ�
{
	ifstream ReadNum;
	ReadNum.open("number.txt");//��number.txt
	ReadNum >> N;//��ͣ������������ȡ��N
	ReadNum.close();

	ifstream Load;
	Load.open("CarList.txt");//��CarList.txt
	int i = 0;
	while (!Load.eof())//���û�������ļ�β�ͼ���
	{
		Load >> _LoadList[i].number >> _LoadList[i].model >> _LoadList[i].enterTime >> _LoadList[i].quitTime >> _LoadList[i].price >> _LoadList[i].cost;
	}
	Load.clear();
	Load.close();
}

void SaveList(Car* _SaveList)//��̬����洢���ļ�
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
	SaveNum << N;//��ͣ������������¼��number.txt��
	SaveNum.clear();
	SaveNum.close();
}

void LoadAdmin(Manager* _LoadAdmin)//���ع���Ա�շ��ۼ�
{
	ifstream Load;
	Load.open("Admin.txt");//��Admin.txt
	Load >> _LoadAdmin->AllCost;
	Load.clear();
	Load.close();
}

void SaveAdmin(Manager* _SaveAdmin)//�������Ա�շ��ۼ�
{
	ofstream Save;
	Save.open("Admin.txt");
	Save << _SaveAdmin->AllCost;
	Save.clear();
	Save.close();
}