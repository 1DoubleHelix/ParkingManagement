#pragma once
#include<iostream>
#include<string>
using namespace std;
class Car
{
public:
	int number;//���ƺ�
	string model;//����
	int enterTime;//�볡ʱ��
	int quitTime;//����ʱ��
	int price;//ÿСʱ�շ�
	int cost;//����

	Car() :number(0), model("default"), enterTime(0), quitTime(0), price(0), cost(0) {}//��ʼ��Car��Ķ���
	~Car() {}
	int CountCost();//���㲢���ط���
};