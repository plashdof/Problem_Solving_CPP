#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		long long m;
		int num;
		int up_num;
		int count = 0;
		int indic = 0;
		string s;
		cin >> m;
		s = to_string(m);
		int size = s.size();
		
 		for (int i = size-1; i >= 0; i--) {
			num = s[i] - '0';
			if (i >= 1) {
				up_num = s[i - 1] - '0';
			}
			
			if (num > 5) {
				if (i == 0) {
					count = count + 11 - num;
				}
				else {
					count = count + 10 - num;
					m = m + pow(10, indic + 1) - num * pow(10, indic);
					s = to_string(m);
				}
			}
			else if(num < 5) {
				count = count + num;
			}
			else {
				if (i == 0) {
					count = count + num;
				}
				else {
					if (up_num >= 5) {
						count = count + 10 - num;
						m = m + pow(10, indic + 1) - num * pow(10, indic);
						s = to_string(m);
					}
					else {
						count = count + num;
					}
				}
				
			}

			indic++;
		}


		cout << count << "\n";
		

	}


}