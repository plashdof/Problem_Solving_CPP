#include <iostream>
#include <algorithm>
#include <set>;
using namespace std;


int arrW[501];
int arrV[501];
int arr[100001] = {0};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	int N, K;
	int temp;
	cin >> T;


	for (int i = 0; i < T; i++) {
		int result = 0;
		set<int> s;

		cin >> N >> K;

		for (int j = 0; j < N; j++) {
			cin >> arrW[j];
		}

		for (int j = 0; j < N; j++) {
			cin >> temp;

			arr[temp / arrW[j]] = arr[temp/arrW[j]] + arrW[j];   // index �� �ִ빫��,  ���� 1kg�� ������

			s.insert(temp / arrW[j]);
		}

		std::set<int>::iterator it = --s.end();



		//  *it : kg �� ����
		//  arr[*it] : �ش� ��ŷ��� �ִ� ����

		while (it != s.end()) {
			if (arr[*it]  < K) {
				result += arr[*it] * (*it);
				K -= arr[*it];
				--it;
				continue;
			}
			else if (arr[*it] == K) {
				result += arr[*it] * (*it);
				break;
			}
			else {
				result += K * (*it);
				break;
			}
		}

		it = s.begin();

		while (it != s.end()) {
			arr[*it] = 0;
			++it;
		}


		cout << result << "\n";

	}


	return 0;
}