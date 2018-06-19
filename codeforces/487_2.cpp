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
clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
#endif
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

string s;
void Print(){
  rep(i,sz(s))
    if(s[i]!='.')cout<<s[i];
    else cout<<"0";
}

char nott(char a){
  if(a=='0')return '1';
  else return '0';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    int n,p;cin>>n>>p;
    cin>>s;

    rep(i,sz(s)){
      for(int j=i+p;j<sz(s);j+=p)
        if(s[i]=='1'){
          if(s[j]=='0'){Print();return 0;}
          else if(s[j]=='.'){s[j]='0';Print();return 0;}
        }
        else if(s[i]=='0'){
          if(s[j]=='1'){Print();return 0;}
          else if(s[j]=='.'){s[j]='1';Print();return 0;}
        }
        else{
          if(s[j]=='.'){s[i]='1',s[j]='0';Print();return 0;}
          else if(s[j]=='1'){s[i]='0';Print();return 0;}
          else if(s[j]=='0'){s[i]='1';Print();return 0;}
        }
    }
    cout<<"No\n";




    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
