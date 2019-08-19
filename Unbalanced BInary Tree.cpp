#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <string.h>
#include <map>
#include <set>

#define N 200
#define  INF (1 << 30)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

struct Tree {
	int val;
	Tree* left;
	Tree* right;
};

void new_node(int val, Tree** node) {
	if ((*node) == NULL) {
		(*node) = new Tree;
		(*node)->val = val;
		(*node)->right = NULL;
		(*node)->left = NULL;
		return;
	}
	if (val >= (*node)->val) new_node(val, &(*node)->right);
	else new_node(val, &(*node)->left);
}

void destroy_tree(Tree* node) {
	if (node != NULL) {
		destroy_tree(node->right);
		destroy_tree(node->left);
		delete(node);
	}
}


// search & count //
Tree* min_value(Tree* node) {
	if (node->left != NULL) 
		min_value(node->left);
	else 
		return node;
}

Tree* max_value(Tree* node) {
	if (node->right != NULL) 
		max_value(node->right);
	else 
		return node;
}

Tree* search(Tree* node, int value) {
	if (node == NULL)
		return NULL;
	if (node->val == value) return node;
	if (value > node->val) search(node->right, value);
	else search(node->left, value);
}

int tree_height(Tree* node) {
	int l = 0, r = 0;
	if (node == NULL) return 0;
	if(node->right != NULL) r = tree_height(node->right);
	if (node->left != NULL) l = tree_height(node->left);
	if (r > l) return r + 1;
	else return l + 1;
}

int list_count(Tree* node) {
	if (node == NULL) return 0;
	if (!node->right && !node->left) return 1;
	return list_count(node->left) + list_count(node->right);
}

int nodes_count(Tree* node) {
	if (node == NULL) return 0;
	return nodes_count(node->left) + nodes_count(node->right) + 1;
}

void TreeTraversalAndPrint(Tree* Root) {
	if (Root != NULL) {
		cout << Root->val << endl;
		TreeTraversalAndPrint(Root->left);
		TreeTraversalAndPrint(Root->right);

	}
}

void TreeTraversalAndPrint2(Tree* Root) {
	if (Root != NULL) {
		TreeTraversalAndPrint2(Root->left);
		TreeTraversalAndPrint2(Root->right);
		cout << Root->val << endl;
	}
}
void TreeTraversalAndPrint3(Tree* Root) {
	if (Root != NULL) {
		TreeTraversalAndPrint2(Root->left);
		cout << Root->val << endl;
		TreeTraversalAndPrint2(Root->right);
	}
}

void Print(Tree**node, int l)
{
	int i;

	if (*node != NULL)
	{
		Print(&((**node).right), l + 1);
		for (i = 1; i <= l; i++) cout << "   ";
		cout << (**node).val << endl;
		Print(&((**node).left), l + 1);
	}
}

int n, tmp, h;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	//freopen("tree.in", "rt", stdin);
	//freopen("tree.out", "wt", stdout);

	Tree* binTree = NULL;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		new_node(tmp, &binTree);
	}

	h = tree_height(binTree);

	cout << h << '\n';

	//system("pause");
	return 0;
}
