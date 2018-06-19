#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// using namespace __gnu_pbds;
using namespace std;
#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a,b) (make_pair((a),(b)) )
#define all(c)  (c).begin(),(c).end()
#define fill(a) (memset((a), 0, sizeof (a)))
#define fillA(a) (memset((a), -1, sizeof (a)))
#define trav(a,x) for(auto& (a):(x))
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=(a);i<=(n);++i)
#define repD(i,a,n) for(int i=(a);i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define fst first
#define snd second
#define endl '\n'

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<ll, ll> pp;
typedef pair<ll, pp> ppp;
typedef vector<pp > vpp;

#ifdef LOCAL_TEST
clock_t time_p=clock();void fin(){time_p=clock()-time_p;cerr<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";}
#endif
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 400009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

bool comp(ppp a,ppp b){
  return a.snd.fst<b.snd.fst;
}

pp a[MAX];



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");time_p=clock();
    #endif

    int t;cin>>t;
    rep(i,t){
      int n;cin>>n;
      rep(i,n)cin>>a[i].fst>>a[i].snd;
      rep(i,n)a[i].snd*=-1;
      sort(a,a+n);
      rep(i,n)a[i].snd*=-1;

      priority_queue<int> take,ntake;
      ll sum=0;int ans=0;
      repD(i,n-1,0){
        if(!take.empty()&&a[i].snd<=take.top()){
          take.push(a[i].snd);
          sum+=a[i].snd;
        }
        else ntake.push(-a[i].snd);

        while(!take.empty()&&sz(take)*a[i].fst<sum){
          int a=take.top();take.pop();
          sum-=a;
          ntake.push(-a);
        }

        while(!ntake.empty()&& (sz(take)+1)*a[i].fst>=sum-ntake.top() ){
          int a=-ntake.top();ntake.pop();
          take.push(a);
          sum+=a;
        }

        ans=max(ans,sz(take));
      }
      cout<<ans<<'\n';
    }




    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
