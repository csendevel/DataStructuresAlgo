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

#define N 71000
#define  INF (1 << 30)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

struct AVLNode {
	int key;
	unsigned char height;
	AVLNode* left, * right;

	AVLNode(int k) { key = k; left = right = 0; height = 1; }
};

unsigned char height(AVLNode* v) {
	return v ? v->height : 0;
}

void correct_h(AVLNode* node) {
	if (node == 0) return;
	node->height = max(height(node->left), height(node->right)) + 1;
}

unsigned char defect_h(AVLNode* node) {
	if (node == 0) return 0;
	return height(node->right) - height(node->left);
}

void print(AVLNode* node, int offset) {
	if (node == 0) return;
	for (int i = 0; i < offset; i++) cout << " ";
	cout << node->key << " " << node->height << " " << node << '\n';
	print(node->left, offset + 3);
	print(node->right, offset + 3);
}

AVLNode* rotate_left(AVLNode* node) {
	AVLNode* b = node->right;
	node->right = b->left;
	b->left = node;
	correct_h(node);
	correct_h(b);
	return b;
}

AVLNode* rotate_right(AVLNode* node) {
	AVLNode* b = node->left;
	node->left = b->right;
	b->right = node;
	correct_h(node);
	correct_h(b);
	return b;
}

AVLNode* balance_tree(AVLNode* v) {
	correct_h(v);

	if (defect_h(v) == 2) {
		if (defect_h(v->right) < 0)
			v->right = rotate_right(v->right);
		return rotate_left(v);
	}
	if (defect_h(v) == -2) {
		if (defect_h(v->left) > 0)
			v->left = rotate_left(v->left);
		return rotate_right(v);
	}

	return v;
}

AVLNode* insert(AVLNode* root, int key) {
	if (!root) return new AVLNode(key);

	if (key < root->key)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);

	return balance_tree(root);
}

AVLNode* find_min(AVLNode* v) {
	return v->left ? find_min(v->left) : v;
}

AVLNode* delete_min(AVLNode* v) {
	if (v->left == 0)
		return v->right;
	v->left = delete_min(v->left);
	return balance_tree(v);
}

AVLNode* remove(AVLNode* root, int key) {
	if (!root) return 0;
	if (key < root->key)
		root->left = remove(root->left, key);
	else if (key > root->key)
		root->right = remove(root->right, key);
	else {
		AVLNode* q = root->left, * r = root->right;
		delete root;
		if (!r) return q;
		AVLNode* min = find_min(r);
		min->right = delete_min(r);
		min->left = q;
		return balance_tree(min);
	}
	return balance_tree(root);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	AVLNode* root = 0;
	root = insert(root, 1);
	for (int i = 2; i < 20; i++)
		root = insert(root, i);

	print(root, 1);

	root = remove(root, 12);

	print(root, 1);
	return 0;
}