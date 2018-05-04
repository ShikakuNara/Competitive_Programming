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

const int MAX = 100009;
const int MOD = 1e9+7;

ll p[MAX] = {0}, r[MAX] = {0}, cnt[MAX] = {0};

ll findset(ll i)
{
  if(p[i]!=i)p[i]=findset(p[i]);
  return p[i];
}

void merge(ll i,ll j)
{
  if(p[i]==p[j])return;
  i=findset(i),j=findset(j);
  if(r[i]>r[j]){p[j] = i;return;}
  p[i]=j;
  if(r[i]==r[j])r[j]++;

  return;
}

bool sameset(ll i,ll j){return findset(i)==findset(j);}

void build_ds(ll n)
{
  repA(i,0,n)p[i]=i;
  repA(i,0,n)cnt[i]=1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif


    ll a[] = {1,2,3,4,5}, n=6;

    build_ds(n);

    merge(1,2), merge(4, 5);

    cout<< findset(1)<<", " << findset(5) << ", " << findset(3)<<end;
    cout << sameset(1, 2)<<end;

    merge(2, 5);
    cout << findset(3) << ", " << findset(5)<<end;
    cout<<sameset(1, 4);


    return 0;
}
