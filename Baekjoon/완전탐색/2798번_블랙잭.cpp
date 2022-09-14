#include <iostream>
#include <vector>
using namespace std;



int main() {
	int N, M;
	int num;
	int max = -1;
	vector<int> v;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < N-2; i++) {
		for (int j = i + 1; j < N-1; j++) {
			for (int k = j + 1; k < N; k++) {
				if (v[i] + v[j] + v[k] > M) continue;
				if (max < v[i] + v[j] + v[k]) max = v[i] + v[j] + v[k];
			}
		}
	}

	cout << max;

}