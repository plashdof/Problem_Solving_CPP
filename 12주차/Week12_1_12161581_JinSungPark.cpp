#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int X, A, B;
		cin >> X >> A >> B;

		int biryoung = X;
		int tosun = 0;
		int time = 0;

		// ����̰� ������ �Ƚ����� ����
		bool rest = false;

		while (biryoung != tosun) {
			if (!rest) {
				time++;
				tosun += 2;
				biryoung += 1;
				if (time == A) {
					rest = true;
					time = 0;
				}
			}
			else {
				time++;
				biryoung += 1;
				if (time == B) {
					rest = false;
					time = 0;
				}
			}
		}

		cout << biryoung << "\n";
	}
}