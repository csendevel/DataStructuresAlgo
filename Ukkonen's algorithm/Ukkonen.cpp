 2.81 KB

#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
#include<cstring>
#include<string>
using namespace std;
int MAXN = 100100;
class position
{
public:
    position(int v, int l): v(v), l(l) {}
    int v, l;
};
 
class node
{
public:
    node(int l, int r, int par): l(l), r(r), par(par), link(-1){}
    node(): r(MAXN), link(-1){}
    int l, r, par, link;
    map<char, int> next;
};
int szt;
int szs;
char s[100100];
node suffTree[200200];
 
 
int link(int v);
 
 
int leng(int v)
{
    return suffTree[v].r-suffTree[v].l;
}
 
int addToParent(int l, int r, int par)
{
    int nid= szt++;
    suffTree[nid] = node(l, r, par);
    return suffTree[par].next[s[l]] = nid;
}
 
int splitEdge(position pos)
{
    int v = pos.v;
    int up = pos.l;
    int down = leng(v)-up;
    if(up == 0) return v;
    if(down == 0) return suffTree[v].par;//return par;
    int mid = addToParent(suffTree[v].l, suffTree[v].l+down, suffTree[v].par);
    suffTree[v].l += down;
    suffTree[v].par = mid;
    suffTree[mid].next[s[suffTree[v].l]] = v;
    return mid;
}
 
position readChar(position pos, char c)
{
    int v = pos.v;
    int up = pos.l;
    if(up)
        return s[suffTree[v].r-up]==c?position(v,up-1):position(-1,-1);
    else
    {
        int w = suffTree[v].next.find(c)!=suffTree[v].next.end()?suffTree[v].next[c]:-1;
        return w!=-1?position(w, leng(w)-1):position(-1,-1);
    }
}
 
position addChar(position pos, int i)
{
    while(true)
    {
        position npos = readChar(pos, s[i]);
        if(npos.v != -1)
            return npos;
        else
        {
            int mid = splitEdge(pos);
            addToParent(i, MAXN, mid);
            pos = position(link(mid), 0);
            if(mid == 0) return pos;
        }
    }
}
 
position goDownFast(int v, int l, int r)
{
    if(l == r) return position(v, 0);
    while(true)
    {
        v = suffTree[v].next[s[l]];
        if(leng(v) >= r-l) return position(v, leng(v)-r+l);
        l += leng(v);
    }
}
 
int link(int v)
{
    if(suffTree[v].link == -1)
        suffTree[v].link = splitEdge(goDownFast(link(suffTree[v].par), suffTree[v].l+(suffTree[v].par==0), suffTree[v].r));
    return suffTree[v].link;
}
 
void makesuffTree()
{
    szt = 1;
    node root(-1, -1, -1);
    root.link = 0;
    suffTree[0] = root;
    position pos(0, 0);
    for(int i = 0; i < szs; i++)
        pos = addChar(pos, i);
}
 
vector<int> vid;
vector<int> par;
vector<int> l;
vector<int> r;
void print(node &n, int nid)
{
    vid.push_back(nid);
    par.push_back(n.par);
     l .push_back(n. l );
     r .push_back(n. r==MAXN?szs:n.r );
     for(map<char, int>::iterator it = n.next.begin(); it != n.next.end(); it++)
         print(suffTree[it->second],it->second);
}
int ord[200200];
int main()
{
    scanf("%s", s);
    szs = strlen(s);
    makesuffTree();
    print(suffTree[0],0);
 
    cout << par.size() << endl;
    ord[vid[0]]=0;
    for(int i = 1; i < par.size(); i++)
    {
        printf("%d %d %d\n", ord[par[i]], l[i], r[i]);
        ord[vid[i]]=i;
    }
 
 
    return 0;
}
