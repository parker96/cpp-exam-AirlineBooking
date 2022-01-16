
#include <iostream>
#include <string>
#define SEAT_MAX 8
using namespace std;

class Seats
{
public:
	int time[2]; // 출발하는 시간 데이터. [0] = 시, [1] = 분
	string seats[SEAT_MAX][2]; // 좌석 데이터. [0] = 예약자 이름, [1] = 비밀번호.
	string dis[SEAT_MAX][2]; // 예약자 질병 데이터. [0] = 예약자의 질병, [1] = 복용중인 약.

	Seats(); // 클래스 생성자
	~Seats();// 클래스 소멸자

	int check_rest(); // 남은 좌석 수를 확인한다.
	void print_seats();// 좌석의 현황을 출력한다.
	void Book_seats(); // 선택한 좌석을 예약한다.
	int Confirm_password(int no); // 예약된 좌석의 비밀번호를 확인하다.
	void Cancel_Book(); // 선택한 좌석의 예약을 취소한다.
};