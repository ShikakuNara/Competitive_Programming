#include "/usr/local/include/bits/stdc++.h"
// #include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef stack <int>  si;
typedef stack <ll> sll;
typedef stack < pair<int, int> > sii;
typedef queue < pair<int, int> > qii;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define p(a, b) ( make_pair(a, b) )

const int M = 100000;

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}


int main()
{
    ifstream cin("in.txt");
    ofstream cout("out.txt");
    cout << "ddd";
    ll n, m ,k;
    cin >> n >> m >> k;

    ll min = 0, max = m;
    ll p = 0;
    ll ans;
    ll pill = 0;

    //
    // while( min < max)
    // {
    //   p = (max + min + 1)/2;
    //   pill = 0;
    //   cout << "3\n";
    //   pill += p*(p+1)-p;
    //   if(p > k)
    //   {
    //     pill -= (p-k)*(p-k+1)/2;
    //   }
    //   else
    //   {
    //     pill += p-k;
    //   }
    //   if(p > n-k)
    //   {
    //     pill -= (p-n+k-1)*(p-n+k)/2;
    //   }
    //   else
    //   {
    //     pill += n-k+1-p;
    //   }
    //
    //   if( pill > m)
    //   {
    //     max = p;
    //   }
    //   else if(pill < m)
    //   {
    //     min = p;
    //   }
    //   else
    //   {
    //     cout << p << "\n";
    //     break;
    //   }
    // }

    cout.close();
    cin.close();

    return 0;
}
