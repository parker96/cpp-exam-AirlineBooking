
#include "AirBooking.h"

AirBooking::AirBooking()
{  // ������ �� �ʱ�ȭ.
	seat[0].time[0] = 7; // 7�� ���
	seat[1].time[0] = 12; // 12�� ���
	seat[2].time[0] = 17; // 17�� ���
}

AirBooking::~AirBooking()
{ // �Ҹ���
	cout << "���� ���񽺸� �����մϴ�.\n" << endl;
	system("pause");
}

/* �ʱ� ȭ�� �� �޴� ���. */
int AirBooking::showmenu(){
	int order; // cin���� ���� (���)���� �����Ͽ� return������ �����մϴ�.

	/* �ʱ� ȭ�� �޴� ���*/
	system("cls"); // ȭ�� �ʱ�ȭ.
	cout << "\n / �Ѽ��װ� ���� �ý��� /\n";
	cout << " 2016/06/12\n";
	cout << " ����(Seoul) -> �λ�(Busan)\n";
	cout << "������������������������������������������\n";
	cout << "��	����� Ƽ�� ���� ����		��\n";
	cout << "������������������������������������������\n";
	cout << "\t<��߽ð�>\t<�ܿ��¼�>\n";
	cout << "������������������������������������������";
	/* ��� �ð��� �ܿ� �¼� ����ϱ�. */
	for (int i = 0; i < 3; i++){
		cout << "\n\t";
		printf("%02d:%02d", seat[i].time[0], seat[i].time[1]);
		cout << "\t\t�ܿ��¼� : " << seat[i].check_rest() << "." << endl;
	}
	cout << "������������������������������������������\n";
	cout << " 1.����     2.��ȸ     3.���     4.����\n";
	cout << ">> ";
	cin >> order; // (���)���� �޴´�.
	return order; // main�� order�� return���ش�.
}

/* �Է��� �ð� ���ڸ� ���ؽ��� ��ȯ�Ͽ� return ���ش�. */
int AirBooking::time_index(int time){
	switch (time){
	case 7:  return 0;	break;
	case 12: return 1;	break;
	case 15: return 2;	break;
	}
	return -1; // ���� ���� ���� ���� ������ -1 return.
}