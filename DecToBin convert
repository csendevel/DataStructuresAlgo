#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

long long t,n,c;
int p[1000000];

string to_bin_str(unsigned long long n){
    c = 0;
    string result = "";
    do
    {
        result = (char)('0' + (n % 2)) + result; 
        if(n % 2 == 1)c++; // bit counter
        n = n / 2;
    } while (n > 0);
    return result;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    for(int i = 2; i < 1000000; i++){
        if(p[i] == 0){
            for(int j = i + i; j < 1000000; j += i)
                p[j] = 1;
        }
    } 
    
    for(int i = 1; i < 1000; i++){
        //if(p[i] == 0)cout << i << " " << to_bin_str(i) << endl;
        cout << i << " " << to_bin_str(i) << endl;
    }
    return 0;
}
