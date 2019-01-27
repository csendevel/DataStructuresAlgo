#include <bits/stdc++.h>
#define N 10000

using namespace std;

typedef long long ll;

int n, m, k;
double me[N], ans;
bool used[N];

struct Tvert {
	double x, y;
}a[N];

double dist(int x, int y) {
	return sqrt((a[x].x - a[y].x)*(a[x].x - a[y].x) + (a[x].y - a[y].y)*(a[x].y - a[y].y));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y;

	me[0] = 0;
	for (int i = 1; i < n; i++) me[i] = 10000000000000;

	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int u = 0; u < n; u++) {
			if (!used[u] && (v == -1 || me[u] < me[v])) v = u;
		}

		used[v] = 1;

		ans += me[v];
		double l = 0;

		for (int to = 0; to < n; to++) {
			l = dist(v, to);
			if (l < me[to]) me[to] = l;
		}
	}

	cout << setprecision(12) << ans << '\n';
	return 0;
}
