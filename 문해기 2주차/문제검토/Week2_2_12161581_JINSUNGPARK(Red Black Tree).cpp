#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;






int main() {

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int M, N, c;
		string command;
		string s;
		int num;
		multiset<int> ms;
		cin >> M >> N;



		for (int j = 0; j < M; j++) {
			cin >> c;
			ms.insert(c);
		}


		for (int j = 0; j < N; j++) {
			cin >> command;

			if (command == "Delete") {
				cin >> s;

				if (s == "min") {
					ms.erase(ms.begin());
				}
				else if (s == "max") {
					ms.erase(--ms.end());
				}
			}
			else if (command == "Add") {
				cin >> num;
				ms.insert(num);
			}
		}

		cout << *(ms.begin()) << " " << *(--ms.end()) << "\n";
		



	}


}