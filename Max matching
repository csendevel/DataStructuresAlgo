#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <math.h>
#define N 1000010

using namespace std;

typedef long long ll;

int n, k;
int r[N];
const int s = 384;
vector <int> answer;

struct block {
	vector <int> a;
	void push_back(int x) {
		a.push_back(x);
	}

	int get(int x, int y) {
		return a[a.size() - 1];
	}
};

block s_dec[s];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> r[i];
		s_dec[i / s].push_back(r[i]);
	}

	for (int i = 0; i < s; i++)
		sort(s_dec[i].a.begin(), s_dec[i].a.end());

	int lp = 0, rp = 0, ans = -1;

	cin >> k;
	for (int i = 0; i < k; i++) {
		ans = -1;
		cin >> lp >> rp;
		lp--;

		while (lp < rp) {
			if (lp % s || lp + s - 1 >= rp) {
				ans = max(ans, r[lp]);
				lp++;
			}
			else {
				ans = max(ans, s_dec[lp / s].get(lp, rp));
				lp += s;
			}
		}
		answer.push_back(ans);
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	cout << '\n';

	return 0;
}
