#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

int team[100001];
pair<int, int> team_ranking[100001];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n, m;
		cin >> n >> m;

		int temp;

		for (int j = 1; j <= n; j++) {
			cin >> team[j];

			team_ranking[team[j]].first = n - j + 1;
			team_ranking[team[j]].second = team[j];
			
		}


		



	}

}


int n, m
int team[1..n]
pair<int, int> score[1..m]    //<팀의 점수, 팀의 번호>
int chance[1..m]                 //chance[i]=j; 인하 팀의 선수가 i번 팀의 선수와 j회 대결할 수 있음
int rest                                 //순위를 올릴 수 있는 인하 팀 선수의 수
int answer

main
read n, m
for i = 1 to n
read team[i]
score[team[i]].first += n - i + 1
if i != 1 and team[i] == 1 and team[i - 1] != team[i]
rest += 1
chance[team[i - 1]] += 1
sort(score, score + m)
while rest > 0
if score[m].second == 1 and score[m].first > score[m - 1].first
break
bool flag = true
for i = m downto 1
if score[i].second == 1
score[i].first += 1
if flag == true and chance[score[i].second] > 0
chance[score[i].second] -= 1
score[i].first -= 1
flag = false
rest -= 1
answer += 1
sort(score, score + m)
if score[m].second == 1 and score[m].first > score[m - 1].first
print answer
else
print - 1