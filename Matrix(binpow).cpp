#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
#define N 710

using namespace std;

typedef long long ll;
const ll MOD = 999999937;

ll sum, n;
ll a[5][5], b[5][5], t[5][5], tmp[5][5];
ll matrix[5][5] = { {1,1,1,1,1},
					{1,1,1,1,1},
					{1,1,1,0,0},
					{1,1,1,1,1},
					{1,1,1,0,0} };

void mult1() {
	memset(t, 0, sizeof(t));

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++) {
				t[i][j] += a[i][k] * a[k][j];
				t[i][j] = t[i][j] % MOD;
			}

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			a[i][j] = t[i][j];
}

void mult2() {
	memset(tmp, 0, sizeof(tmp));

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
				tmp[i][j] = tmp[i][j] % MOD;
			}

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			b[i][j] = tmp[i][j];
}

void bin_pow(long long n) {
	while (n) {
		if (n & 1)
			mult2();
		mult1();
		n >>= 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (cin >> n) {

		memset(b, 0, sizeof(b));
		for (int i = 0; i < 5; i++) b[i][i] = 1;

		for (int i = 0;i < 5; i++)
			for (int j = 0; j < 5; j++)
				a[i][j] = matrix[i][j];

		sum = 0;
		if (n == 0) break;
		bin_pow(n - 1);

		/*for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << b[i][j] << " ";
			}
			cout << '\n';
		}*/

		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				sum = (sum + b[i][j]) % MOD;

		cout << sum << '\n';
	}
	return 0;
}
