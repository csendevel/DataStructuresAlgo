#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n,u,v;
vector<int> g[1000];
int color[10000];
vector<int> p;
int cycle_st, cycle_end;

bool dfs (int v) {
	color[v] = 1;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (color[to] == 0) {
			p[to] = v;
			if (dfs (to))  return true;
		}
		else if (color[to] == 1 && to != p[v]) {
			cycle_end = v;
			cycle_st = to;
			return true;
		}
	}
	color[v] = 2;
	return false;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
        
	p.assign (n, -1);
	cycle_st = -1;
	for (int i = 0; i < n; ++i){
            if(color[i] == 0){
                if (dfs (i))break;
            }
        }
	if (cycle_st == -1)
		puts ("Acyclic");
	else {
		puts ("Cyclic");
		vector<int> cycle;
		cycle.push_back (cycle_st);
		for (int v = cycle_end; v != cycle_st; v = p[v])
			cycle.push_back (v);
		cycle.push_back (cycle_st);
		reverse (cycle.begin(), cycle.end());
		for (size_t i=0; i < cycle.size(); ++i)
			printf ("%d ", cycle[i]);
	}
}
