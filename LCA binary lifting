#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
const int N = 100010;

int t = 0;
int tin[N], tout[N], dp[N][22];
vector <int> g[N];
long long ans, pans, l, r;

void dfs(int v, int p) {
	tin[v] = t++;
	dp[v][0] = p;
	for (int j = 1; j < 22; ++j) {
		dp[v][j] = dp[dp[v][j - 1]][j - 1];
	}
	for (auto to : g[v]) {
		dfs(to, v);
	}
	tout[v] = t++;
}

bool par(int a, int b) {
	return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

int lca(int a, int b) {
	if (par(a, b)) {
		return a;
	}
	else if (par(b, a)) {
		return b;
	}
	for (int j = 21; j >= 0; --j) {
		if (!par(dp[a][j], b))
			a = dp[a][j];
	}
	return dp[a][0];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, p;
	cin >> n >> m;

	for (int i = 1; i < n; ++i) {
		cin >> p;
		g[p].push_back(i);
	}

	dfs(0, 0);

	for (int i = 1; i <= m; i++) {
		cin >> l >> r;
    ans = lca(l, r);
    cout << ans << '\n';
	}
	
	return 0;
}
