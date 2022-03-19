#include "Car.h"

int Car::CountCost()//计算并返回费用
{
	return((quitTime - enterTime) * price);
}