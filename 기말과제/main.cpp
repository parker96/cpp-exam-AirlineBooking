
#include "AirBooking.h" // class AirBooking.
#include <windows.h> // Sleep()�Լ� ȣ��
void main(){
	AirBooking ticket; // ���� Ŭ������ AirBooking�� ��ü ticket�� �����մϴ�.
	int order = 0, time = 0; // �̿��ڰ� �Է��� (���)���� �����մϴ�.
	do{ // 1 -> ����, 2 -> ��ȸ, 3 -> ���, 4 -> ����.
		order = ticket.showmenu();
		// �޴� �� �������� ����ϸ� (���)���� �޾� order�� ���� �����մϴ�.
		switch (order){
		case 1: // ���� �ϱ�
			do{
				cout << "���Ͻô� ��� �ð��� �Է��� �ּ���.\n>> ";
				cin >> time;
			} while ((time != 7) && (time != 12) && (time != 17));
			// ��Ȯ�� ���� �Է��� ������ �Է��� �޴´�.
			system("cls");
			ticket.seat[ticket.time_index(time)].Book_seats();
			system("pause");
			break;
		case 2: // ��ȸ
			do{
				cout << "��ȸ�� ���Ͻô� ��� �ð��� �Է��� �ּ���.\n>> ";
				cin >> time;
			} while ((time != 7) && (time != 12) && (time != 17));
			// ��Ȯ�� ���� �Է��� ������ �Է��� �޴´�.
			system("cls");
			cout << "��ȸ��...";
			Sleep(2000); // 2�� �Ŀ� ��ȸ ȭ�� ���.
			cout << " \n" << time << "�� �װ��� ��ȸ �����Ͽ����ϴ�." << endl;
			ticket.seat[ticket.time_index(time)].print_seats();
			system("pause");
			break;
		case 3: // ���
			do{
				cout << "�����Ͻ� ��� �ð��� �Է��� �ּ���.\n>> ";
				cin >> time;
			} while ((time != 7) && (time != 12) && (time != 17));
			// ��Ȯ�� ���� �Է��� ������ �Է��� �޴´�.
			system("cls");
			ticket.seat[ticket.time_index(time)].Cancel_Book();
			system("pause");
			break;
		case 4: // ����
			break;
		}
	} while (order != 4); // ����ڰ� ����(��ɰ� : 4)�� �Է��Ҷ����� do{...}�۾��� �ݺ��մϴ�.
}