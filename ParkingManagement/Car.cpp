#include "Car.h"

int Car::CountCost()//���㲢���ط���
{
	return((quitTime - enterTime) * price);
}