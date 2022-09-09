#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;

char hamming(string s, int N) {
	int Min = 128;
	int MinString = 0;

	for (int i = 0; i < v.size(); i++) {
		int count = 0;

		for (int j = 0; j < N; j++) {
			if (s[j] != v[i][j]) count++;
		}

		if (count < Min) {
			Min = count;
			MinString = i;
		};
	}

	return (65 + MinString);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int M, N, s_length;
		string s;
		string s_result;
		string temp;
		vector<string> v_result;
		cin >> M >> N;

		for (int j = 0; j < M; j++) {

			cin >> s;
			v.push_back(s);
		}

		cin >> s_length >> s_result;
		for (int j = 0; j < s_length; j = j + N) {
			temp = hamming(s_result.substr(j, N), N);
			v_result.push_back(temp);
		}


		for (int j = 0; j < v_result.size(); j++) {
			cout << v_result[j];
		}

		cout << "\n";

		v.clear();

	}
	

}