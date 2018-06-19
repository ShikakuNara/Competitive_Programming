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
typedef pair<ll, char> pp;
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

int n=50,m=50;
int a[10];pp f[20];

void pre(){
  rep(i,4)f[i]=mp(a[i],'A'+i);
  sort(f,f+4);
}




int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    cin>>a[0]>>a[1]>>a[2]>>a[3];
    pre();

    cout<<"50 50\n";
    int i=0;

    while(f[0].fst!=1){
        if(i%2==0)
          rep(j,m){
            if(f[0].fst==1)cout<<f[3].snd;
            else if(j%2)cout<<f[0].snd,f[0].fst--;
            else cout<<f[3].snd;
          }
        else rep(j,m)cout<<f[3].snd;
        cout<<endl;
        i++;
    }
    f[3].fst--;

    rep(j,m)cout<<f[3].snd;cout<<endl;i++;
    rep(j,m)cout<<f[0].snd,f[0].fst--;cout<<endl;i++;

    repA(k,1,3){
      while(f[k].fst!=0){
          if(i%2==0)
            rep(j,m){
              if(f[k].fst==0)cout<<f[0].snd;
              else if(j%2)cout<<f[k].snd,f[k].fst--;
              else cout<<f[0].snd;
            }
          else rep(j,m)cout<<f[0].snd;
          cout<<endl;
          i++;
      }
      rep(j,m)cout<<f[0].snd;cout<<endl;i++;
    }

    while(i<n){
      rep(j,m)cout<<f[0].snd;cout<<endl;i++;
    }



















    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
