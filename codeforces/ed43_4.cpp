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
typedef pair<ll, ll> pp;
typedef pair<ll, pp > ppp;
typedef vector<pp > vpp;
typedef vector<ppp > vppp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;


int d[1000], deg[1000];
vpp e;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int n;cin>>n;
    rep(i,n)cin>>d[n-i-1];

    //add edges
    rep(i,n){
      // cout<<i<<":"<<d[i]-deg[i]<<endl;
      repA(j,i+1,i+d[i]-deg[i])e.pb(mp(i,j)),deg[j]++;
      deg[i]+=d[i];
    }



    //check other vertices and add back edges.
    int p=0;
    repA(i,n,d[0])sum+=deg[i]-
    while(sum%2){
      p++;
    }
    repA(i,n,d[0]){
      repA(j,i+1,i+d[p]-1){
        e.pb(mp(i,j));
        deg[i]++,deg[j]++;
      }
    }



    int j=n-1,k=1;
    repA(i,n,d[0]){
      while(deg[i]<d[n-1]){
        if(j-k<=0)j=i-1,k++;
        else if(deg[j]==deg[j-k])j--;

        if(j-k<=0)j=i-1,k++;


        deg[j]++;deg[i]++;
        e.pb(mp(i,j));
      }
    }

    // if(sz(e)>=1e6){
    //   int a=0;
    //   while(a==0)a++,a--;
    // }

    cout<<sz(e)<<endl;
    trav(it,e)cout<<it.fst+1<<' '<<it.snd+1<<endl;










    return 0;
}
