
#include "AirBooking.h"

AirBooking::AirBooking()
{  // 생성자 및 초기화.
	seat[0].time[0] = 7; // 7시 출발
	seat[1].time[0] = 12; // 12시 출발
	seat[2].time[0] = 17; // 17시 출발
}

AirBooking::~AirBooking()
{ // 소멸자
	cout << "예약 서비스를 종료합니다.\n" << endl;
	system("pause");
}

/* 초기 화면 및 메뉴 출력. */
int AirBooking::showmenu(){
	int order; // cin으로 받은 (명령)값을 저장하여 return값으로 전달합니다.

	/* 초기 화면 메뉴 출력*/
	system("cls"); // 화면 초기화.
	cout << "\n / 한성항공 예약 시스템 /\n";
	cout << " 2016/06/12\n";
	cout << " 서울(Seoul) -> 부산(Busan)\n";
	cout << "┌───────────────────┐\n";
	cout << "│	비행기 티켓 예약 서비스		│\n";
	cout << "└───────────────────┘\n";
	cout << "\t<출발시간>\t<잔여좌석>\n";
	cout << "┌───────────────────┐";
	/* 출발 시간별 잔여 좌석 출력하기. */
	for (int i = 0; i < 3; i++){
		cout << "\n\t";
		printf("%02d:%02d", seat[i].time[0], seat[i].time[1]);
		cout << "\t\t잔여좌석 : " << seat[i].check_rest() << "." << endl;
	}
	cout << "└───────────────────┘\n";
	cout << " 1.예약     2.조회     3.취소     4.종료\n";
	cout << ">> ";
	cin >> order; // (명령)값을 받는다.
	return order; // main에 order에 return해준다.
}

/* 입력한 시간 숫자를 인텍스로 변환하여 return 해준다. */
int AirBooking::time_index(int time){
	switch (time){
	case 7:  return 0;	break;
	case 12: return 1;	break;
	case 15: return 2;	break;
	}
	return -1; // 위에 맞지 않은 값이 없을시 -1 return.
}