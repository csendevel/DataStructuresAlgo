#include <string> 
#include <vector> 
#include <iostream> 
#include <string.h>
#include <algorithm>
#define N 510

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int INF = numeric_limits<int> ::max();

int n, q, start;
char command;
int X1, X2, Y1, Y2, x, y;
int v;

int c[N][N];
int treeMax[4 * N][4 * N];
int treeMin[4 * N][4 * N];

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
	if (ly == ry)
		if (lx == rx) {
			treeMax[vx][vy] = c[lx][ly];
			treeMin[vx][vy] = c[lx][ly];
		}
		else {
			treeMax[vx][vy] = max(treeMax[vx * 2][vy], treeMax[vx * 2 + 1][vy]);
			treeMin[vx][vy] = min(treeMin[vx * 2][vy], treeMin[vx * 2 + 1][vy]);
		}
	else {
		int my = (ly + ry) / 2;
		build_y(vx, lx, rx, vy * 2, ly, my);
		build_y(vx, lx, rx, vy * 2 + 1, my + 1, ry);
		treeMax[vx][vy] = max(treeMax[vx][vy * 2], treeMax[vx][vy * 2 + 1]);
		treeMin[vx][vy] = min(treeMin[vx][vy * 2], treeMin[vx][vy * 2 + 1]);
	}
}

void build_x(int vx, int lx, int rx) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		build_x(vx * 2, lx, mx);
		build_x(vx * 2 + 1, mx + 1, rx);
	}
	build_y(vx, lx, rx, 1, 0, n - 1);
}

int max_y(int vx, int vy, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return -INF;
	if (ly == tly && try_ == ry)
		return treeMax[vx][vy];
	int tmy = (tly + try_) / 2;
	return max(max_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy)),
		max_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry));
}

int max_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
	if (lx > rx)
		return -INF;
	if (lx == tlx && trx == rx)
		return max_y(vx, 1, 0, n - 1, ly, ry);
	int tmx = (tlx + trx) / 2;
	return max(max_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry),
		max_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
}

int min_y(int vx, int vy, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return INF;
	if (ly == tly && try_ == ry)
		return treeMin[vx][vy];
	int tmy = (tly + try_) / 2;
	return min(min_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy)),
		min_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry));
}

int min_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
	if (lx > rx)
		return INF;
	if (lx == tlx && trx == rx)
		return min_y(vx, 1, 0, n - 1, ly, ry);
	int tmx = (tlx + trx) / 2;
	return min(min_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry),
		min_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
	if (ly == ry) {
		if (lx == rx) {
			treeMax[vx][vy] = new_val;
			treeMin[vx][vy] = new_val;
		}
		else {
			treeMax[vx][vy] = max(treeMax[vx * 2][vy], treeMax[vx * 2 + 1][vy]);
			treeMin[vx][vy] = min(treeMin[vx * 2][vy], treeMin[vx * 2 + 1][vy]);
		}
	}
	else {
		int my = (ly + ry) / 2;
		if (y <= my)
			update_y(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
		else
			update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
		treeMax[vx][vy] = max(treeMax[vx][vy * 2], treeMax[vx][vy * 2 + 1]);
		treeMin[vx][vy] = min(treeMin[vx][vy * 2], treeMin[vx][vy * 2 + 1]);
	}
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		if (x <= mx)
			update_x(vx * 2, lx, mx, x, y, new_val);
		else
			update_x(vx * 2 + 1, mx + 1, rx, x, y, new_val);
	}
	update_y(vx, lx, rx, 1, 0, n - 1, x, y, new_val);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> c[i][j];

	for (int i = 0; i < 4 * n; i++) {
		for (int j = 0; j < 4 * n; j++) {
			treeMax[i][j] = -INF;
			treeMin[i][j] = INF;
		}
	}

	build_x(1, 0, n - 1);

	cin >> q;

	while (q--) {
		cin >> command;
		if (command == 'q') {
			cin >> X1 >> Y1 >> X2 >> Y2;
			X1--; X2--; Y1--; Y2--;

			cout << max_x(1, 0, n - 1, X1, X2, Y1, Y2) << " " << min_x(1, 0, n - 1, X1, X2, Y1, Y2) << '\n';
		}
		else {
			cin >> x >> y >> v;
			x--; y--;
			update_x(1, 0, n - 1, x, y, v);
		}
	}

	//system("pause");
	return 0;
}
