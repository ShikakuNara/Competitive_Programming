#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")

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
typedef pair<int, int> pp;
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 1000009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

int a[MAX],b[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int t;cin>>t;
    rep(aa,t){
      string s,t;cin>>s>>t;
      int t1=0,t0=0,s1=0,s0=0,ss=0;
      rep(i,sz(t))if(t[i]=='0')t0++; else t1++;
      rep(i,sz(s))if(s[i]=='0')s0++;else if(s[i]=='1') s1++;else ss++;

      int cnt=0;
      if(t1<s1) cout<<"Case "<<aa+1<<": "<<-1<<endl;
      else if(t1+t0-s1-s0!=ss) cout<<"Case "<<aa+1<<": "<<-2<<endl;
      else{
        int d1=t1-s1,d0=t0-s0;
        rep(i,sz(s))if(s[i]=='?'){
          if(t[i]=='1'){
            if(d1)s[i]='1',d1--;
            else s[i]='0',d0--;
          }
          if(t[i]=='0'){
            if(d0>0)s[i]='0',d0--;
            else s[i]='1',d1--;
          }
          cnt++;
        }
        rep(i,sz(s))if(s[i]=='0'&&t[i]=='1'&&d0<0)s[i]='1',d0++,cnt++;
        rep(i,sz(s))if(s[i]!=t[i]&&s[i]=='1')cnt++;
        cout<<"Case "<<aa+1<<": "<<cnt<<endl;
      }
    }






    return 0;
}
