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
typedef pair<ll , ll > pp;
typedef pair<ll, pp> ppp;
typedef vector<pp > vpp;

#ifdef LOCAL_TEST
clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
#endif
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

pp a[6],b[6];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    rep(i,4)cin>>a[i].fst>>a[i].snd;
    rep(i,4)cin>>b[i].fst>>b[i].snd;

    rep(i,4)a[4].fst+=a[i].fst;
    rep(i,4)a[4].snd+=a[i].snd;
    rep(i,4)b[4].fst+=b[i].fst;
    rep(i,4)b[4].snd+=b[i].snd;
    a[4].fst/=4;
    b[4].fst/=4;
    a[4].snd/=4;
    b[4].snd/=4;


    ll mx=10000,Mx=-10000;
    ll my=10000,My=-10000;
    rep(i,4)mx=min(mx,a[i].fst),my=min(my,a[i].snd);
    rep(i,4)Mx=max(Mx,a[i].fst),My=max(My,a[i].snd);

    int ff=0;
    rep(i,5){
      if(b[i].fst<=Mx&&b[i].fst>=mx){
        if(b[i].snd<=My&&b[i].snd>=my)ff=1;
      }
    }


    mx=10000,Mx=-10000;
    my=10000,My=-10000;
    sort(b,b+4);
    Mx=b[3].fst,My=b[3].snd;
    mx=b[0].fst,my=b[0].snd;

    rep(i,5){
      if(a[i].fst+a[i].snd<=Mx+My&&a[i].fst+a[i].snd>=mx+my){
        if(a[i].fst-a[i].snd<=Mx-My&&a[i].fst-a[i].snd>=mx-my)ff=1;
      }
    }

    if(ff)cout<<"YES\n";
    else cout<<"NO\n";










    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
