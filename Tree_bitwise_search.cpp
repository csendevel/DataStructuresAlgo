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

int digit(ll x, ll n) {
	return (x>>n)&1;
}

struct DSNode{
	int key, val;
	struct DSNode* zero;
	struct DSNode* one;
};

void print(DSNode * root, int offset) {
	if (root == 0) return;
	print(root->zero, offset + 3);
	for (int i = 0; i < offset; i++)
		cout << " ";
	cout << root->key << " " << root->val << '\n';
	print(root->one, offset + 3);
}

struct DSNode* tree_build(int key, int d, DSNode* z, DSNode* f) {
	struct DSNode* p = (struct DSNode*)malloc(sizeof(struct DSNode));
	p->zero = z;
	p->one = f;
	p->key = key;
	p->val = d;
	return p;
}

struct DSNode* search(DSNode* root, int key, int level = 0) {
	if (root == 0) return NULL;
	if (root->key == key) return root;
	if (digit(key, level) == 1) search(root->one, key, level + 1);
	else search(root->zero, key, level + 1);
}

struct DSNode* insert(DSNode** root, int key, int val, int level = 0) {
	if (*root == 0) {
		*root = (struct DSNode*)malloc(sizeof(struct DSNode));
		(*root)->key = key;
		(*root)->val = val;
		(*root)->zero = 0;
		(*root)->one = 0;
		return *root;
	}
	if (digit(key, level) == 1) insert(&(*root)->one, key, val, level + 1);
	else insert(&(*root)->zero, key, val, level + 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	/*int x, n;
	cin >> x >> n;
	cout << digit(x, n) << '\n';*/

	struct DSNode* root = NULL;
	
	insert(&root, 4, 66);
	insert(&root, 7, 62);
	insert(&root, 1, 6);
	insert(&root, 2, 666);
	insert(&root, 15, 995);

	print(root, 1);

	//struct DSNode* root = tree_build(2, 55, tree_build(4, 67, 0, tree_build(8, 88, 0, 0)), tree_build(3, 68, 0, 0));
	//print(root, 1);

	//struct DSNode* val = search(root, 1);
	//if(val != NULL) cout << val->key << " " << val->val << '\n';

	return 0;
}