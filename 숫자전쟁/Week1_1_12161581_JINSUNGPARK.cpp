#include <iostream>
#include <vector>
#include <cmath>
using namespace std;






int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int n;
	int m;
	int temp;
	
	
	cin >> N;

	// 인하왕국 병사수 n  비룡왕국 병사수 m

	for (int x = 0; x < N; x++) {
		vector<int> inha_vec;
		vector<int> birong_vec;
		vector<int> inha_GDC_vec;
		vector<int> birong_GDC_vec;

		cin >> n >> m;

		for (int y = 0; y < n; y++) {
			cin >> temp;
			inha_vec.push_back(temp);
		}

		for (int y = 0; y < m; y++) {
			cin >> temp;
			birong_vec.push_back(temp);
		}

		int Min = 100000000;
		int min = 0;
		bool count1 = true;
		bool count2 = true;
		int inha_result = 0;
		int birong_result = 0;
		int GDC = 0;


		for (int i = 0; i < birong_vec.size(); i++) {
			if (birong_vec[i] < Min) Min = birong_vec[i];
		}

		min = Min;


		// 비룡왕국의 병사들 최대공약수 구하기

		for (int i = min; i >= 2; i--) {
			for (int j = 0; j < birong_vec.size(); j++) {
				if (birong_vec[j] % i != 0) {
					count1 = false;
					break;
				}
			}

			if (count1 == true) {
				GDC = i;
				break;
			}
			
			count1 = true;
		}

		// 비룡왕국의 병사들 최대공약수의 약수들 구하기

		for (int i = GDC; i >= 1; i--) {
			if (GDC % i == 0) birong_GDC_vec.push_back(i);
		}

		// 최대공약수의 약수들중, 인하왕국 병사의 약수 아닌것 판별

		for (int i = 0; i < birong_GDC_vec.size(); i++) {
			for (int j = 0; j < inha_vec.size(); j++) {
				if (inha_vec[j] > birong_GDC_vec[i] && inha_vec[j] % birong_GDC_vec[i] == 0) {
					count2 = false;
					break;
				}
			}

			if (count2 == true) {
				inha_result = birong_GDC_vec[i];
				break;
			}

			count2 = true;
		}


		Min = 100000000;
		min = 0;

		for (int i = 0; i < inha_vec.size(); i++) {
			if (inha_vec[i] < Min) Min = inha_vec[i];
		}
		min = Min;


		// 인하왕국의 병사들 최대공약수 구하기
		count1 = true;

		for (int i = min; i >= 2; i--) {
			for (int j = 0; j < inha_vec.size(); j++) {
				if (inha_vec[j] % i != 0) {
					count1 = false;
					break;
				}
			}

			if (count1 == true) {
				GDC = i;
				break;
			}

			count1 = true;
		}

		// 비룡왕국의 병사들 최대공약수의 약수들 구하기

		for (int i = GDC; i >= 1; i--) {
			if (GDC % i == 0) inha_GDC_vec.push_back(i);
		}

		// 최대공약수의 약수들중, 인하왕국 병사의 약수 아닌것 판별

		count2 = true;

		for (int i = 0; i < inha_GDC_vec.size(); i++) {
			for (int j = 0; j < birong_vec.size(); j++) {
				if (birong_vec[j] > inha_GDC_vec[i] && birong_vec[j] % inha_GDC_vec[i] == 0) {
					count2 = false;
					break;
				}
			}

			if (count2 == true) {
				birong_result = inha_GDC_vec[i];
				break;
			}

			count2 = true;
		}

		if (inha_result == 0) inha_result = -1;
		if (birong_result == 0) birong_result = -1;

		cout << inha_result << " " << birong_result << "\n";
		
	}

	

}