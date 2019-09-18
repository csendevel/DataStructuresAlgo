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

#define N 10010
#define  INF (1 << 30)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int phi(int n) {
	int result = n;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cout << phi(4);

	return 0;
}
