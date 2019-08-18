//#include "pch.h"
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

#define N 200000

using namespace std;

typedef long long ll;

struct Point {
	ll x, y;
};

vector <Point> a, up_env, down_env;
int n;

ll operator *(Point a, Point b) {
	return a.x * b.y - b.x * a.y;
}

Point operator-(Point a, Point b) {
	return { a.x - b.x, a.y - b.y };
}

bool pos(Point a, Point b, Point c) {
	return (a - b)*(c - b) > 0;
}

bool neg(Point a, Point b, Point c) {
	return (a - b)*(c - b) < 0;
}

bool comp(Point a, Point b) {
	if (a.x == b.x) return a.y < b.y;;
	return a.x < b.x;
}

double sqr(long double a) {
	return a * a;
}

double d(Point a, Point b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

void convex(vector<Point> &a) {
	if (a.size() == 1) return;
	sort(a.begin(), a.end(), &comp);

	up_env.push_back(a[0]);
	down_env.push_back(a[0]);

	Point lp = a[0], rp = a.back();

	for (size_t i = 1; i < a.size(); i++) {
		if (i == a.size() - 1 || pos(lp, a[i], rp)) {
			while (up_env.size() >= 2 && !pos(up_env[up_env.size() - 2], up_env[up_env.size() - 1], a[i]))
				up_env.pop_back();
			up_env.push_back(a[i]);
		}
		if (i == a.size() - 1 || neg(lp, a[i], rp)) {
			while (down_env.size() >= 2 && !neg(down_env[down_env.size() - 2], down_env[down_env.size() - 1], a[i]))
				down_env.pop_back();
			down_env.push_back(a[i]);
		}
	}

	a.clear();
	for (size_t i = 0; i < up_env.size(); i++)
		a.push_back(up_env[i]);
	for (size_t i = down_env.size() - 2; i > 0; i--)
		a.push_back(down_env[i]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y;

	convex(a);

	/*cout << (int)a.size() << '\n';
	for (size_t i = 0; i < a.size(); i++)
		cout << a[i].x << " " << a[i].y << '\n';*/

	long double p = 0;
	int m = a.size();

	if (m != 2) {
		for (int i = 0; i < m; i++) {
			int r = (i + 1) % m;
			p += d(a[i], a[r]);
		}
	}
	else
		p += d(a[0], a[1]);

	printf("%.40llf", p);
	return 0;
}
