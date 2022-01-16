
#include "Seats.h"
using namespace std;

Seats::Seats()
{ // 생성자 및 초기화
	this->time[0] = 0; // 시
	this->time[1] = 0; // 분
}

Seats::~Seats(){} // 소멸자

/* 잔여 좌석 수를 계산하여 return값으로 전달합니다. */
int Seats::check_rest(){
	int rest = SEAT_MAX; // 잔여 좌석 수를 #define한 'SEAT_MAX'으로 초기화 합니다.

	/*  예약하여 값이 존재하면 잔여 좌석의 수를 계산합니다. */
	for (int i = 0; i < SEAT_MAX; i++)	if (seats[i][0].length() > 0) rest--;
	return rest;
}

/* 선택한 출발 시간 항공편의 좌석 현황 출력 */
void Seats::print_seats(){
	cout << "\n " << time[0] << "시 항공편>>\n";
	for (int i = 0; i < 63; i++)	cout << "-";
	cout << endl;
	for (int i = 0; i < SEAT_MAX; i++)	cout << " " << i + 1 << " [ " << seats[i][0] << " ] ";
	cout << endl;
	for (int i = 0; i < 63; i++)	cout << "-";
	cout << endl;
}

/* 선택한 출발시간의 항공편 좌석을 선택하여 예약한다. */
void Seats::Book_seats(){
	int no = 0; // 선택한 좌석 번호.
	Seats::print_seats(); // 선택한 출발 시간의 항공편 좌석 현황 출력.
	do{
		// 만약 선택한 좌석이 이미 예약되어 있다면 출력.
		if ((seats[no - 1][0].length() > 0) && (no != NULL))	cout << "선택한 좌석이 이미 예약되어있습니다.";
		cout << "\n 예약하실 좌석을 입력해주세요. (작업 취소 : 0)\n>> ";
		cin >> no; // 예약자가 선택한 좌석 번호 입력.
		if (no == 0){
			"작업을 취소하였습니다.\n";	break; // 중간에 작업을 취소할 경우
		}
	} while ((no > 8) || (seats[no - 1][0].length() > 0));
	// 알맞은 값을 받을 때까지 값을 받는다.
	if (no == 0) { return; } // 0을 입력하여 작업을 취소한다.
	no--;  // 입력한 좌석 번호를 입덱스와 맞게 처리한다.
	cout << " 예약자의 이름을 입력해주세요.\n>>";
	cin >> seats[no][0]; // 예약자의 이름을 입력받는다.
	cout << " 현재 보유하고 계신 질병이 있으십니까?\n 만약 있으시다면 질병명, 없으시면 '0'을 입력하여 주십시오.\n>>";
	cin >> dis[no][0]; // 만약 예약자에게 평소 앓고 있는 지병이 있다면 질병명을 입력받는다.
	if (dis[no][0] != "0"){ // 만약 지병이 있어 질병을 입력하였다면.
		cout << " 질병과 관련하여 복용중인 약을 적어주십니오.\n>>";
		cin >> dis[no][1];
	}
	else{
		dis[no][0] = ""; // 입력한 질병 명이 없을 경우.
	}
	cout << " 설정하실 비밀번호를 입력해주세요.\n>>";
	cin >> seats[no][1]; // 예약 취소시 확인할 비밀번호를 입력받는다.

	/* 예약이 완료되면 완료되었다는 메시지와 예약 정보 및 영수증을 출력한다. */
	if ((seats[no][0].length() > 0) && (seats[no][1].length() > 0)){
		cout << endl << "*성공적으로 예약되었습니다." << endl << endl << endl;
		/* 영수증 출력 */
		for (int i = 0; i < 63; i++)	cout << "-";
		cout << "\n - 비행기 예약 확인증 -\n";
		cout << " * 예약 항공\t:\t한성항공." << endl;
		cout << " * 항공 노선\t:\t서울(Seoul) -> 부산(Busan)." << endl;
		cout << " * 티켓 가격\t:\t1,500,000,000\\.\n" << endl;
		cout << " * 출발 시간\t:\t" << time[0] << "시 " << time[1] << "분." << endl;
		cout << " * 이름\t\t:\t" << seats[no][0] << endl;
		cout << " * 보유 질환\t:\t" << dis[no][0] << endl;
		cout << " * 복용중인 약\t:\t" << dis[no][1] << endl;
		cout << " * 비밀번호\t:\t" << seats[no][1] << endl;

		for (int i = 0; i < 63; i++)	cout << "-";
		cout << "\n";
	}
	else	cout << "예약에 실패하였습니다.\n"; // 예약에 실패할 경우 메시지 출략.
}

/* 선택한 좌석의 비밀번호를 확인한다. */
int Seats::Confirm_password(int no){
	string pw;
	cout << "예약하실때 설정하신 비밀번호를 입력하십시오.\n>> ";
	cin >> pw;
	if (seats[no][1] == pw){ return 1; } // 입력한 비밀번호가 맞다면,
	else{ return 0; } // 입력한 비밀번호가 틀리다면
}

/* 선택한 좌석의 예약을 취소한다.  */
void Seats::Cancel_Book(){
	int no = 0, order = 0;
	Seats::print_seats();
	do{
		cout << "삭제하실 좌석의 번호를 입력하세요. (작업 취소 : 0)\n>> ";
		cin >> no;
	} while ((no > 8) || (seats[no - 1][0].length() == 0));
	// 알맞은 값을 받을 때까지 값을 받는다.
	if (no == 0){ return; }  // 0을 입력하여 작업을 취소한다.
	no--; // 입력한 좌석 번호를 입덱스와 맞게 처리한다.
	for (int i = 0; i < 5; i++){
		if (Seats::Confirm_password(no) == 1){ // 비밀번호를 확인한다.
			/* 비밀번호가 맞다면 취소하는 좌석의 정보를 초기화 한다. */
			seats[no][0] = "";
			seats[no][1] = "";
			cout << " 성공적으로 취소되었습니다.\n";
			break;
		}
		else{
			if (i == 4){  // 비밀번호 입력이 5회 이살일 시.
				cout << " 비밀번호가 5회 이상 틀렸습니다.\n 고객센터로 문의 부탁드립니다.\n";
			}
			else{ // 비밀번호가 틀렸을 경우.
				cout << " 비밀번호가 틀렸습니다(틀린 횟수 : " << i + 1 << ").\n>>";
			}
		}
	}
}