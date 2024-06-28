#include<iostream>
using namespace std;

int main() {
	int arr[10][10] = { 0 };
	int x, y;
	cin >> x >> y;
	arr[x][y] = 1;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}