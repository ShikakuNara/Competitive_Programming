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




int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll t;cin>>t;
    rep(aa,t){
      ll a[MAX];
      priority_queue<ll> pq;
      vll b;

      ll n,l;cin>>n>>l;
      ll left=n,tn=n/2+(n%2);

      rep(i,l){
        cin>>a[i];left-=a[i];
      }

      if(100%n==0){
        cout<<"Case #"<<aa+1<<": "<<100<<endl;
        continue;
      }
      // else if(100%n>=tn){
      //   rep(i,l)b.pb(a[i]);
      //
      //   while(left>0){
      //     ll t=0;
      //     while(t<left&&(t*100)%n<tn)t++;
      //
      //     b.pb(t);
      //     left-=t;
      //   }
      //
      //   ll ans=0;
      //
      //   rep(i,sz(b)){
      //     if(((b[i]*100+n)%n)<tn)ans+=(b[i]*100)/n;
      //     else ans+=(b[i]*100)/n+1;
      //   }
      //
      //   cout<<"Case #"<<aa+1<<": "<<ans<<endl;
      //   continue;
      // }

      ll ans=0;
      rep(i,l){
        if(((a[i]*100)%n)<tn){
          pq.push((a[i]*100)%n);
          if(((a[i]*100+n)%n)<tn)ans+=(a[i]*100)/n;//cout<<a[i]<<"add\n";
          else ans+=(a[i]*100)/n+1;//cout<<a[i]<<"add\n";
        }
        else b.pb(a[i]);
      }


      while(!pq.empty()&&left>0){
        ll c=pq.top();pq.pop();


        ll t=0;
        while(t<left&&(c+(t)*100+n)%n<tn)t++;

        if((c+(t)*100+n)%n<tn)ans+=(c+(t)*100)/n;
        else ans+=(c+(t)*100)/n+1;//cout<<"one";

        // b.pb(c+t);
        // cout<<c<<"::"<<t<<","<<(c+(t)*100)/n<<endl;
        left-=t;
      }

      // while(!pq.empty()){
      //   // cout<<pq.top()<<"lo\n";
      //   // b.pb(pq.top()),pq.pop();
      // }

      while(left>0){
        ll t=1;
        while(t<left&&(t*100)%n<tn)t++;

        b.pb(t);
        // cout<<t<<"<>\n";
        left-=t;
      }

      rep(i,sz(b)){
        // cout<<b[i]<<".."<<endl;
        if(((b[i]*100+n)%n)<tn)ans+=(b[i]*100)/n;
        else ans+=(b[i]*100)/n+1;
      }

      cout<<"Case #"<<aa+1<<": "<<ans<<endl;

    }

    return 0;
}
