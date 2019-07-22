#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <string.h>

#define N 700000
#define  INF (1 << 30)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int n;
string s;
vector <char> op;
vector <ll> pol;

ll bin_pow(ll v, ll pow) {
    if(pow < 0) 
        return 0;
	ll res = 1;
	while (pow) {
		if (pow & 1)
			res *= v;
		v *= v;
		pow >>= 1;
	}
	return res;
}

inline bool is_oper(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '#';
}

inline int prior(char c) {
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
	if (c == '^') return 3;
	if (c == '#') return 4;
	return -1;
}

inline bool left_assoc(char op) {
	return op == '^' ? 0 : 1;
}

inline void calc(char op) {
	if (op == '#') {
		ll l = pol.back(); pol.pop_back();
		pol.push_back(-l);
		return;
	}
	ll r = pol.back(); pol.pop_back();
	ll l = pol.back(); pol.pop_back();
	switch (op) {
            case '+': pol.push_back(l + r); break;
            case '-': pol.push_back(l - r); break;
            case '*': pol.push_back(l * r); break;
            case '/': pol.push_back(l / r); break;
            case '^': pol.push_back(bin_pow(l, r)); break; 
	}
}

inline void solve(int x, int y) {

	for (int i = 0; i < s.size(); i++) {

		if (s[i] == '(') op.push_back('(');

		else if (s[i] == ')') {
			while (!op.empty() && op.back() != '(')
				calc(op.back()), op.pop_back();
			op.pop_back();
		}

		else if (s[i] == 'x') pol.push_back(x);

		else if (s[i] == 'y') pol.push_back(y);

		else if (is_oper(s[i])) {
			while (!op.empty() && (left_assoc(op.back()) && prior(op.back()) >= prior(s[i]) || !left_assoc(op.back()) && prior(op.back()) > prior(s[i])) /*&& prior(op.back()) >= prior(s[i])*/)
				calc(op.back()), op.pop_back();
			op.push_back(s[i]);
		}

		else if ('0' <= s[i] && s[i] <= '9') {
			ll res = 0;
			while ('0' <= s[i] && s[i] <= '9' && i < s.size()) { res = res * 10 + (int)(s[i] - '0'); i++; }
			pol.push_back(res);
			i--;
		}
		
		//debag
		//for (int i = 0; i < pol.size(); i++) cout << pol[i] << ' ';
		//cout << '\n';
		//for (int i = 0; i < op.size(); i++) cout << op[i] << ' ';
		//cout << '\n';
	}
	while (!op.empty())
		calc(op.back()), op.pop_back();
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	cin >> s;

	if (s[0] == '-') s[0] = '#';
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '-' && s[i - 1] == '(') s[i] = '#';
	}
	
	//cout << s << endl;

	cin >> n;

	int x, y;

	while (n--) {
		pol.clear();
		cin >> x >> y;
		solve(x, y);
		cout << pol.back() << '\n';
	}

	return 0;
}
