#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int cost[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; 
    cin >> T;

    for (int i = 0; i < T; i++) {
        string from, to; 
        cin >> from >> to;

        for (int j = 0; j <= from.length(); j++) cost[j][0] = j;
        for (int j = 0; j <= to.length(); j++) cost[0][j] = j;

        for (int f = 1; f <= from.length(); f++) {
            for (int t = 1; t <= to.length(); t++) {

                if (from[f - 1] == to[t - 1]) cost[f][t] = cost[f - 1][t - 1];
                else cost[f][t] = min(cost[f - 1][t - 1], min(cost[f - 1][t], cost[f][t - 1])) + 1;

            }
        }
        cout << cost[from.length()][to.length()] << "\n";
    }

}