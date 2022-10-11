#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Node {
	int year;
	string city;
	vector<int> distance;
	vector<string> connect;
};

class Graph {
private:
	Node* root;
	vector<Node*> vec;
	

public:

	multiset<int> years;

	void insertNode(Node* n) {
		vec.push_back(n);
	}

	void setYear(int y) {
		years.insert(y);
	}

	Node* findNodeBycity(string s) {
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i]->city == s) return vec[i];
		}
	}

	Node* findNodeByyear(int y) {
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i]->year == y) return vec[i];
		}
	}

	void setRoot() {

	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	vector<Node*> vec;
	vector<string> city;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, M;
	
		cin >> N >> M;
		Graph* graph = new Graph();

		for (int j = 0; j < N; j++) {
			string s;
			int y;
			cin >> s >> y;

			Node* node =new Node();
			node->year = y;
			node->city = s;
			graph->insertNode(node);
			
		}

	

		for (int j = 0; j < M; j++) {
			string s1, s2;
			int t;
			cin >> s1 >> s2 >> t;
			Node* n1 = graph->findNodeBycity(s1);
			Node* n2 = graph->findNodeBycity(s2);

			n1->connect.push_back(s2);
			n1->distance.push_back(t);

			n2->connect.push_back(s1);
			n2->city.push_back(t);

		}

	}




	return 0;
}