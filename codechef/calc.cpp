// #include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>

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
#define rall(c) (c).rbegin(),(c).rend() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define p(a, b) ( make_pair(a, b) )


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
    // ifstream cin("in.txt"); 
    // ofstream cout("out.txt");

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        ll n, b;
        cin >> n >> b;

        if( b > n)
            cout << 0 << '\n';
        else
        {
            ll y = n % b, x, z= 0;

            ll frac = n % b;
            
            if( ( (n/2) - frac ) % b == 0) // perfect case
            {
                x = n / 2;
                y = x - b;
                z = x + b;
            }
            else if( 2 * frac < n) // 0 and 1 
            {
                ll k = (n / 2 - frac) / b;
                k++;
                x = k*b + frac;
                y = x-b;
                z = x+b;
            }
            else //-1 and 0
            {
                ll k = (n / 2 - frac) / b;
                x = k*b + frac;
                y = x-b;
                z = x+b;
            }

            ll ans1 = (n - y) / b;
            ans1 *= y;
            ll ans2 = (n - x) / b;
            ans2 *= x;
            ll ans3 = (n - z) / b;
            ans3 *= z;

            ll ans = ans1 > ans2 ? ans1 : ans2;
            ans = ans > ans3 ? ans : ans3;

            cout << ans << "\n";
        }
    }


    // cout.close();
    // cin.close();
    
    return 0;
}