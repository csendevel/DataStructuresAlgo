    #include <iostream>
    #include <stdio.h>
    #include <algorithm>
    #include <math.h>
    #include <vector>
    #include <string>
    #include <string.h>
     
    #define N 700000
    #define s 708
    #define  INF (1 << 30)
     
    using namespace std;
     
    typedef long long ll;
    typedef unsigned long long ull;
    typedef pair <int, int> pii;
    typedef pair <ll, ll> pll;
     
    struct block {
    	bool isReversed = false;
    	bool isUpdated = false;
     
    	int value = 0;
     
    	vector <int> a;
    	vector <int> b;
     
    	void push_back(int x) {
    		a.push_back(x);
    		b.push_back(x);
    	}
     
    	void rev() {
    		reverse(a.begin(), a.end());
    	}
     
    	void update() {
    		for (int i = 0; i < a.size(); i++) {
    			a[i] = value;
    			b[i] = value;
    		}
    	}
     
    	int get_ans(int x) {
    		int tmp = lower_bound(b.begin(), b.end(), x) - b.begin();
    		int ans = b.size() - tmp;
    		return ans;
    	}
     
    	void block_sort() {
    		sort(b.begin(), b.end());
    	}
     
    	void clear_to(int pos) {
    		for (int i = a.size() - 1; i >= pos; i--)
    			a.pop_back();
    	}
     
    	void clear() {
    		value = 0;
    		a.clear(); b.clear();
    		isReversed = false; isUpdated = false;
    	}
     
    	void mem_cpy() {
    		b.clear(); b.resize(a.size());
    		for (int i = 0; i < a.size(); i++) b[i] = a[i];
    	}
     
    };
     
    int n, m, cnt;
    int arr[N];
    string oper;
     
    block sqrt_dec[15 * s];
    vector <int> Index;
     
    void Build() {
     
    	Index.clear();
     
    	for (int i = 0; i <= cnt + 1; i++)
    		sqrt_dec[i].clear();
     
    	cnt = ceil((double)n / s);
        
        Index.resize(cnt);
        
    	for (int i = 0; i < cnt; i++)
    		Index[i] = i;
     
    	for (int i = 0; i < n; i++)
    		sqrt_dec[i / s].push_back(arr[i]);
     
    	for (int i = 0; i < cnt; i++)
    		sqrt_dec[i].block_sort();
     
    }
    
    void Push(int i) {
    	if (sqrt_dec[i].isReversed) {
    		sqrt_dec[i].rev();
    		sqrt_dec[i].isReversed = false;
    	}
    	if (sqrt_dec[i].isUpdated) {
    		sqrt_dec[i].update();
    		sqrt_dec[i].isUpdated = false;
    		sqrt_dec[i].value = 0;
    	}
    }
    
     void Rebuild(){
        int count = 0;
            
        for(int i = 0; i < cnt; i++) Push(Index[i]);
            
        for(int i = 0; i < cnt; i++){
                
            for(int j = 0; j < sqrt_dec[Index[i]].a.size(); j++){
                arr[count + j] = sqrt_dec[Index[i]].a[j];
           }
                
            count += sqrt_dec[Index[i]].a.size();
        }
            
        Build();
    }
     
    void Split(int p) {
     
    	int l = 0;
     
    	for (int i = 0; i < cnt; i++) {
    		if (p > l && p <= l + sqrt_dec[Index[i]].a.size() - 1) {
     
    			Push(Index[i]);
     
    			cnt++;
    			Index.insert(Index.begin() + i + 1, cnt - 1);
     
    			for (int j = p - l; j < sqrt_dec[Index[i]].a.size(); j++) {
    				sqrt_dec[Index[i + 1]].push_back(sqrt_dec[Index[i]].a[j]);
    			}
     
    			sqrt_dec[Index[i + 1]].block_sort();
     
    			if(p > 0) sqrt_dec[Index[i]].clear_to(p - l);
     
    			sqrt_dec[Index[i]].mem_cpy();
     
    			sqrt_dec[Index[i]].block_sort();
     
    			break;
     
    		}
    		l += sqrt_dec[Index[i]].a.size();
    	}
    }
     
    void Set(int l, int r, int v) {
        
        if(cnt >= 5 * s) Rebuild();
        
    	int left = 0, li = 0, ri = 0;
     
    	for (int i = 0; i < cnt; i++) {
    		if (l >= left && l <= left + sqrt_dec[Index[i]].a.size()) {
    			if (l != left + 1) {
    				Split(l - 1);
    				li = i + 1;
    			}
    			else li = i;
     
    			break;
    		}
    		left += sqrt_dec[Index[i]].a.size();
    	}
     
    	left = 0;
     
    	for (int i = 0; i < cnt; i++) {
    		if (r >= left && r <= left + sqrt_dec[Index[i]].a.size()) {
    			if (r != left + sqrt_dec[Index[i]].a.size()) 
    				Split(r);
     
    			ri = i;
    			break;
    		} 
    		left += sqrt_dec[Index[i]].a.size();
    	}
     
    	for (int i = li; i <= ri; i++) {
    		sqrt_dec[Index[i]].isUpdated = true;
    		sqrt_dec[Index[i]].value = v;
    	}
    }
     
    int Get(int l, int r, int v) {
        
        if(cnt >= 5 * s) Rebuild();
        
    	int left = 0, ans = 0, li = 0, ri = 0;
     
    	for (int i = 0; i < cnt; i++) {
    		if (l >= left + 1 && l <= left + sqrt_dec[Index[i]].a.size()) {
    			if (l != left + 1) {
    				Split(l - 1);
    				li = i + 1;
    			}
    			else li = i;
    			break;
    		}
    		left += sqrt_dec[Index[i]].a.size();
    	}
     
    	left = 0;
     
    	for (int i = 0; i < cnt; i++) {
    		if (r >= left && r <= left + sqrt_dec[Index[i]].a.size()) {
    			if (r != left + sqrt_dec[Index[i]].a.size())
    				Split(r);
     
    			ri = i;
    			break;
    		}
    		left += sqrt_dec[Index[i]].a.size();
    	}
     
    	for (int i = li; i <= ri; i++) {
    		if (sqrt_dec[Index[i]].isUpdated) {
    			if(sqrt_dec[Index[i]].value >= v) ans += sqrt_dec[Index[i]].b.size();
    		}
    		else
    			ans += sqrt_dec[Index[i]].get_ans(v);
    	}
     
    	return ans;
    }
     
    void Reverse(int l, int r) {
        
        if(cnt >= 5 * s) Rebuild(); 
        
    	int left = 0, li = 0, ri = 0;
     
    	for (int i = 0; i < cnt; i++) {
    		if (l >= left && l <= left + sqrt_dec[Index[i]].a.size()) {
    			if (l != left + 1) {
    				Split(l - 1);
    				li = i + 1;
    			}
    			else li = i;
     
    			break;
    		}
    		left += sqrt_dec[Index[i]].a.size();
    	}
     
    	left = 0;
     
    	for (int i = 0; i < cnt; i++) {
    		if (r >= left && r <= left + sqrt_dec[Index[i]].a.size()) {
    			if (r != left + sqrt_dec[Index[i]].a.size())
    				Split(r);
     
    			ri = i;
    			break;
    		}
    		left += sqrt_dec[Index[i]].a.size();
    	}
     
    	while (li < ri) {
    		sqrt_dec[Index[li]].isReversed = (sqrt_dec[Index[li]].isReversed) ? false : true;
    		sqrt_dec[Index[ri]].isReversed = (sqrt_dec[Index[ri]].isReversed) ? false : true;
    		swap(Index[li], Index[ri]);
    		li++; ri--;
    	}
     
    	if(li == ri) sqrt_dec[Index[li]].isReversed = (sqrt_dec[Index[li]].isReversed) ? false : true;
    }
     
    void block_out() {
    	cout << "********************\n";
    	cout << "Sqrt_dec blocks\n";
     
    	for (int i = 0; i < cnt; i++) {
    		cout << " Block " << i << '\n';
    		cout << " Index " << Index[i] << '\n';
    		cout << " Flags:\n ";
    		cout << " IsReversed " << sqrt_dec[Index[i]].isReversed << '\n';
    		cout << " IsUpdated " << sqrt_dec[Index[i]].isUpdated << " value " << sqrt_dec[Index[i]].value << '\n';
     
    		cout << " a: \n";
    		for (int j = 0; j < sqrt_dec[Index[i]].a.size(); j++) {
    			cout << sqrt_dec[Index[i]].a[j] << " ";
        	}
    		cout << "\n b: \n";
    		for (int j = 0; j < sqrt_dec[Index[i]].b.size(); j++) {
    			cout << sqrt_dec[Index[i]].b[j] << " ";
    		}
    		cout << '\n';
    	}
    	cout << "********************\n";
    }
    
    int main() {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
    	//freopen("out.txt", "rt", stdin);
    	//freopen("o.txt", "wt", stdout);
     
    	cin >> n;
     
    	for (int i = 0; i < n; i++) cin >> arr[i];
     
    	Build();

    	cin >> m;
     
    	int l, r, v;
     
    	while (m--) {
    		cin >> oper;
    		if (oper == "get") {
    			cin >> l >> r >> v;
    			cout << Get(l, r, v) << '\n';
    			//block_out();
    		}
    		if (oper == "set") {
    			cin >> l >> r >> v;
    			Set(l, r, v);
    			//block_out();
    		}
    		if (oper == "reverse") {
    			cin >> l >> r;
    			Reverse(l, r);
    			//block_out();
    		}
    	}
     
    	return 0;
    }
