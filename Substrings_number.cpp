#include <iostream>
#include <cctype>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <string.h>
#include <stack>
#include <queue>

#define N 700000
#define  INF (1 << 30)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

ll z[N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s;

	cin >> s;

	ll ans = 0;
	ll len = s.size();
	reverse(s.begin(), s.end());

	int cur_str_len = 0;

	for (int k = len - 1; k >= 0; k--) {
		++cur_str_len;

		ll max_z = 0;

		for (int t = k; t < (k + cur_str_len + 1); t++) z[t] = 0;
		ll r = k, l = k;

		for (int i = k + 1; i < (k + cur_str_len); ++i) {
			if (i <= r)
				z[i] = min(r - i + 1, z[k + i - l]);

			while (i + z[i] < (k + cur_str_len) && s[k + z[i]] == s[i + z[i]])
				++z[i];

			max_z = max(max_z, z[i]);

			if (i + z[i] - 1 > r) {
				l = i;
				r = i + z[i] - 1;
			}
		}

		ans += (cur_str_len - max_z);
	}

	cout << ans << '\n';

	return 0;
}
