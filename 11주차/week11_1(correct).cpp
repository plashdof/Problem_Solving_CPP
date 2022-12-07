#include <iostream>
#include <cmath>
using namespace std;


long long zero[33] = { 0 };
long long one[33] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	zero[1] = 0;
	one[1] = 1;

	for (int j = 2; j <= 32; j++) {

		// n자리수의 0개수는 직전자리수의 0개수 + 1개수
		zero[j] = zero[j - 1] + one[j - 1];

		// n자리수의 1개수는 0개수 + 2^(n-1)
		one[j] = zero[j] + (long long)(pow(2, j - 1));
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		long long N;
		cin >> N;
		int k = 1;
		while (true) {
			if (N == (long long)(pow(2, k))) {
				break;
			}
			k++;
		}
		long long result_zero = 0;
		long long result_one = 0;

		if (N >= 4) {
			for (int j = 1; j <= k; j++) {
				result_zero += zero[j];
				result_one += one[j];
			}
			result_zero += k;
			result_one += 1;
		}
		else {
			result_zero = 1;
			result_one = 2;
		}

		cout << result_zero << " " << result_one << "\n";


	}



}


/*
(1,2) + (2,3) + (5,8) + (9, 20) + (27, 47)

1 : (0,1)
10 11 : (1, 3)
100 101 110 111 : (4, 8)
1000 1001 1010 1011 1100 1101 1110 1111 : (12, 20)
10000 10001 10010 10011 10100 10101 10110 10111 11000 11001 11010 11011 11100 11101 11110 11111 : (32, 48)
 n자리수 : (x , x + 2^n-1)  x 는 직전자리수의 0개수 + 1개수

*/