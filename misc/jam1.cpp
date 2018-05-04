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

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

int cs=0,cc=0,a[35]={0};

int test(){
  int dam=0,j=1;
  rep(i,cc+1){
    dam+=j*a[i];
    j*=2;
  }
  return dam;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif


    int t;cin>>t;
    rep(aa,t){
      fill(a);cc=0,cs=0;
      int d;cin>>d;
      string s;cin>>s;


      rep(i,sz(s)){
        if(s[i]=='C')cc++;
        else cs++,a[cc]++;
      }



      if(cs>d)cout<<"Case #"<<aa+1<<": "<<"IMPOSSIBLE\n";
      else{
        int dam=test();
        // cout<<dam<<endl;

        int mov=0;
        while(dam>d&&cc){
          while(a[cc]==0&&cc)cc--;
          if(cc<0)break;
          a[cc]--;mov++;
          a[cc-1]++;


          dam=test();
          // rep(i,10)cout<<a[i]<<',';cout<<endl;
          // cout<<dam<<endl;
        }

        cout<<"Case #"<<aa+1<<": "<<mov<<endl;

      }
    }


    return 0;
}
