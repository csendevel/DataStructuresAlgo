#include <iostream>
#include <stdio.h>
#include <cassert>
#include <algorithm>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <string.h>
#include <time.h>

#define N 200
#define  INF (1 << 30)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int n, p, t;
bool Graycode[N][N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	Graycode[1][n] = 0;
	Graycode[2][n] = 1;
	p = 2;

	for (int i = 2; i <= n; i++) {
		t = p;
		p *= 2;
		for (int k = p / 2 + 1; k <= p; k++) {
			for (int r = 1; r <= n; r++) Graycode[k][r] = Graycode[t][r];
			Graycode[t][n + 1 - i] = 0;
			Graycode[k][n + 1 - i] = 1;
			t--;
		}
	}

	for (int j = 1; j <= (1 << n); j++) {
		for (int i = 1; i <= n; i++) cout << Graycode[j][i]; cout << '\n';
	}

	return 0;
}
