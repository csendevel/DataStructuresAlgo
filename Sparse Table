#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <math.h>
#define N 1000100

using namespace std;

typedef long long ll;

ll n, k, r, l, v;
ll arr[N], log1[N], power[50];
pair <ll, ll> dp[N][25];
pair <ll, ll> ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	log1[1] = 0;
	for (int i = 2; i <= n; i++) log1[i] = log1[i / 2] + 1;

	power[0] = 1;
	for (int i = 1; i <= 40; i++) power[i] = power[i - 1] * 2;

	for (ll i = 0; i < n; i++)
		dp[i][0] = { arr[i],i };

	for (ll i = n; i >= 0; i--) {
		for (ll j = 1; j <= 20; j++) {
			if (dp[i][j - 1].first > dp[i + power[j - 1]][j - 1].first)
				dp[i][j] = dp[i][j - 1];
			else
				dp[i][j] = dp[i + power[j - 1]][j - 1];
		}
	}

	/*for (int i = 1; i < n; i++) {
		for (int j = 0; j < lg[n]; j++) {
			cout << dp[i][j].second << " ";
		}
		cout << "\n";
	}*/

	cin >> k;

	while (k--) {
		ans = { 0,0 };
		cin >> l >> r;

		--r; --l;
		v = log1[(r - l + 1)];

		if (dp[l][v].first > dp[r - power[v] + 1][v].first)
			ans = dp[l][v];
		else
			ans = dp[r - power[v] + 1][v];

		cout << ans.first << " " << ans.second + 1 << "\n";
	}
	return 0;
}
