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
typedef long double ld;
typedef pair<ld, ld> pp;
typedef vector<pp > vpp;


// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

ld eps=0.000000001;

ld Abs(ld a){
  if(a>eps)return a;
  return -a;
}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

priority_queue<ld> pq,pq2;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int t;cin>>t;
    cout<<fixed<<setprecision(12);
    rep(aa,t){
      int n; ld a;cin>>n>>a;
      ld p=0.00000000000000000;
      ld _1=1.0000000000;
      rep(i,n){
        ld w,h;cin>>w>>h;
        p+=2*(w+h);
        pq.push(-w);
      }

      ld pM=p,pm=p,ans=10000000000000,ansi=p;

      int ff=0;
      while(!pq.empty()){
        ld c=pq.top();pq.pop();
        pq2.push(-c);

        pM+=2*(-c)*sqrt(2);
        pm+=2*(-c);

        if(pm>a){
          ld tmp=pq2.top();
          pM-=2*(tmp)*sqrt(2);
          pm-=2*(tmp);
        }
        else if(pM>a&&pm<a){
          cout<<"Case #"<<aa+1<<": "<<a<<endl;ff=1;
          break;
        }

        if(ans>Abs(pM-a))ans=Abs(pM-a),ansi=pM;
        if(ans>Abs(pm-a))ans=Abs(pm-a),ansi=pm;
      }
      if(ff==1)continue;

      cout<<"Case #"<<aa+1<<": "<<ansi<<endl;
    }



    return 0;
}
