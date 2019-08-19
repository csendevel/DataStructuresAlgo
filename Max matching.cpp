//#include "pch.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <math.h>
#define N 500

using namespace std;

typedef long long ll;

int n, m, ans, tmp;
int mt[N], used[N];
vector <int> g[N];

int dfs(int u, int now) {
	if (used[u] == now) return 0;
	used[u] = now;
	for (auto to : g[u]) {
		if (mt[to] == -1 || dfs(mt[to], now)) {
			mt[to] = u;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		while (cin >> tmp && tmp != 0)
			g[i].push_back(tmp - 1);
	}

	for (int i = 0; i < m; i++) mt[i] = -1;

	for (int i = 0; i < n; i++)
		dfs(i, i + 1);

	for (int i = 0; i < m; i++)
		if (mt[i] != -1) ans++;

	cout << ans << '\n';
	for (int i = 0; i < m; i++)
		if (mt[i] != -1)
			cout << mt[i] + 1 << " " << i + 1 << '\n';

	return 0;
}
