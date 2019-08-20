#include <iostream>
#include <stdio.h>
#include <cassert>
#include <algorithm>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <string.h>
#include <time.h>

#define N 100
#define  INF (1 << 30)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

ll n, tmp, max_path = -10, st, en;
ll dist[N][N], via[N][N];
vector <ll> path;

void find_path(int start, int end) {
	if (dist[start][end] == 1000000000) {
		cout << "No path\n";
		return;
	}

	int via_node = via[start][end];

	if (via_node = end) {
		path.push_back(end);
		return;
	}
	else {
		find_path(start, via_node);
		find_path(via_node, end);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			if (tmp == -1) {
				dist[i][j] = 1000000000;
				via[i][j] = -1;
			}
			else {
				dist[i][j] = tmp;
				via[i][j] = j;
			}
		}
	}

	for (int via_node = 0; via_node < n; via_node++) {
		for (int from_node = 0; from_node < n; from_node++) {
			for (int to_node = 0; to_node < n; to_node++) {
				int new_dist = dist[from_node][via_node] + dist[via_node][to_node];
				if (new_dist < dist[from_node][to_node]) {
					dist[from_node][to_node] = new_dist;
					via[from_node][to_node] = via_node;
				}
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dist[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';*/

	path.clear();

	cin >> st >> en;

	find_path(st, en);

	for (int i = 0; i < path.size(); i++) cout << path[i] << " "; cout << '\n';

	return 0;
}
