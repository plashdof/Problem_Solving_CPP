#include <iostream>
#include <algorithm>
#include <set>



using namespace std;

int arr[5001] = {0};


bool warning(int start, int end, int mid1, int mid2) {
	multiset<int> ms;
	ms.insert(arr[start]);
	int count = 0;
	double medium = 0;
	std::multiset<int>::iterator it = ms.begin();

	for (int i = start+1; i <= end; i++) {
		ms.insert(arr[i]);
		count++;
		
		if (count <= mid1) {
			if (arr[i] < *it) {
				
			}
			else {
				it++;
			}
		}

		if (count > mid1) {
			if (arr[i] < *it) {
				it--;
			}
			
		}
	}
	if (mid2 == -1) medium = *it;
	else medium = ((double) * it + *(++it)) / 2;

	if (arr[end + 1] >= medium * 2) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	for (int x = 0; x < T; x++) {
		int n, d;
		int count = 0;
		int mid1;
		int mid2;


		cin >> n >> d;

		if (d % 2 == 0) {
			mid1 = d / 2 - 1;
			mid2 = d / 2;
		}
		else {
			mid1 = (d - 1) / 2;
			mid2 = -1;
		}
		
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		for (int i = d; i < n; i++) {
			if(warning(i - d, i - 1, mid1, mid2)) count++;
		}

		cout << count << "\n";

		for (int i = 0; i < n; i++) {
			arr[i] = 0;
		}
	}
}