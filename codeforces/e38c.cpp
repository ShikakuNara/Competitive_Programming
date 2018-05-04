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
typedef long long int ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=(a);i<=(n);++i)
#define repD(i,a,n) for(int i=(a);i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define fst first
#define snd second
#define endl '\n'


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

vll sq;

void pre(){
  repA(i,1,4*10000){
    sq.pb(i*i);
  }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    pre();
    int t;cin>>t;
    rep(aa,t){
      int x;cin>>x;int ff=1;
      if(x==0){cout<<"1 1\n";continue;}

      int i=lower_bound(all(sq),x)-sq.begin();
      while(i<sq.size()){
        ll si=sqrt(sq[i]),sj=sqrt(sq[i]-x);
        if(sj!=0&&sj*sj==sq[i]-x){

          int m=si/sj-1;if(m==0)m++;
          // cout<<"newm"<<","<<si<<","<<sj<<endl;
          // cout<<"m->"<<m<<endl;
          while(si/m>sj)m++;//cout<<"m->"<<m<<endl;
          if(si/m==sj){
            cout<<si<<" "<<m<<endl;
            ff=0;
            break;
          }
        }
        i++;
      }

      if(ff)cout<<-1<<endl;
    }


    return 0;
}
