
#include <iostream>
#include "Seats.h"
using namespace std;

class AirBooking
{
public:
	Seats seat[3];
	AirBooking();  // 클래스 생성자.
	~AirBooking(); // 클래스 소멸자.

	int showmenu();// 초기 메뉴를 출력한다.
	int time_index(int time); // 입력받은 시간을 인덱스로 반환한다.
};