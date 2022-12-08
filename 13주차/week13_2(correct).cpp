#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;

int N, M, Q;

vector<pair<int, int>> graph[251];


int dijkstra(int start, int end) {

	int dist[251];

	for (int i = 0; i < 251; i++) {
		dist[i] = INF;
	}

	priority_queue<pair<int, int>> pq;

	dist[start] = 0;
	pq.push({ start, 0 });


	while (!pq.empty()) {
		int cur = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		if (dist[cur] < distance) {
			continue;
		}

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int now_distance = distance + graph[cur][i].second;

			if (dist[next] > now_distance) {
				dist[next] = now_distance;
				pq.push({ next,-now_distance });
			}
		}

	}

	return dist[end];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int u, v, w;
		

		cin >> N >> M >> Q;

		for (int j = 0; j < M; j++) {
			cin >> u >> v >> w;
			graph[u].push_back({ v,w });
			graph[v].push_back({ u,w });
		}

		for (int j = 0; j < Q; j++) {
			cin >> u >> v;
			cout << dijkstra(u, v) << "\n";
		}

		for (int j = 0; j < 251; j++) {
			graph[j].clear();
		}
	}
}

