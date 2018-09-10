#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int h[25001];
int heapsize,t;

// heap sort
void heapify(int i){
    int l = 2*i, r = 2*i + 1;
    int temp;
    if(l < heapsize){
        if(h[i] < h[l]){
            swap(h[i],h[l]);
            heapify(l);
        }
    }
    if(r < heapsize){
        if(h[i] < h[r]){
            swap(h[i],h[r]);
            heapify(r);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> heapsize;
    cin >> h[1];
    
    for(int i = 2; i < heapsize; i++){
        cin >> h[i];
        int k = i;
        while(k/2 > 0){
            if(h[k/2] < h[k]){
                swap(h[k],h[k/2]);
                k/=2;
            } else break;
        }
    }
    
    while(cin >> t && t != -1){
        cout << h[1] << endl;
        h[1] = t;
        heapify(1);
    }
    return 0;
} 
