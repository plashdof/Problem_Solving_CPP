#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


vector<int> GCD_factor;



// 유클리드 호제법으로, 두 수의 GCD 구하는 함수 생성

int GCD(int a, int b) {
	while (1) {
		int r = a % b;
		if (r == 0) return b;

		a = b;
		b = r;

	}
}

// 약수 구하는 함수 생성

void factor(int a) {
	if (a <= 0) {
		return;
	}

	GCD_factor.push_back(a);

	for (int i = 1; i <= a / 2; i++) {
		if (a % i == 0) {
			GCD_factor.push_back(i);
		}
	}

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	


	cin >> N;

	// 인하왕국 병사수 n  비룡왕국 병사수 m

	for (int x = 0; x < N; x++) {
		vector<int> inha_vec;
		vector<int> birong_vec;
		int n;
		int m;
		int temp;
		bool flag = false;
		int result1 = -1;
		int result2 = -1;

		cin >> n >> m;

		for (int y = 0; y < n; y++) {
			cin >> temp;
			inha_vec.push_back(temp);
		}

		for (int y = 0; y < m; y++) {
			cin >> temp;
			birong_vec.push_back(temp);
		}

		// 비룡왕국의 병사들 최대공약수 구하기

		if (birong_vec.size() >= 3) {
			temp = GCD(birong_vec[0], birong_vec[1]);

			for (int i = 2; i < birong_vec.size(); i++) {

				temp = GCD(temp, birong_vec[i]);
			}
		}
		else if(birong_vec.size() == 2) {
			temp = GCD(birong_vec[0], birong_vec[1]);
		}
		else {
			temp = birong_vec[0];
		}
		

		// 비룡왕국의 병사 최대공약수의 약수들 구하기
		factor(temp);



		for (int i = 0; i < GCD_factor.size(); i++) {
			for (int j = 0; j < inha_vec.size(); j++) {
				if (inha_vec[j] >= GCD_factor[i] &&  inha_vec[j] % GCD_factor[i] == 0) {
					flag = true;
				}
			}

			if (flag == false) {
				result1 = GCD_factor[i];
			}
		}


		GCD_factor.clear();
		flag = false;


		// 인하왕국의 병사들 최대공약수 구하기

		if (inha_vec.size() >= 3) {
			temp = GCD(inha_vec[0], inha_vec[1]);

			for (int i = 2; i < inha_vec.size(); i++) {

				temp = GCD(temp, inha_vec[i]);
			}
		}
		else if (inha_vec.size() == 2) {
			temp = GCD(inha_vec[0], inha_vec[1]);
		}
		else {
			temp = inha_vec[0];
		}

		

		// 인하왕국의 병사 최대공약수의 약수들 구하기
		factor(temp);



		for (int i = 0; i < GCD_factor.size(); i++) {
			for (int j = 0; j < birong_vec.size(); j++) {
				if (birong_vec[j] >= GCD_factor[i] && birong_vec[j] % GCD_factor[i] == 0) {
					flag = true;
				}
			}

			if (flag == false) {
				result2 = GCD_factor[i];
			}
		}


		cout << result1 << " " << result2 << "\n";


		GCD_factor.clear();
		
	}
}