#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// index �� ���ѹ�
int team_score[100001] = {0};
int ranking[100001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n,m,temp;
		cin >> n >> m;
		vector<int> inha_team_ranking;
		vector<int> max_team_ranking;

		for (int j = 1; j <= n; j++) {
			cin >> temp;
			team_score[temp] += n - j + 1;
			ranking[j] = temp;

			if (temp == 1) {
				inha_team_ranking.push_back(j);
			}
		}

		int max = -1;
		int max_team_num = 0;

		for (int j = 1; j <= n; j++) {
			if (team_score[j] >= max) {
				max = team_score[j];
				max_team_num = j;
			}
		}

		int distance = max - team_score[1];

		if (distance < 0) {
			cout << 0 << "\n";
		}
		else {
			
			for (int j = 1; j <= n; j++) {
				if (ranking[j] == max_team_num) {
					max_team_ranking.push_back(ranking[j]);
				}
			}

			

			// TODO ���⼭ inha_team_ranking��  max_team_ranking �� �̿��� ������ ã�ƾ��� (�������� �ƽ������� ��ĭ �Ʒ��ִ°��
			
			int inhaindex = 1;
			int maxindex = 0;

			while (true) {
				if( max_team_ranking[0])
			}




		}

	}

}