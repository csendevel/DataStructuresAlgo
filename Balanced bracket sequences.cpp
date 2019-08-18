 #include <iostream>
    #include <stdio.h>
    #include <algorithm>
    #include <math.h>
    #include <stack>
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
    bool g;
    stack <char> st;
    
    int main() {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
    	//freopen("input.txt", "rt", stdin);
    	//freopen("output.txt", "wt", stdout);
     
        cin >> n;
        
        while(n--){
            cin >> s;
        
            g = false;
            
            for(int i = 0; i < s.size(); i++){
                if(s[i] == '(') st.push(s[i]); 
                if(s[i] == '[') st.push(s[i]);
                if(s[i] == ')'){
                    if(!st.empty()) {
                        if(st.top() == '(') st.pop();
                        else g = true;
                    } else g = true;
                }
                if(s[i] == ']'){
                    if(!st.empty()) {
                        if(st.top() == '[') st.pop();
                        else g = true; 
                    } else g = true;
                }
            }
            
            if(g || !st.empty()) cout << "No\n";
            else cout << "Yes\n";
            
            st = stack <char> ();
        }
        
        return 0;
}
