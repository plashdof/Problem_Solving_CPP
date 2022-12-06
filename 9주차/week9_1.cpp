#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int N, M, K;
vector<vector<int>> graph;
vector<bool> isVisited;
int dis[1001];

void BFS(int start) {
	queue<int> q;
	q.push(start);
	isVisited[start] = true;
	dis[start] = 0;
	bool state = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];

			if (!isVisited[next]) {
				q.push(next);
				isVisited[next] = true;
				dis[next] = dis[cur] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {

		cin >> N >> M >> K;

		int H;
		int min = 0;
		int hanyang = 0;
		

		graph.assign(N + 1, vector<int>(0, 0));
		isVisited.assign(N + 1, false);

		// 한양 구하기
		for (int j = 0; j < N; j++) {
			cin >> H;
			if (j == 0) min = H;
			if (H < min) {
				min = H;
				hanyang = j;
			}
		}

		int temp1, temp2;

		for (int j = 0; j < M; j++) {
			cin >> temp1 >> temp2;

			graph[temp1].emplace_back(temp2);
			graph[temp2].emplace_back(temp1);
		}


		BFS(hanyang);


		for (int j = 0; j < K; j++) {
			cin >> temp1;
			if (temp1 == hanyang) {
				cout << 0 << "\n";
			}
			else if (dis[temp1] == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << dis[temp1] << "\n";
			}
			
		}

		for (int j = 0; j < N; j++) {
			dis[j] = 0;
		}


	}

}