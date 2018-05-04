#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;
typedef stack < pair<int, int> > sii;
typedef queue < ll > qll;

#define sz(a) (ll) ((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define tr(c,i)       for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)  ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define end '\n'
#define fi first
#define se second
#define PI 3.14159265

const int MAX = 300009;
const int MOD = 1e9+7;

// Functions
ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}
ll abs(ll a, ll b){
  if( a > b)
    return a-b;

  return b-a;
}
double abs(double a, double b){
  if( a > b)
    return a-b;

  return b-a;
}

ll n, q;
ll noti= 0, j = 0; qll que, a[MAX]; std::map<ll, bool> mp;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin>>n>>q;
    for (size_t i = 0; i < q; i++) {
      ll tmp; cin>>tmp;
      if(tmp == 1)
      {
        ll x; cin>>x; j++, x--;

        a[x].push(j);
        que.push(j);

        noti++;
        cout<<noti<<end;
      }
      else if(tmp == 2)
      {
        ll x, cnt = 0; cin>>x; x--;

        while(!a[x].empty())
        {
          ll y = a[x].front();
          a[x].pop();
          if( mp[y] == 0)
          {
            mp[y] = 1;
            cnt++;
          }
        }


        noti -= cnt;
        cout<<noti <<end;
      }
      else
      {
        ll t, cnt = 0; cin>>t;
        while((!que.empty()) && que.front() <= t)
        {
          ll u = que.front();
          if(mp[u] == 0)
          {
            mp[u] = 1;
            cnt++;
          }
          que.pop();
        }


        noti -= cnt;
        cout<<noti<<end;
      }
    }


    return 0;
}
