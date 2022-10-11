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

		// 문제에서의 m의 범위가 10^10 까지이므로 long long 자료형으로 설정
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

			// 상위자리수 저장
			if (i >= 1) {
				up_num = s[i - 1] - '0';
			}
			

			// 자리수 5 초과시
			if (num > 5) {
				if (i == 0) {	// 최상위 자리수 5 초과시에 대한 예외처리
					count = count + 11 - num;	// 11 - num 을 더함
				}
				else {
					count = count + 10 - num;
					m = m + pow(10, indic + 1) - num * pow(10, indic);	
					s = to_string(m);
				}
			}
			else if(num < 5) {		// 자리수 5 미만시
				count = count + num;
			}
			else {					// 자리수 5 일경우
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