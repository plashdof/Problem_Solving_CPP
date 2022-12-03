#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;


// team ��ȣ�� indexing ���� ->  
int team_score[100001] = {0};

pair<int,int> team_data[100001];


bool compare(int a, int b) {
	if (team_data[a].first > team_data[b].first) return false;
	else return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {

		int n, m, current_temp, before_temp;

		cin >> n >> m;
		vector<int> fight_opponent;
		set<pair<int, int>> team_ranking;

		for (int j = 1; j <= n; j++) {
			cin >> current_temp;

			// ���������� �ѵ�� ���� ������ ����ȣ�� vector�� ����
			if (j > 1 && current_temp == 1) {
				fight_opponent.push_back(before_temp);
			}

			before_temp = current_temp;
			
			// team score�� ����ȣ�� indexing �Ͽ� ���
			team_score[current_temp] += n - j + 1;
		}

		// team_score�� �������� ����
		for (int j = 1; j <= m; j++) {
			team_ranking.insert({team_score[j],j});
		}

		int count = 1;

		// team_data[����ȣ] = (����ŷ, ������)  �� �������� ����
		for (set<pair<int, int>>::iterator it = --team_ranking.end(); it != team_ranking.end(); it--) {
			team_data[(*it).second] = pair<int, int>(count, (*it).first);
			count++;
		}

		// team_data ���� ����ŷ ��� fight_opponent sort
		sort(fight_opponent.begin(), fight_opponent.end(), compare);


		int result = 0;
		for (int j = 0; j < fight_opponent.size(); j++) {
			
		}


	}

}