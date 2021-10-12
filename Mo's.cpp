#include<bits/stdc++.h>
using namespace std;

//#Rohitpratap311
//#Keep Calm And Stay Happy


using ll = long long;
using ld = long double;

//Mo's Algorithm 
//Based on sqrt decomposition 
//0 based indexing 
//blocks size might change 
//Problem here : DQUERY ( SPOJ )

int n,q,blocks=555;
int fre[1000001]={0};
vector<int> vec;
int cnt=0;

struct Q
{
  int l,r,ind;  
};

bool cmp(Q a,Q b)
{
    if(a.l/blocks==b.l/blocks) return a.r<b.r;
    else return a.l/blocks<b.l/blocks;
}

void add(int pos)
{
    fre[vec[pos]]++;
    if(fre[vec[pos]]==1) cnt++;
}

void remove(int pos)
{
    fre[vec[pos]]--;
    if(fre[vec[pos]]==0) cnt--;
}

void solveCP311()
{
    cin>>n;
    vec.resize(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    cin>>q;
    vector<Q> query;
    vector<int> ans(q);
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        Q temp;
        temp.l=l;
        temp.r=r;
        temp.ind=i;
        query.push_back(temp);
    }
    sort(query.begin(),query.end(),cmp);
    int ml=0,mr=-1;
    for(int i=0;i<q;i++)
    {
        int l=query[i].l;
        int r=query[i].r;
        int ind=query[i].ind;
        while(ml>l) { ml--; add(ml); }
        while(mr<r) { mr++; add(mr); }
        while(ml<l) { remove(ml); ml++; }
        while(mr>r) { remove(mr); mr--; }
        ans[ind]=cnt;
    }
    for(auto i:ans) cout<<i<<'\n';
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
