
#include <iostream>
#include "Seats.h"
using namespace std;

class AirBooking
{
public:
	Seats seat[3];
	AirBooking();  // Ŭ���� ������.
	~AirBooking(); // Ŭ���� �Ҹ���.

	int showmenu();// �ʱ� �޴��� ����Ѵ�.
	int time_index(int time); // �Է¹��� �ð��� �ε����� ��ȯ�Ѵ�.
};