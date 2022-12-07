#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		
		int count = 0;
		int lenght = 0;
		int max = 0;
		for (int k = 0; k < s.size(); k++) {
			for (int j = k; j < s.size(); j++) {
				lenght++;
				if (s[j] == '0') {
					count++;
				}
				else {
					count--;
				}

				if (count == 0) {
					if (lenght > max) max = lenght;
				}
			}
			lenght = 0;
			count = 0;
		}
		cout << max << "\n";
	}

}