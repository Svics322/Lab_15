#include<Windows.h>

#include"QueensPlacer.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "������ ����� ���������: ";
	cin >> N;
	
	if (cin.fail()) {
		cerr << "����� ��������� ����������� �������." << endl;
		return 1;
	}

	QueensNPlacer Queens(N);
	
	Queens.solvePlacementSols();
	Queens.printAllSolutions();
	
	return 0;
}