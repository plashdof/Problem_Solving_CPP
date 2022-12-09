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
sort(aquarium, aquarium + M)        //수족관의 온도를 기준으로 오름차순 정렬
sort(shark, shark + N)                       //상어의 서식 온도 하한을 기준으로 오름차순 정렬
int j = 1
for i = 1 to M
while j <= N and shark[j].first <= aquarium[i]   //상어의 서식 온도 하한이
PQ.push({ shark[j].second, shark[j].first })    //수족관의 온도보다 낮거나
j++                                                                     //같으면 최소힙에 삽입
while PQ.empty() == false and PQ.top().first < aquarium[i]
    PQ.pop()                               //최소힙에서 현재 수족관에 서식할 수 없는 상어를 제거
    if PQ.empty() == false
        PQ.pop()                               //최소힙이 비어있지 않았으면 상어와 수족관을 매치
        answer++

        print answer
