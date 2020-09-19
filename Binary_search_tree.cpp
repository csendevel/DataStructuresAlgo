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

struct BSNode{
	int key, val;
	struct BSNode* left;
	struct BSNode* right;
};

void print(BSNode * root, int offset) {
	if (root == 0) return;
	print(root->left, offset + 3);
	for (int i = 0; i < offset; i++)
		cout << " ";
	cout << root->key << " " << root->val << '\n';
	print(root->right, offset + 3);
}

struct BSNode* node_build(int key, int d, BSNode* l = 0, BSNode* r = 0) {
	struct BSNode* p = (struct BSNode*)malloc(sizeof(struct BSNode));
	p->left = l;
	p->right = r;
	p->key = key;
	p->val = d;
	return p;
}

struct BSNode* search(BSNode* root, int key, BSNode* anc = 0) {
	if (root == 0) return nullptr;
	if (root->key == key) return root;
	if (key > root->key) search(root->right, key, root);
	else search(root->left, key, root);
}

struct BSNode* insert(BSNode** root, int key, int val) {
	if (*root == 0) {
		*root = node_build(key, val);
		return *root;
	}
	if (key > (*root)->key) insert(&(*root)->right, key, val);
	else insert(&(*root)->left, key, val);
}

BSNode* find_left(BSNode* f) {
	BSNode* ptr = f;
	while (ptr->left != 0)
		ptr = ptr->left;
	return ptr;
}

BSNode* delete_node(BSNode** root, int key) {
	if ((*root) == 0)
		return *root;
	if (key < (*root)->key)
		(*root)->left = delete_node(&(*root)->left, key);
	else if (key > (*root)->key)
		(*root)->right = delete_node(&(*root)->right, key);
	else if ((*root)->left != 0 && (*root)->right != 0) {
		(*root)->key = find_left((*root)->right)->key;
		(*root)->right = delete_node(&(*root)->right, (*root)->key);
	}
	else {
		if ((*root)->left != 0)
			*root = (*root)->left;
		else if((*root)->right != 0)
			*root = (*root)->right;
		else 
			*root = 0;
	}
	return *root;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	struct BSNode* root = NULL;
	
	insert(&root, 4, 66);
	insert(&root, 7, 62);
	insert(&root, 1, 6);
	insert(&root, 2, 666);
	insert(&root, 15, 995);

	print(root, 1);

	root = delete_node(&root, 4);

	print(root, 1);
	//struct BSNode* val = search(root, 1);
	//if(val != NULL) cout << val->key << " " << val->val << '\n';

	return 0;
}