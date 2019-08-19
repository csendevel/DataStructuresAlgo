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

#define N 1000000
#define  INF (1 << 30)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

ll v;

ll bin_pow_mod(ll v, ll pow, ll mod) {
	ll res = 1;
	while (pow) {
		if (pow & 1) res = (res * v) % mod;
		v = (v * v) % mod;
		pow >>= 1;
	}
	return res;
}

bool is_prime(ll x) {
	ll n = 0, c1 = 0, c2 = 0;
	for (int i = 0; i < 1000; i++) {
		n = rand() % (x - 2) + 1;
		if (bin_pow_mod(n, x - 1, x) == 1) c1++;
		else c2++;
	}
	if (c1 > c2) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	srand(time(NULL));

	cin >> v;

	if (is_prime(v)) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}
