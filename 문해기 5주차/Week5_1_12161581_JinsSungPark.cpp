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

		// 25���ϸ� ��Ÿ�ӿ���
		int arr[26] = { 0 };
		bool flag = true;


		cin >> origin >> attacked;

		// �������ڿ� �ش�Ǵ� �迭�ε����� 1�̵�
		for (int j = 0; j < origin.size(); j++) {
			arr[origin[j] - 'A'] = 1;
		}



		// origin �� ���� ���� attacked �� ���ð�� NO
		// origin �� �ִ¹��� attacked �� ���°�� NO


		for (int j = 0; j < attacked.size(); j++) {

			// origin �� ���¹��� atacked�� ���ð�� flag false ��
			if (arr[attacked[j] - 'A'] == 0) {
				flag = false;
				break;
			}

			// origin �� �ִ¹��� attacked�� ���ð��, 2�� ǥ��.
			if (arr[attacked[j] - 'A'] == 1) {
				arr[attacked[j] - 'A'] = 2;
				continue;
			}

		}

		// orogin �� �ִ¹��ڰ� attacked�� �ȳ��´ٸ�, flag false��
		// <27���ϸ� WRONG ANSWER
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