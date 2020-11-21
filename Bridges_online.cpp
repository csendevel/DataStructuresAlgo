#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

vector<int> bcomp; // dsu for doubly connected components
vector<int> comp;  // dsu for conectivity components
vector<int> sz, par, used;

int bridges;

int get_bcomp(int u) {
	if (u == -1) return -1;
	if (bcomp[u] == u)
		return u;
	return bcomp[u] = get_bcomp(bcomp[u]);
}

int get_comp(int u) {
	u = get_bcomp(u);

	if (comp[u] == u)
		return u;
	return comp[u] = get_comp(comp[u]);
}

void rehand_tree(int u) {
	u = get_bcomp(u);

	int it = u;
	int child = -1;

	while (it != -1) {
		int t = get_bcomp(par[it]);
		par[it] = child;
		comp[it] = u;
		child = it; it = t;
	}

	sz[u] = sz[child];
}

int u_cnt;
int comp_cycle(int a, int b) {
	vector <int> path_a, path_b;

	u_cnt++;
	int lca;

	while (true) {
		if (a != -1) {
			a = get_bcomp(a);
			path_a.push_back(a);

			if (used[a] == u_cnt) {
				lca = a;
				break;
			}
			used[a] = u_cnt;
			a = par[a];
		}

		if (b != -1) {
			b = get_bcomp(b);
			path_b.push_back(b);

			if (used[b] == u_cnt) {
				lca = b;
				break;
			}
			used[b] = u_cnt;
			b = par[b];
		}
	}

	int cnt = 0;

	for (int i = 0; i < path_a.size(); i++) {
		bcomp[path_a[i]] = lca;
		if (path_a[i] == lca) break;
		cnt++;
	}

	for (int i = 0; i < path_b.size(); i++) {
		bcomp[path_b[i]] = lca;
		if (path_b[i] == lca) break;
		cnt++;
	}

	return cnt;
}

void add_edge(int a, int b) {
	a = get_bcomp(a); b = get_bcomp(b);

	int comp_a = get_comp(a), comp_b = get_comp(b);

	if (comp_a != comp_b) {
		bridges++;

		if (sz[comp_a] > sz[comp_b]) {
			swap(comp_a, comp_b);
			swap(a, b);
		}

		rehand_tree(a);

		par[a] = b;
		comp[a] = b;
		sz[comp_b] += sz[a];

	}
	else {
		if (a != b)
			bridges -= comp_cycle(a, b);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cout << "Enter vertex and edges number:\n";
	//graph vertex from 0 to n-1
	int n, m;
	cin >> n >> m;

	bcomp.assign(n, 0);
	comp.assign(n, 0);
	sz.assign(n, 1);
	par.assign(n, -1);
	used.assign(n, 0);

	for (int i = 0; i < n; i++)
		bcomp[i] = comp[i] = i;

	cout << "Enter edges:\n";
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;

		add_edge(x, y);
		cout << "number of bridges: " << bridges << '\n';
	}

	return 0;
}