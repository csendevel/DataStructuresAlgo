#include <iostream> 
#include <algorithm>

#define N 510

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, q, start;
char command;
int X1, X2, Y1, Y2, x, y;
ll v;

ll c[N];
ll treeMax[4 * N];
ll treeMin[4 * N];

void build_tree_max() {
	for (int i = start - 1; i > 0; i--)
		treeMax[i] = max(treeMax[i * 2], treeMax[i * 2 + 1]);
}

void build_tree_min() {
	for (int i = start - 1; i > 0; i--)
		treeMin[i] = min(treeMin[i * 2], treeMin[i * 2 + 1]);
}

ll get_max(int l, int r) {
	l += start, r += start;
	ll maxv = -1000000000;
	while (l <= r) {
		if (l % 2 != 0) {
			maxv = max(maxv, treeMax[l]);
			l++;
		}
		if (r % 2 == 0) {
			maxv = max(maxv, treeMax[r]);
			r--;
		}
		r >>= 1; l >>= 1;
	}
	return maxv;
}

ll get_min(int l, int r) {
	l += start, r += start;
	ll minv = 100000000;
	while (l <= r) {
		if (l % 2 != 0) {
			minv = min(minv, treeMin[l]);
			l++;
		}
		if (r % 2 == 0) {
			minv = min(minv, treeMin[r]);
			r--;
		}
		r >>= 1; l >>= 1;
	}
	return minv;
}

void update(int x, int v) {
	x += start;
	treeMax[x] = v;
	treeMin[x] = v;
	while (x / 2 != 0) {
		x /= 2;
		treeMax[x] = max(treeMax[2 * x], treeMax[2 * x + 1]);
		treeMin[x] = min(treeMin[2 * x], treeMin[2 * x + 1]);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> c[i];

	start = 1;
	while (start < n) start <<= 1;

	for (int i = 0; i < n; i++) {
		treeMax[i + start] = c[i];
		treeMin[i + start] = c[i];
	}

	build_tree_max();
	build_tree_min();

	cin >> q;

	while (q--) {
		cin >> command;
		if (command == 'q') {
			cin >> x >> y;
			x--, y--;

			cout << get_max(x, y) << " " << get_min(x, y) << '\n';
		}
		else {
			cin >> x >> v;
			x--;
			update(x, v);
		}
	}

	return 0;
}
