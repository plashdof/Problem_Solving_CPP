#include <iostream>
#include <utility>
using namespace std;

pair<int, int> shark[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;

        

        for (int j = 0; j < N; j++) {

        }
    }
}

pair<int, int> shark[N]
int aquarium[N]
priority queue<pair<int, int>> PQ
int answer = 0

main()
read N, M
for i = 1 to N
read shark[i].first, shark[i].second
for i = 1 to M
read aquarium[i]
sort(aquarium, aquarium + M)        //�������� �µ��� �������� �������� ����
sort(shark, shark + N)                       //����� ���� �µ� ������ �������� �������� ����
int j = 1
for i = 1 to M
while j <= N and shark[j].first <= aquarium[i]   //����� ���� �µ� ������
PQ.push({ shark[j].second, shark[j].first })    //�������� �µ����� ���ų�
j++                                                                     //������ �ּ����� ����
while PQ.empty() == false and PQ.top().first < aquarium[i]
    PQ.pop()                               //�ּ������� ���� �������� ������ �� ���� �� ����
    if PQ.empty() == false
        PQ.pop()                               //�ּ����� ������� �ʾ����� ���� �������� ��ġ
        answer++

        print answer
