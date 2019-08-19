#include <iostream>
#include <stdio.h>
#include <cassert>
#include <algorithm>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <string.h>

#define N 1000000
#define  INF (1 << 30)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

bool sieve[N];

void Eratosthene_sieve() {
	for (int i = 4; i <= N; i += 2) sieve[i] = 1;

	for (ll i = 3; i*i <= N; i+=2) {
		if (!sieve[i])
			for (ll j = i * i; j <= N; j += i) sieve[j] = 1;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Eratosthene_sieve();

	for (int i = 2; i <= 1000; i++) if (!sieve[i]) cout << i << " "; cout << '\n';

	return 0;
}
