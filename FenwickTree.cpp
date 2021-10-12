#include<bits/stdc++.h>
using namespace std;

//#Rohitpratap311
//#Keep Calm And Stay Happy


using ll = long long;
using ld = long double;

//Fenwick Tree / Binary Indexed Tree
//1 based indexing .
//query(x) :- sum of int the range [1.x]
//add(i,val) :- add val to the ith index
//addRange(l,r,val) :- add val to each elements in the range [l,r];

struct FenwickTree
{
    int n;
    vector<ll> bit;
    FenwickTree(int n)
    {
        this->n=n;
        bit.assign(n+2,0);
    }
    ll query(int idx)
    {
        ll ans=0;
        while(idx>0)
        {
            ans+=bit[idx];
            idx-=(idx&-idx);
        }
        return ans;
    }
    void add(int idx,int val)
    {
        while(idx<=n)
        {
            bit[idx]+=val;
            idx+=(idx&-idx);
        }
    }
    void addRange(int l,int r,ll val)
    {
        add(l,val);
        add(r+1,-val);
    }
};

void solveCP311()
{
    ll n;
    cin>>n;
    FenwickTree fen(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solveCP311();
    }
    return 0;
}
