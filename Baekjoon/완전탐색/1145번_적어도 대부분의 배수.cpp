#include <iostream>
#include <climits>
using namespace std;





int GCD(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int LCM(int a, int b) {
	return (a * b) / GCD(a, b);
}

int main() {
	int arr[6] = { 0 };
	int temp = 0;
	int min = INT_MAX;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			for (int k = j + 1; k < 5; k++) {
				temp = LCM(arr[i], arr[j]);
				temp = LCM(temp, arr[k]);
				if (min > temp) min = temp;
			}
		}
	}


	cout << min;

}