#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(vector< vector<int> > &A);
bool is_existing_country(vector< vector<int> > &A, vector< vector<int> > &B, vector<int> &current_pos);
void extend_country(vector< vector<int> > &A, vector< vector<int> > &B, vector<int> &position);
vector<int> next(vector< vector<int> > &A, vector< vector<int> > &B, vector<int> &current_pos);
bool hasNext(vector< vector<int> > &A, vector< vector<int> > &B, vector<int> &current_pos);
void print(vector< vector<int> > &V);


int main() {
	//vector< vector<int> > A = {
	//	{ 5, 4, 4 },
	//	{ 4, 3, 4 },
	//	{ 3, 2, 4 },
	//	{ 2, 2, 2 },
	//	{ 3, 3, 4 },
	//	{ 1, 4, 4 },
	//	{ 4, 1, 1 }
	//};

	vector< vector<int> > A = {
		{ 6, 5, 4, 4 },
		{ 4, 4, 3, 4 },
		{ 1, 3, 2, 4 },
		{ 5, 4, 2, 4 },
		{ 9, 4, 3, 4 },
		{ 7, 4, 4, 4 },
		{ 1, 4, 4, 4 }
	};

	int result = solution(A);
	cout << "num of country is " << result << endl << endl;
}


int solution(vector< vector<int> > &A) {
	int num_row = A.size();
	int num_col = A[0].size();

	if (num_row < 2 && num_col < 2)
		return min(num_row, num_col);

	vector< vector<int> > B(num_row, vector<int>(num_col, -1));
	int num_country = 0;
	vector<int> current_pos(2);

	for (int row = 0; row < num_row; row++) {
		for (int col = 0; col < num_col; col++) {
			if (B[row][col] == -1) {
				current_pos[0] = row;
				current_pos[1] = col;
				if (!is_existing_country(A, B, current_pos)) {
					num_country++;
					B[current_pos[0]][current_pos[1]] = num_country;
				}

				print(B);

				extend_country(A, B, current_pos);
			}
		}
	}

	return num_country;
}


// Extend the same country from position.
void extend_country(vector< vector<int> > &A, vector< vector<int> > &B, vector<int> &position) {
	int num_row = B.size();
	int num_col = B[0].size();

	stack<vector<int>> stack_pos;
	stack_pos.push(position);

	while (!stack_pos.empty()) {
		vector<int> current_pos = stack_pos.top();
		stack_pos.pop();

		while (hasNext(A, B, current_pos)) {
			vector<int> next_pos = next(A, B, current_pos);
			stack_pos.push(current_pos);
			current_pos = next_pos;

			print(B);
		}
	}
}


// Check if position is existing country.
// If so, label it.
bool is_existing_country(vector< vector<int> > &A, vector< vector<int> > &B, vector<int> &position) {
	int num_row = B.size();
	int num_col = B[0].size();
	int x = position[0];
	int y = position[1];

	if (y < num_col - 1 && B[x][y + 1] != -1 && A[x][y] == A[x][y + 1]) {
		B[x][y] = B[x][y + 1];
		return true;
	}
	if (x < num_row - 1 && B[x + 1][y] != -1 && A[x][y] == A[x + 1][y]) {
		B[x][y] = B[x + 1][y];
		return true;
	}
	if (y > 0 && B[x][y - 1] != -1 && A[x][y] == A[x][y - 1]) {
		B[x][y] = B[x][y - 1];
		return true;
	}
	if (x > 0 && B[x - 1][y] != -1 && A[x][y] == A[x - 1][y]) {
		B[x][y] = B[x - 1][y];
		return true;
	}

	return false;
}


vector<int> next(vector< vector<int> > &A, vector< vector<int> > &B, vector<int> &current_pos) {
	int num_row = B.size();
	int num_col = B[0].size();
	int x = current_pos[0];
	int y = current_pos[1];

	vector<int> next_pos(2);

	if (y < num_col - 1 && B[x][y + 1] == -1 && A[x][y] == A[x][y + 1]) {
		B[x][y + 1] = B[x][y];
		next_pos[0] = x;
		next_pos[1] = y + 1;
		return next_pos;
	}
	if (x < num_row - 1 && B[x + 1][y] == -1 && A[x][y] == A[x + 1][y]) {
		B[x + 1][y] = B[x][y];
		next_pos[0] = x + 1;
		next_pos[1] = y;
		return next_pos;
	}
	if (y > 0 && B[x][y - 1] == -1 && A[x][y] == A[x][y - 1]) {
		B[x][y - 1] = B[x][y];
		next_pos[0] = x;
		next_pos[1] = y - 1;
		return next_pos;
	}
	if (x > 0 && B[x - 1][y] == -1 && A[x][y] == A[x - 1][y]) {
		B[x - 1][y] = B[x][y];
		next_pos[0] = x - 1;
		next_pos[1] = y;
		return next_pos;
	}

	return next_pos;
}


bool hasNext(vector< vector<int> > &A, vector< vector<int> > &B, vector<int> &current_pos) {
	int num_row = B.size();
	int num_col = B[0].size();
	int x = current_pos[0];
	int y = current_pos[1];

	if (y < num_col - 1 && B[x][y + 1] == -1 && A[x][y] == A[x][y + 1]) {
		return true;
	}
	if (x < num_row - 1 && B[x + 1][y] == -1 && A[x][y] == A[x + 1][y]) {
		return true;
	}
	if (y > 0 && B[x][y - 1] == -1 && A[x][y] == A[x][y - 1]) {
		return true;
	}
	if (x > 0 && B[x - 1][y] == -1 && A[x][y] == A[x - 1][y]) {
		return true;
	}

	return false;
}


void print(vector< vector<int> > &V) {
	int num_row = V.size();
	int num_col = V[0].size();

	for (int i = 0; i < num_row; i++) {
		for (int j = 0; j < num_col; j++) {
			cout.width(3);
			cout << V[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl;	
}