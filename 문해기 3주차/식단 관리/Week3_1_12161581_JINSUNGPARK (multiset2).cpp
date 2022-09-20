#include <iostream>
#include <algorithm>
#include <set>



using namespace std;

int arr[5001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	for (int x = 0; x < T; x++) {
		int n, d;
		int count = 0;
		int temp;
		int mid1;
		int mid2;
		double medium;
		multiset<int> ms;
		


		cin >> n >> d;

		if (d % 2 == 0) {
			mid1 = d / 2 - 1;
			mid2 = d / 2;
		}
		else {
			mid1 = (d - 1) / 2;
			mid2 = -1;
		}

		cin >> temp;
		ms.insert(temp);
		arr[0] = temp;

		std::multiset<int>::iterator it_seek = ms.begin();
		
		
		
		for (int i = 1; i < n; i++) {
			
			cin >> arr[i];
			
			// 초기 중앙값 찾는 로직. i>=d 부터는 필요없음
			
			if (i <= mid1) {
				if (arr[i] > *it_seek) {
					it_seek++;
				};
			}
			else if(i < d) {
				if (arr[i] < *it_seek) {
					it_seek--;
				} 
			}


			if (i >= d) {
				std::multiset<int>::iterator it_seek_next = ++it_seek;
				--it_seek;

				if (mid2 == -1) medium = *it_seek;
				else medium = ((double)(*it_seek) + (*it_seek_next)) / 2;

				if (arr[i] >= medium * 2) count++;


				if (arr[i - d] <= *it_seek && arr[i] > *it_seek) {
					++it_seek;
				}
				if (arr[i - d] > *it_seek && arr[i] <= *it_seek) {
					--it_seek;
				}
			}

			ms.insert(arr[i]);
			if (it_seek == ms.end()) {
				it_seek = ms.begin();
			} 

			
		}

	

		cout << count << "\n";
		
		for (int i = 0; i < n; i++) {
			arr[i] = 0;
		}

		
	}
}