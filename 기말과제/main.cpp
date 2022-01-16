
#include "AirBooking.h" // class AirBooking.
#include <windows.h> // Sleep()함수 호출
void main(){
	AirBooking ticket; // 예약 클래스인 AirBooking의 객체 ticket을 생성합니다.
	int order = 0, time = 0; // 이용자가 입력한 (명령)값을 저장합니다.
	do{ // 1 -> 예약, 2 -> 조회, 3 -> 취소, 4 -> 종료.
		order = ticket.showmenu();
		// 메뉴 및 스케줄을 출력하며 (명령)값을 받아 order에 값을 저장합니다.
		switch (order){
		case 1: // 예약 하기
			do{
				cout << "원하시는 출발 시간을 입력해 주세요.\n>> ";
				cin >> time;
			} while ((time != 7) && (time != 12) && (time != 17));
			// 정확한 값을 입력할 때까지 입력을 받는다.
			system("cls");
			ticket.seat[ticket.time_index(time)].Book_seats();
			system("pause");
			break;
		case 2: // 조회
			do{
				cout << "조회를 원하시는 출발 시간을 입력해 주세요.\n>> ";
				cin >> time;
			} while ((time != 7) && (time != 12) && (time != 17));
			// 정확한 값을 입력할 때까지 입력을 받는다.
			system("cls");
			cout << "조회중...";
			Sleep(2000); // 2초 후에 조회 화면 출력.
			cout << " \n" << time << "시 항공편 조회 성공하였습니다." << endl;
			ticket.seat[ticket.time_index(time)].print_seats();
			system("pause");
			break;
		case 3: // 취소
			do{
				cout << "예약하신 출발 시간을 입력해 주세요.\n>> ";
				cin >> time;
			} while ((time != 7) && (time != 12) && (time != 17));
			// 정확한 값을 입력할 때까지 입력을 받는다.
			system("cls");
			ticket.seat[ticket.time_index(time)].Cancel_Book();
			system("pause");
			break;
		case 4: // 종료
			break;
		}
	} while (order != 4); // 사용자가 종료(명령값 : 4)를 입력할때까지 do{...}작업을 반복합니다.
}