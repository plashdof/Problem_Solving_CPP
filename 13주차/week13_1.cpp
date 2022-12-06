#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int H[1001];
vector<vector<int>> graph;
vector<bool> isVisited;

void DFS(int cur) {
	isVisited[cur] = true;
	cout << cur << "\n";

	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		if (!isVisited[next]) {
			DFS(next);
		}
	}
}

bool compare(int i, int j) {
	return H[i] < H[j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		graph.assign(N + 1, vector<int>(0, 0));
		isVisited.assign(N + 1, false);
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		
		int min = 500001;
		int start = 0;
		for (int j = 0; j < N; j++) {
			cin >> H[j];
			if (min > H[j]) {
				min = H[j];
				start = j;
			}
			pq.push({ H[j],j });
		}

		int temp1, temp2;

		for (int j = 0; j < M; j++) {
			cin >> temp1 >> temp2;
			graph[temp1].emplace_back(temp2);
			graph[temp2].emplace_back(temp1);
		}

		for (int j = 0; j < N; j++) {
			sort(graph[j].begin(), graph[j].end(), compare);
		}

		DFS(start);

		while (!pq.empty()) {
			if (isVisited[pq.top().second]) {
				pq.pop();
				continue;
			}
			else {
				start = pq.top().second;
				DFS(start);
			}
		}
		
	}
}