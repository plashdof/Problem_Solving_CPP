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
		
		int n,P;
		int result = -1;
		set<pair<int, int>> temp;
		set<pair<int, int>>::iterator it = temp.end();
		cin >> n;

		for (int j = 1; j <= n; j++) {
			cin >> P;
			
			if (j == 1) {
				cout << -1 << " ";
			}
			else {
				result = -1;
				for (set<pair<int, int>>::iterator it = --temp.end(); it != temp.end(); it--) {
					if (P >= it->first) {
						result = it->second;
						break;
					}
				}

				cout << result << " ";
				
			}
			temp.insert({ P, j });


		}
		cout << "\n";
	}
}