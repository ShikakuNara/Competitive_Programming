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
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define rep(i, n)     for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(ll i = a; i <= (n); ++i)
#define repD(i, a, n) for(ll i = a; i >= (n); --i)
#define pq(x)			    priority_queue<x,std::vector<x>,compare>
#define rpq(x)			  priority_queue<x,std::vector<x>,Rcompare>
#define PI 3.14159265
#define X first
#define Y second
#define end '\n'

// Functions
struct Rcompare{
  bool operator()(pp lhs,pp rhs){
    return lhs.X>rhs.X;
  }
}; struct compare{
  bool operator()(pp lhs,pp rhs){
    return lhs.X<rhs.X;
  }
};


ll gcd(ll a, ll b){
  if (a == 0) return b;
  return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * (b / gcd(a, b));
}
ll Abs(ll a){
  if( a > 0)
    return a;

  return -a;
}
double Abs(double a){
  if( a > 0)
    return a;

  return -a;
}
ll power(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=power(x,y/2);
  if(y%2==1)return tmp*tmp*x;
  return tmp*tmp;
}
const int MAX = 400009;
const int MOD = 1e9+7;

using namespace std;
const long long MAX_SIZE = 1100009;

// isPrime[] : isPrime[i] is true if number is prime
// prime[] : stores all prime number less than N
// SPF[] that store smallest prime factor of number
// [for Exp : smallest prime factor of '8' and '16'
// is '2' so we put SPF[8] = 2 , SPF[16] = 2 ]
vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);

// function generate all prime number less then N in O(n)
void manipulated_seive(int N)
{
    // 0 and 1 are not prime
    isprime[0] = isprime[1] = false ;

    // Fill rest of the entries
    for (long long int i=2; i<N ; i++)
    {
        // If isPrime[i] == True then i is
        // prime number
        if (isprime[i])
        {
            // put i into prime[] vector
            prime.push_back(i);

            // A prime number is its own smallest
            // prime factor
            SPF[i] = i;
        }

        // Remove all multiples of  i*prime[j] which are
        // not prime by making isPrime[i*prime[j]] = false
        // and put smallest prime factor of i*Prime[j] as prime[j]
        // [ for exp :let  i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ]
        // so smallest prime factor of '10' is '2' that is prime[j] ]
        // this loop run only one time for number which are not prime
        for (long long int j=0;
             j < (int)prime.size() &&
             i*prime[j] < N && prime[j] <= SPF[i];
             j++)
        {
            isprime[i*prime[j]]=false;

            // put smallest prime factor of i*prime[j]
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}

ll binarysearch(ll i,ll s,ll e)
{
  ll m=(s+e)/2;
  cout<<isprime[m]<<end;
  if(s==e&&isprime[m]!=i)return 0;
  if(isprime[m]==i)return 1;
  if(isprime[m]<i) return binarysearch(i,m+1,e);
  return binarysearch(i,s,m);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    manipulated_seive(MAX_SIZE-1);
    ll M=0,cnt=0,flag=0,a=-1,b=-1;
    repA(i,-1000,1000)repA(j,0,1000)
    {
      if(j<0||isprime[j]==0) continue;

      repA(n,0,j-1)
      {
        if(n*n+i*n+j>sz(isprime)){cout<<"large\n";break;}
        else if(n*n+i*n+j<=0)break;
        else if(isprime[n*n+i*n+j]==1)cnt++;
        else{flag=1; break;}
      }

      if(flag==1)if(cnt>M){M=cnt,a=i,b=j;}
      cnt=0,flag=0;

    }
    cout<<M<<','<<a<<','<<b<<end;


    return 0;
}
