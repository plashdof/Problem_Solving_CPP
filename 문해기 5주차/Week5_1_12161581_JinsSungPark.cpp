#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string origin;
		string attacked;

		// 25로하면 런타임에러
		int arr[26] = { 0 };
		bool flag = true;


		cin >> origin >> attacked;

		// 원본문자에 해당되는 배열인덱스가 1이됨
		for (int j = 0; j < origin.size(); j++) {
			arr[origin[j] - 'A'] = 1;
		}



		// origin 에 없는 문자 attacked 에 나올경우 NO
		// origin 에 있는문자 attacked 에 없는경우 NO


		for (int j = 0; j < attacked.size(); j++) {

			// origin 에 없는문자 atacked에 나올경우 flag false 로
			if (arr[attacked[j] - 'A'] == 0) {
				flag = false;
				break;
			}

			// origin 에 있는문자 attacked에 나올경우, 2로 표시.
			if (arr[attacked[j] - 'A'] == 1) {
				arr[attacked[j] - 'A'] = 2;
				continue;
			}

		}

		// orogin 에 있는문자가 attacked에 안나온다면, flag false로
		// <27로하면 WRONG ANSWER
		for (int j = 0; j < 26; j++) {
			if (arr[j] == 1) {
				flag = false;
				break;
			}
		}

		if (flag) cout << "YES" << "\n";
		else cout << "NO" << "\n";


	}


	return 0;
}