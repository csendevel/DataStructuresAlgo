//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#define N 100000

using namespace std;

typedef long long ll;

vector <int> g[N];
vector <int> ans;
bool used[N];
int timer, n, m, u, v;

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (!used[to])
			dfs(to);
	}
	ans.push_back(v);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		g[u].push_back(v);
	}

	for (int i = 1; i <= n; i++)
		if (!used[i]) dfs(i);


	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

	system("pause");
	return 0;
}
