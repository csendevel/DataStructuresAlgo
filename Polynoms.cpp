#include <iostream>
#include <cctype>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <list>

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

		cout << ans << '\n';
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
	}
	
	while (s1 > s2) {
		s.pol.push_back(0);
	}

	list<T> c;
	vector<T> tmp; 
	tmp.assign(s1, 0);
	int cnt = 0;

	for (auto it = this->pol.begin(); it != this->pol.end(); ++it)
		tmp[cnt++] += *it;
	
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
	}

	while (s1 > s2) {
		s.pol.push_back(0);
	}

	list<T> c;
	vector<T> tmp;
	tmp.assign(s1, 0);
	int cnt = 0;

	for (auto it = this->pol.begin(); it != this->pol.end(); ++it)
		tmp[cnt++] += *it;

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
	}

	while (s1 > s2) {
		s.pol.push_back(0);
	}

	list<T> c;
	vector<T> tmp;

	tmp.assign(s1, 0);
	int cnt = 0;

	auto it1 = this->pol.begin();
	auto it2 = s.pol.begin();

	for (int i = 0; i < s1; i++) {
		auto it1 = this->pol.begin();
		auto it2 = s.pol.end() - 1;
		
		int ans = 0;

		for (int j = 0; j <= i; j++) {
			ans += (*it1) * (*it2);
			it1++;
			it2--;
		}

		tmp[i] = ans;
	}

	for (int i = 0; i < s1; i++) c.push_back(tmp[i]);

	return Polynom(c);
}

template <class T>
Polynom<T> Polynom<T>::operator/(Polynom<T> s) {
	int s1 = this->pol.size();
	int s2 = s.pol.size();

	if (s1 < s2) return Polynom;

	list<T> c;
	vector<T> tmp;
	tmp.assign(s1, 0);
	int cnt = 0;


	
	return Polynom(c);
}

template <class T>
Polynom<T> Polynom<T>::operator%(Polynom<T> s) {
	int s1 = this->pol.size();
	int s2 = s.pol.size();

	if (s1 < s2) return this;



	list<T> c;
	vector<T> tmp;
	tmp.assign(s1, 0);
	int cnt = 0;



	return Polynom(c);
}

template<class T>
T& Polynom<T>::operator[](const int index) {
	int s1 = this->pol.size();
	while (index > s1) this->pol.push_back(0);
	auto it = this->pol.begin();
	it += index;

	return *it;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);



	return 0;
}
