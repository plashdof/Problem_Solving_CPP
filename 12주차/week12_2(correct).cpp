#include <iostream>
#include <set>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {

		int n, P;
		int result = -1;
		set<pair<int, int>> temp;
		set<pair<int, int>>::iterator iter = temp.end();
		pair<set<pair<int, int>>::iterator, bool> it;
		cin >> n;

		for (int j = 1; j <= n; j++) {
			cin >> P;
			it = temp.insert({ P, j });
			if (j == 1) {
				cout << -1 << " ";
			}
			else {
				--it.first;
				if (it.first == iter) {
					cout << -1 << " ";
				}
				else {
					cout << it.first->second << " ";
				}

			}
			
		}
		cout << "\n";
	}
}