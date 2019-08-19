#include <bits/stdc++.h>
#define N 100010

using namespace std;

typedef long long ll;

int dad[N], rnk[N];
int n, m;
ll sum;

struct Tedge {
	int x, y, w;
}a[N];

bool sortf(Tedge a, Tedge b) {
	return a.w < b.w;
}

int get(int u) {
	if (dad[u] == u) return u;
	else return dad[u] = get(dad[u]);
}

void set_union(int a, int b) {
	a = get(a); b = get(b);
	if (rnk[a] < rnk[b]) dad[a] = b;
	if (rnk[a] > rnk[b]) dad[b] = a;
	if (rnk[a] == rnk[b]) {
		rnk[a]++; dad[a] = b;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x, y;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> a[i].w;
		a[i].x = --x; a[i].y = --y;
	}

	for (int i = 0; i < n; i++) dad[i] = i;

	sort(a, a + m, sortf);

	for (int i = 0; i < m; i++) {
		if (get(a[i].x) != get(a[i].y)) {
			sum += a[i].w;
			set_union(a[i].x, a[i].y);
		}
	}

	cout << sum << "\n";
	return 0;
}
