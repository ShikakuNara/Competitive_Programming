#include <bits/stdc++.h>

#ifdef LOCAL_TEST
  #pragma comment(linker,"/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll,ll> pp;
typedef vector<pp > vpp;
typedef vector <int> vi;
typedef stack <int>  si;
typedef stack <ll> sll;
typedef stack < pair<int,int> > sii;
typedef queue < pair<int,int> > qii;

#define sz(a) (ll) ((a).size())
#define pb push_back
#define mp(a,b)       (make_pair(a,b) )
#define all(c)        (c).begin(),(c).end()
#define tr(c,i)       for(typeof((c).begin() i=(c).begin(); i!=(c).end(); i++)
#define present(c,x)  ((c).find(x)!=(c).end())
#define cpresent(c,x) (find(all(c),x)!=(c).end())
#define sortA(v)      (sort(v.begin(),v.end()))
#define sortD(v)      (sort(v.rbegin(),v.rend()))
#define fill(a)       (memset(a,0,sizeof (a)))
#define end '\n'
#define PI 3.14159265

// Functions
ll gcd(ll a,ll b){
    if (a==0)
        return b;
    return gcd(b%a,a);
}
ll lcm(ll a,ll b){
    return a * b / gcd(a,b);
}
ll abs(ll a,ll b){
  if( a > b)return a-b;
  return b-a;
}
double abs(double a,double b){
  if( a > b)return a-b;
  return b-a;
}

const int MAX=10009;
ll tree[4*MAX]={0},lazy[4*MAX]={0};

void updateU(ll i,ll s,ll e,ll us,ll ue,ll diff)
{
    if (lazy[i]!=0)
    {
        tree[i]+=(e-s+1)*lazy[i];
        if (s!=e) lazy[i*2+1]+=lazy[i],lazy[i*2+2]+=lazy[i];
        lazy[i]=0;
    }
    if (s>e||s>ue||e<us)return;
    if (s>=us&&e<=ue)
    {
        tree[i]+=(e-s+1)*diff;
        if (s!=e) lazy[i*2+1]+=diff,lazy[i*2+2]+=diff;
        return;
    }

    ll m=(s+e)/2;
    updateU(i*2+1,s,m,us,ue,diff),updateU(i*2+2,m+1,e,us,ue,diff);
    tree[i]=tree[i*2+1]+tree[i*2+2];
}

void update(ll us,ll ue,ll diff,ll n){updateU(0,0,n-1,us,ue,diff);}

ll getU(ll s,ll e,ll qs,ll qe,ll i)
{
    if (lazy[i]!=0)
    {
        tree[i]+=(e-s+1)*lazy[i];
        if (s!=e) lazy[i*2+1]+=lazy[i],lazy[i*2+2]+=lazy[i];
        lazy[i]=0;
    }
    if (s>e||s>qe||e<qs)return 0;
    if (s>=qs&&e<=qe)return tree[i];
    ll m=(s+e)/2;
    return getU(s,m,qs,qe,2*i+1)+getU(m+1,e,qs,qe,2*i+2);
}

ll get(ll qs,ll qe,ll n)
{
    if (qs<0||qe>n-1||qs>qe) {cout<<"invalid input\n"; return -1;}
    return getU(0,n-1,qs,qe,0);
}

void buildtreeU(ll arr[],ll s,ll e,ll i)
{
    if (s > e) return;
    if (s==e){tree[i]=arr[s]; return;}
    ll m=(s+e)/2;
    buildtreeU(arr,s,m,i*2+1); buildtreeU(arr,m+1,e,i*2+2);
    tree[i]=tree[i*2+1]+tree[i*2+2];
}

void buildtree(ll a[],ll  n){buildtreeU(a,0,n-1,0); return;}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ifstream cin("in.txt"); ofstream cout("out.txt");

    ll a[]={1,2,3,4,5};
    buildtree(a,5);

    for (size_t i=0; i < 2*5; i++) {
      cout << tree[i] << " ";
      /* code */
    }
    update(1,1,5,5);
    cout << end << get(0,2,5) << end;

    cout.close(); cin.close();
    return 0;
}
