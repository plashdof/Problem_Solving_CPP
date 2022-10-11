#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int arr[1000000] = {0};
int arr_size;



int main() {

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int M, N, c;
		string command;
		string s;
		int num;
		cin >> M >> N;

		arr_size = M;

		
		for (int j = 0; j < M; j++) {
			cin >> c;
			arr[j] = c;
		}

		sort(arr, arr + arr_size);
		int s_index = 0;
		int e_index = arr_size - 1;


		for (int j = 0; j < N; j++) {
			cin >> command;

			if (command == "Delete") {
				cin >> s;

				if (s == "min") {
					arr[s_index] = 0;
					s_index++;
				}
				else if (s == "max") {
					arr[e_index] = 0;
					e_index--;
				}
			}
			else if (command == "Add") {
				cin >> num;
				arr[e_index + 1] = num;
				e_index++;
				sort(arr + s_index, arr + e_index+1);
			}
		}
		

		cout << arr[s_index] << " " << arr[e_index] << "\n";

		for (int j = s_index; j < e_index; j++) {
			arr[j] = 0;
		}

	}


}