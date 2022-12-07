#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		stack<int> s;
		string ss;
		int temp = 0;
		int numindex = 0;
		int calindex = 1;
		int s1 = 0;
		int s2 = 0;

		cin >> ss;



		for (int j = 0; j < ss.size(); j++) {
			temp = ss[j] - '0';
			if (1 <= temp && temp <= 9) {
				s.push(temp);
			}
			else {
				if (ss[j] == '+') {
					s1 = s.top();
					s.pop();
					s2 = s.top();
					s.pop();

					s.push(s1 + s2);

				}
				else if (ss[j] == '-') {
					s1 = s.top();
					s.pop();
					s2 = s.top();
					s.pop();
					s.push(s2 - s1);
				}
				else if (ss[j] == '*') {
					s1 = s.top();
					s.pop();
					s2 = s.top();
					s.pop();
					s.push(s1 * s2);
				}
			}
		}

		cout << s.top() << "\n";



	}

}