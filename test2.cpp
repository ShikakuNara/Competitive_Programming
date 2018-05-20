#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
#define trav(a,x) for(auto& (a):(x))
typedef pair<long long,long long> pll;
class DSU{ public:

	vector<long long> parent,sz;

	DSU(long long n=0): parent(n),sz(n)
	{ for(long long i=0; i<n; i++) { parent[i] = i; sz[i]=1; } }

	void join(long long a, long long b)
	{ if(sz[find(b)]<=sz[find(a)]) { parent[find(b)] = find(a); sz[find(a)]+=sz[find(b)];} else{parent[find(a)] = find(b); sz[find(a)]+=sz[find(b)];}}

	long long find(long long a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }

	bool check(long long a, long long b){ return find(a) == find(b); }
};
long long n;
set<pll> st;
map<long long,long long> mp;
bool v[100005];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifdef LOCAL_TEST
	ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
	#endif

	long long n,a,i,curr,pos,k;
	pll p;
	memset(v,false,sizeof(v));
	cin>>n;
	DSU dsu(n);
	for(i=0;i<n;i++)
	{
		cin>>a;
		st.insert(pll(a,i));
	}
	curr=0;
	k=0;
	while(!st.empty())
	{
		p=*st.begin();
		cout<<p.first<<','<<p.second<<endl;
		st.erase(st.begin());
		pos=p.second;
		mp[dsu.sz[dsu.find(pos)]]++;
		v[pos]=true;
		if(pos!=0&&v[pos-1])
		{
			mp[dsu.sz[dsu.find(pos-1)]]--;
			if(mp[dsu.sz[dsu.find(pos-1)]]==0)
				mp.erase(dsu.sz[dsu.find(pos-1)]);
			mp[dsu.sz[dsu.find(pos)]]--;
			if(mp[dsu.sz[dsu.find(pos)]]==0)
				mp.erase(dsu.sz[dsu.find(pos)]);
			dsu.join(pos-1,pos);
			mp[dsu.sz[dsu.find(pos)]]++;
		}
		if(v[pos+1])
		{
			mp[dsu.sz[dsu.find(pos+1)]]--;
			if(mp[dsu.sz[dsu.find(pos+1)]]==0)
				mp.erase(dsu.sz[dsu.find(pos+1)]);
			mp[dsu.sz[dsu.find(pos)]]--;
			if(mp[dsu.sz[dsu.find(pos)]]==0)
				mp.erase(dsu.sz[dsu.find(pos)]);
			dsu.join(pos+1,pos);
			mp[dsu.sz[dsu.find(pos)]]++;
		}
		if(mp.size()==1&&(mp.begin()->second)>curr)
		{
			cout<<mp.begin()->second<<"okay\n";
			curr=mp.begin()->second;
			k=p.first+1;
		}
		else{
			cout<<"Map:";
			trav(it,mp)cout<<it.first<<":"<<it.second<<"-";cout<<endl;
		}
	}
	cout<<k<<"\n";
	return 0;
}
