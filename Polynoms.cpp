#include <iostream>
#include <cctype>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <vector>

using namespace std;

typedef long long ll;

template <class T>
class Polynom
{
	list<T> pol;

public:
	Polynom() { pol.push_back(0); }
	Polynom(list<T> c) { pol = c; }

	ll value(ll point) {
		ll ans = 0;
		ll pow = 1;

		for (auto it = pol.begin(); it != pol.end(); ++it) {
			ans += *it * pow;
			pow *= point;
		}

		return ans;
	}

	void print() {
		for (auto it = pol.begin(); it != pol.end(); ++it)
			cout << *it << " ";
		cout << '\n';
	}

	Polynom operator+ (Polynom s);
	Polynom operator- (Polynom s);
	Polynom operator* (Polynom s);
	Polynom operator/ (Polynom s);
	Polynom operator% (Polynom s);
	T& operator[](const int index);
};

template <class T>
Polynom<T> Polynom<T>::operator+(Polynom<T> s) {
	int s1 = this->pol.size();
	int s2 = s.pol.size();
	
	while (s1 < s2) {
		this->pol.push_back(0);
		s1++;
	}
	
	while (s1 > s2) {
		s.pol.push_back(0);
		s2++;
	}

	list<T> c;
	vector<T> tmp; 
	tmp.assign(s1, 0);
	int cnt = 0;

	for (auto it = this->pol.begin(); it != this->pol.end(); ++it)
		tmp[cnt++] += *it;
	
	cnt = 0;

	for (auto it = s.pol.begin(); it != s.pol.end(); ++it)
		tmp[cnt++] += *it;

	for (int i = 0; i < s1; i++) c.push_back(tmp[i]);

	return Polynom(c);
}

template <class T>
Polynom<T> Polynom<T>::operator-(Polynom<T> s) {
	int s1 = this->pol.size();
	int s2 = s.pol.size();

	while (s1 < s2) {
		this->pol.push_back(0);
		s1++;
	}

	while (s1 > s2) {
		s.pol.push_back(0);
		s2++;
	}

	list<T> c;
	vector<T> tmp;
	tmp.assign(s1, 0);
	int cnt = 0;

	for (auto it = this->pol.begin(); it != this->pol.end(); ++it)
		tmp[cnt++] += *it;

	cnt = 0;
	for (auto it = s.pol.begin(); it != s.pol.end(); ++it)
		tmp[cnt++] -= *it;

	for (int i = 0; i < s1; i++) c.push_back(tmp[i]);

	return Polynom(c);
}

template <class T>
Polynom<T> Polynom<T>::operator*(Polynom<T> s) {
	int s1 = this->pol.size();
	int s2 = s.pol.size();

	while (s1 < s2) {
		this->pol.push_back(0);
		s1++;
	}

	while (s1 > s2) {
		s.pol.push_back(0);
		s2++;
	}

	list<T> c;
	vector<T> tmp;

	tmp.assign(s1, 0);
	
	auto i1 = this->pol.begin();
	auto i2 = s.pol.begin();

	for (int i = 0; i < s1; i++) {
		auto it1 = i1;
		auto it2 = i2;

		int ans = 0;

		for (int j = 0; j <= i; j++) {
			ans += (*it1) * (*it2);
			if (it1 != this->pol.end()) it1++;
			if(it2 != s.pol.begin()) it2--;
		}

		++i2;
		tmp[i] = ans;
	}

	for (int i = 0; i < s1; i++) c.push_back(tmp[i]);

	return Polynom(c);
}

template <class T>
Polynom<T> Polynom<T>::operator/(Polynom<T> s) {
	int s1 = this->pol.size() - 1;
	int s2 = s.pol.size() - 1;

	int max_size = max(s1 + 1, s2 + 1);

	list<T> c;
	vector<T> r, q, u, v;

	for (auto it = this->pol.begin(); it != this->pol.end(); ++it) {
		u.push_back(*it);
	}

	for (auto it = s.pol.begin(); it != s.pol.end(); ++it) {
		v.push_back(*it);
	}

	q.assign(max_size, 0.0);
	r.assign(max_size, 0);

	for (int j = 0; j <= s1; j++)
		r[j] = u[j];

	for (int k = s1 - s2; k >= 0; k--) {
		q[k] = r[s2 + k] / v[s2];
		for (int j = s2 + k - 1; j >= k; j--) r[j] -= q[k] * v[j - k];
	}

	for (int j = s2; j <= s1; j++) r[j] = 0.0;
	
	for (auto i : q)
		c.push_back(i);

	return Polynom(c);
}

template <class T>
Polynom<T> Polynom<T>::operator%(Polynom<T> s) {
	int s1 = this->pol.size() - 1;
	int s2 = s.pol.size() - 1;

	int max_size = max(s1 + 1, s2 + 1);

	list<T> c;
	vector<T> r, q, u, v;

	for (auto it = this->pol.begin(); it != this->pol.end(); ++it) {
		u.push_back(*it);
	}

	for (auto it = s.pol.begin(); it != s.pol.end(); ++it) {
		v.push_back(*it);
	}

	q.assign(max_size, 0.0);
	r.assign(max_size, 0);

	
	for (int j = 0; j <= s1; j++)
		r[j] = u[j];

	for (int k = s1 - s2; k >= 0; k--) {
		q[k] = r[s2 + k] / v[s2];
		for (int j = s2 + k - 1; j >= k; j--) r[j] -= q[k] * v[j - k];
	}

	for (int j = s2; j <= s1; j++) r[j] = 0.0;

	for (auto i : r)
		c.push_back(i);

	return Polynom(c);
}

template<class T>
T& Polynom<T>::operator[](const int index) {
	int s1 = this->pol.size();
	
	while (index >= s1) {
		this->pol.push_back(0);
		s1++;
	}
	
	auto it = this->pol.begin();
	
	for (int i = 0; i < index; i++) ++it;

	return *it;
}

int main() {
	auto ob1 = Polynom<int>({ 1,2,3 });
	auto ob2 = Polynom<int>({ 1,1,1 });

	cout << ob1.value(2) << '\n';

	auto ob3 = ob1 % ob2;

	ob3.print();
	return 0;
}
