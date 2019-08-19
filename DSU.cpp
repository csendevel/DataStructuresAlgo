#include <iostream>
#include <stdio.h>

using namespace std;

const int maxn = 100010;
int n,m,q;

int fvert[maxn], svert[maxn], edge[maxn],ans[maxn];
int dad[maxn],r[maxn];
bool u[maxn];

int find_set(int x){
    if(dad[x] == x)return x;
    else return dad[x] = find_set(dad[x]);
}

int set_union(int x, int y){
    x = find_set(x);
    y = find_set(y);
    if(x == y)return 0;
    else{
        if (r[x] < r[y]) 
            swap (x, y);
        dad[y] = x;
        if (r[x] == r[y])
            r[x]++;
        return 1;
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; i++){
        scanf("%d %d",fvert + i, svert + i);
    }
    scanf("%d",&q);
    for(int i = 0; i < q; i++){
        scanf("%d",edge + i);
        u[--edge[i]] = true;
    }
    
    int c = n;
    for (int i = 0; i < n; i ++)dad[i] = i;
    
    return 0;
}

//http://acm.timus.ru/problem.aspx?space=1&num=1671
