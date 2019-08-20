#include <iostream>
#include <stdio.h>
#include <cassert>
#include <algorithm>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <string.h>
#include <time.h>

#define N 500000
#define  INF (1 << 30)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int heapsize;
ll ans;
ll heap[N];

void make_heap() {
	int index = 0, parent = 0;
	for (int i = 0; i < heapsize; i++) {
		index = i;
		while (index != 0) {
			parent = (index - 1) / 2;
			if (heap[index] <= heap[parent]) break;
			swap(heap[index], heap[parent]);
			index = parent;
		}
	}
}

//heap sort
void heapify(int i) {
	int l = 2 * i, r = 2 * i + 1;
	if (l < heapsize) {
		if (heap[i] < heap[l]) {
			swap(heap[i], heap[l]);
			heapify(l);
		}
	}
	if (r < heapsize) {
		if (heap[i] < heap[r]) {
			swap(heap[i], heap[r]);
			heapify(r);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> heapsize;

	for (int i = 0; i < heapsize; i++) cin >> heap[i];

	make_heap();

	return 0;
}
