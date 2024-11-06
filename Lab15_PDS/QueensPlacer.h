#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<intrin.h>

using namespace std;

class QueensNPlacer {
public:
	QueensNPlacer(int n);
	void solvePlacementSols();
	void printAllSolutions();
	vector<vector<vector<int>>> solutions;
private:
	int N;
	vector<vector<int>> board;

	bool canPlaceQueen(int row, int col);
	bool solveUtility(int row, int columnMask, int diag1Mask, int diag2Mask);
	void printChessBoard(const vector<vector<int>>& board);
};

QueensNPlacer::QueensNPlacer(int n) : N(n), board(n, vector<int>(n, 0)) {	};

void QueensNPlacer::solvePlacementSols() {
	solveUtility(0, 0, 0, 0);
}

void QueensNPlacer::printChessBoard(const vector<vector<int>>& board) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] == 1 ? (cout << "Q ") : (cout << ". ");
		}
		cout << endl;
	}
	cout << endl;
}

void QueensNPlacer::printAllSolutions() {
	if (solutions.empty()) {
		cout << "Рішення не знайдено!" << endl;
	}
	else {
		cout << "Знайдено " << solutions.size() << " рішень:" << endl;
		for (size_t i = 0; i < solutions.size(); i++) {
			cout << "Рішення номер " << i + 1 << ":" << endl;
			printChessBoard(solutions[i]);
		}
	}
}

bool QueensNPlacer::canPlaceQueen(int row, int col) {
	for (int i = 0; i < row; i++) {
		if (board[i][col] == 1) {
			return false;
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1 && (abs(row - i) == abs(col - j))) {
				return false;
			}
		}
	}

	return true;
}

bool QueensNPlacer::solveUtility(int row, int columnMask, int diag1Mask, int diag2Mask) {
	if (row == N) {
		solutions.push_back(board);
		return false;
	}

	int availablePositions = ~(columnMask | diag1Mask | diag2Mask) & ((1 << N) - 1);

	while (availablePositions) {
		int col = availablePositions & -availablePositions;
		unsigned long index;
		_BitScanForward(&index, col);

		board[row][index] = 1;
		solveUtility(row + 1, columnMask | col, (diag1Mask | col) << 1, (diag2Mask | col) >> 1);
		board[row][index] = 0;

		availablePositions &= availablePositions - 1;
	}

	return false;
}
