#include <iostream>
#include <algorithm>

using namespace std;

int arr[5001] = {0};

bool medium(int start, int end, int d, int mid1, int mid2) {
	int darr[5001];
	int counts = 0;
	double medium;

	for (int i = start; i <= end; i++) {
		darr[counts] = arr[i];
		counts++;
	}

	sort(darr, darr + d);

	if (mid2 == -1) {
		medium = darr[mid1];
	}
	else {
		medium = ((double)darr[mid1] + darr[mid2]) / 2;
	}


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
			mid2 = d / 2 ;
		}
		else {
			mid1 = (d - 1) / 2;
			mid2 = -1;
		}


		for (int i = 0; i < n; i++) {
			cin >> arr[i];



			if (i >= d) {
				if (medium(i - d, i - 1, d, mid1, mid2)) {
					count++;
				}
			}
		}




		cout << count << "\n";


		for (int i = 0; i < n; i++) {
			arr[i] = 0;
		}
	}
	
	


}