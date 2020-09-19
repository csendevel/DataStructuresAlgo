#include <iostream>
#include <cctype>
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

struct ANode {
	struct ANode* s, * b;
	int d;
};

struct ANode* f(int d, struct ANode* s = NULL, struct ANode* b = NULL) {
	ANode* v = (struct ANode*)malloc(sizeof(struct ANode));
	v->d = d;
	v->b = b;
	v->s = s;

	return v;
}

void print(struct ANode* v, int offset) {
	if (v == 0) return;

	for (int i = 0; i < offset; i++)
		cout << " ";
	cout << v->d << '\n';

	print(v->s, offset + 4);
	print(v->b, offset);
}

int grandson_num(ANode* root, int level) {
	if (root == 0) return 0;
	ANode* ptr = root->s;

	int cnt = 0;
	while (ptr != NULL) {
		if (level == 2)
			cnt++;
		else
			cnt += grandson_num(ptr, level + 1);
		ptr = ptr->b;
	}

	return cnt;
}

ANode* return_son(ANode* root, int d1, int d2) {
	if (root == 0) return NULL;

	ANode* ptr = root->s;
	while (ptr != NULL) {
		if (ptr->d == d1) {
			ANode* new_ptr = ptr->s;
			while (new_ptr != NULL) {
				if (new_ptr->d == d2)
					return ptr;
				new_ptr = new_ptr->b;
			}
		}
		ptr = ptr->b;
	}

	return NULL;
}

ANode* traversal(ANode* root, int* sons, int sons_num) {
	if (root == nullptr) return NULL;

	ANode* res = root;
	ANode* ptr = NULL;
	
	for (int i = 0; i < sons_num; i++) {
		ptr = res->s;
		
		if (ptr == NULL) return NULL;
		
		int son_cnt = 1;
		while (ptr != NULL) {
			if (son_cnt == sons[i]) {
				res = ptr;
				break;
			}
			son_cnt++;
			ptr = ptr->b;
		}
		
		if (ptr == NULL) return NULL;
	}
	return res;
}

void delete_sons(ANode* root) {
	if (root == 0) return;

	ANode* ptr = root->s;
	ANode* first_grson = NULL;
	while (ptr != NULL) {
		if (ptr->s != NULL) {
			first_grson = ptr->s;
			break;
		}
		ptr = ptr->b;
	}

	ptr = root->s;
	ANode* l_grson = NULL;
	while (ptr != NULL) {
		ANode* n_ptr = ptr->s;
		
		if (l_grson != NULL) 
			l_grson->b = n_ptr;

		while (n_ptr != NULL) {
			l_grson = n_ptr;
			n_ptr = n_ptr->b;
		}

		ptr = ptr->b;
	}

	ptr = root->s;
	ANode* next_son = NULL;
	while (ptr != NULL) {
		next_son = ptr->b;
		free(ptr);
		ptr = next_son;
	}

	root->s = first_grson;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	

	ANode* root = f(1, f(2, 0, f(3, f(5, 0, f(8)), f(4, f(6, 0, f(7)), 0))), 0);


	print(root, 0);


	cout << grandson_num(root, 1) << '\n';
	

	ANode* son = return_son(root, 4, 6);
	cout << son->d << '\n';


	int mass[2] = { 3, 2 };
	ANode* s_son = traversal(root, mass, 2);
	if (s_son != nullptr)
		cout << s_son->d << '\n';
	else
		cout << "No Value\n";


	delete_sons(root);
	print(root, 0);

	return 0;
}