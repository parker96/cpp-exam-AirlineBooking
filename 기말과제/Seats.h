
#include <iostream>
#include <string>
#define SEAT_MAX 8
using namespace std;

class Seats
{
public:
	int time[2]; // ����ϴ� �ð� ������. [0] = ��, [1] = ��
	string seats[SEAT_MAX][2]; // �¼� ������. [0] = ������ �̸�, [1] = ��й�ȣ.
	string dis[SEAT_MAX][2]; // ������ ���� ������. [0] = �������� ����, [1] = �������� ��.

	Seats(); // Ŭ���� ������
	~Seats();// Ŭ���� �Ҹ���

	int check_rest(); // ���� �¼� ���� Ȯ���Ѵ�.
	void print_seats();// �¼��� ��Ȳ�� ����Ѵ�.
	void Book_seats(); // ������ �¼��� �����Ѵ�.
	int Confirm_password(int no); // ����� �¼��� ��й�ȣ�� Ȯ���ϴ�.
	void Cancel_Book(); // ������ �¼��� ������ ����Ѵ�.
};