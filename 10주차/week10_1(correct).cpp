#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N,temp;
		int p, q, X;
		long long sum = 0;
		int count = 0;
		vector<int> v;

		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> temp;
			v.push_back(temp);
			sort(v.begin(), v.end());
		}

		cin >> p >> q >> X;

		do {
			sum = 0;
			for (int j = 0; j < N; j++) {
				sum += v[j] * pow(X, j);
			}
			sum = sum % 1013;

			if (sum >= p && sum <= q) {
				count++;
			}
		} while (next_permutation(v.begin(), v.end()));

		cout << count << "\n";

	}

}