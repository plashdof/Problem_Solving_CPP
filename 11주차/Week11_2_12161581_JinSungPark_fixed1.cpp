#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;


// team 번호로 indexing 접근 ->  
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

			// 인하팀보다 한등수 높은 선수의 팀번호를 vector에 삽입
			if (j > 1 && current_temp == 1) {
				fight_opponent.push_back(before_temp);
			}

			before_temp = current_temp;
			
			// team score를 팀번호로 indexing 하여 계산
			team_score[current_temp] += n - j + 1;
		}

		// team_score로 내림차순 정렬
		for (int j = 1; j <= m; j++) {
			team_ranking.insert({team_score[j],j});
		}

		int count = 1;

		// team_data[팀번호] = (팀랭킹, 팀점수)  로 팀데이터 저장
		for (set<pair<int, int>>::iterator it = --team_ranking.end(); it != team_ranking.end(); it--) {
			team_data[(*it).second] = pair<int, int>(count, (*it).first);
			count++;
		}

		// team_data 에서 팀랭킹 기반 fight_opponent sort
		sort(fight_opponent.begin(), fight_opponent.end(), compare);


		int result = 0;
		for (int j = 0; j < fight_opponent.size(); j++) {
			
		}


	}

}