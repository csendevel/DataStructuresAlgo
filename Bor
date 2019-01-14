#include <bits/stdc++.h>
#define N 1000010

using namespace std;

typedef long long ll;


struct vertex {
	ll alpha[26]; // alphabet on string
	bool term; // terminated vertex
	vertex() { 
		memset(alpha, 0, sizeof(alpha));
		term = false;
	}
} boron[N];

int n;
ll sz = 1, ans;
string s;

void add_string(string s) {
	ll v = 0;
	for (int i = 0; i < s.length(); i++) {
		int tmp = s[i] - 'a';
		if (boron[v].alpha[tmp] == 0)
			boron[v].alpha[tmp] = sz++;

		v = boron[v].alpha[tmp];
	}
	boron[v].term = true;
}

bool isExist(string s) {
	ll v = 0;
	for (int i = 0; i < s.length(); i++) {
		int tmp = s[i] - 'a';
		if (boron[v].alpha[tmp] == 0)
			return 0;

		v = boron[v].alpha[tmp];
	}
	return (boron[v].term != 0);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		if (!isExist(s)) {
			add_string(s);
			ans++;
		}
	}

	cout << ans << '\n';
	return 0;
}
