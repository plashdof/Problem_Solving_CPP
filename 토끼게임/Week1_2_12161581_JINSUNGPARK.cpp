#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int Max = 0;


int putStack(string s, int start) {
	stack<char> q;
	
	

	for (int i = start; i < s.size(); i++) {
		
		if (s[i] == 'C') q.push(s[i]);
		else {
			if (q.empty()) {
				
				return i-start;
			}
			q.pop();
		}

	}

	if (!q.empty()) {
		
		return -1;
	};
	if (q.empty()) {
		
		return -2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;

	cin >> T;
	for (int i = 0; i < T; i++) {
		string S;
		int result;
		int temp;
		cin >> S;


		for (int j = 0; j < S.size(); j++) {
			result = putStack(S, j);
			temp = j;
			if (result > 0) {
				j = result + j;
			}

			if (result == -2) {
				result = S.size() - temp;
			}
			
			if (result > Max) Max = result;
		}

		


		cout << Max << "\n";

		Max = 0;

	}

}