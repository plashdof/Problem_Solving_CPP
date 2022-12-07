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

		int tosun = 0;
		int biryoung = X;
		bool rest = false;
		int time = 0;

		while (true) {
			time++;
			if (rest) {
				biryoung++;
				if (time == B) {
					rest = false;
					time = 0;
				}
			}
			else {
				tosun += 2;
				biryoung++;
				if (time == A) {
					rest = true;
					time = 0;
				}
			}

			if (biryoung == tosun) {
				cout << biryoung << "\n";
				break;
			}


		}
	}
}