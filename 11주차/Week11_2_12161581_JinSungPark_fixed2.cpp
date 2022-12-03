#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;


int team_score[100001] = {0};


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
		priority_queue<pair<int, int>> fighting;
		priority_queue<pair<int, int>> team_ranking;

		for (int j = 1; j <= n; j++) {
			cin >> current_temp;

			// 인하팀보다 한등수 높은 선수의 팀번호를 vector에 삽입
			if (j > 1 && current_temp == 1) {
				fight_opponent.push_back(before_temp);
			}

			before_temp = current_temp;
			
			// team score를 팀번호로 indexing 하여 계산
			team_score[current_temp] += n - j + 1;
		}

		for (int j = 1; j <= m; j++) {
			team_ranking.push({ team_score[j],j });
		}


		// team score 이 높은순 내림차순으로, fight_opponent 를 fighting priority queue pair 에 삽입
		for (int j = 0; j < fight_opponent.size(); j++) {
			fighting.push({ team_score[fight_opponent[j]],fight_opponent[j] });
		}

		int score_temp = 0;
		int number_temp = 0;

		while (!fighting.empty()) {
			if (team_ranking.top().second == fighting.top().second) {
				number_temp = team_ranking.top().second;
				score_temp = team_ranking.top().first;

				team_ranking.pop();
			}
			
		}





		
		


	}

}