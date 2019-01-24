#define _CRT_SECURE_NO_WARNINGS
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
vector <pair<int, int> > ans;
bool used[N];
int fup[N], tin[N];
int timer, n, m, tmp;

void dfs(int v, int par = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (to == par) continue;
		if (used[to]) 
			fup[v] = min(fup[v], tin[to]);
		else {
			dfs(to, v);
			fup[v] = min(fup[v], tin[to]);
			if (fup[to] > tin[v])
				ans.push_back(make_pair(v,to));
		}
	}
}

void find_bridges() {
	timer = 0;
	for (int i = 0; i < n; i++) used[i] = false;
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs(i);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		g[i].push_back(tmp - 1);
	}

	find_bridges();

	for (int i = 0; i < ans.size(); i++) 
		cout << ans[i].first << " " << ans[i].second << '\n';

	//system("pause");
	return 0;
}
