#pragma once
#include<iostream>
using namespace std;

void printSol(vector<vector<int>>& Board) {
	for (int i = 0; i < Board.size(); i++) {
		for (int j = 0; j < Board.size(); j++) {
			cout << Board[i][j] << " ";
		}
		cout << "\n";
	}
}

//This is BOUNDING FUNCTION
bool isSafe(vector<vector<int>>& Board, int row, int col) {

	// to check if row to left of queen has no queens
	for (int i = 0; i < col; i++) {
		if (Board[row][i])
			return false;
	}

	// to check if left diagonal has no queens

	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
		if (Board[i][j])
			return false;
	}

	// to check lower diagonal on left side

	for (int i = row + 1, j = col - 1; i < Board.size() && j >= 0; i++, j--) {
		if (Board[i][j])
			return false;
	}

	return true;
}

//this is a recursive function to check if a queens can be placed in any row the col number provided as arguement
bool arrangeNQ(vector<vector<int>>& Board, int col) {
	if (col >= Board.size())
		return true;

	for (int i = 0; i < Board.size(); i++) {
		if (isSafe(Board, i, col)) {
			Board[i][col] = 1;

			if (arrangeNQ(Board, col + 1))
				return true;

			Board[i][col] = 0; /*BACKTRACKING (if placing
								queens like this way doesn't
								produce true then it backtracks
								and make the whole Board which
								were filled with queens(1) to zero.
								this is backtracking.*/
		}
	}
	return false;
}

void solveNQ() {
	int N;
	cout << "Enter the number of Queens : ";
	cin >> N;

	vector<vector<int>>Board(N, vector<int>(N, 0));
	if (arrangeNQ(Board, 0) == true) {
		printSol(Board);
	}

}