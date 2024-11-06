#include<Windows.h>

#include"QueensPlacer.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть розмір шахівниці: ";
	cin >> N;
	
	if (cin.fail()) {
		cerr << "Розмір шахівниці неправильно введено." << endl;
		return 1;
	}

	QueensNPlacer Queens(N);
	
	Queens.solvePlacementSols();
	Queens.printAllSolutions();
	
	return 0;
}