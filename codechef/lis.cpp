#include "/usr/local/include/bits/stdc++.h"
// #include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vii;
 
#define MAXN   1000001
 
// stores smallest prime factor for every number
int spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    
    // marking smallest prime factor for every
    // number to be itself.
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)// marking spf[j] if it is not
                    spf[j] = i;// previously marked
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int main()
{
    // precalculating Smallest Prime Factor
    sieve();
    ifstream cin("in.txt");
    ofstream cout("out.txt");

    for (int i = 0; i < MAXN; ++i)
    {
        cout << spf[i] << ", ";
    }


    cout.close();
    cin.close();


    // ll t;
    // cin >> t;
    
    // for(; t > 0; t--)
    // {
    //     ll k;
    //     cin >> k;

    //     // calling getFactorization function
    //     vii p = getFactorization(k);


    //     ll n = 0;
    //     for(int i = 0; i < p.size(); i++)
    //         n += p[i];
    //     cout << n << '\n';

    //     ll j = 0;
    //     for(int i = 0; i < p.size(); i++)
    //     {
    //         for(int k = 0; k < p[i]; k++)
    //             cout << j + p[i] - k << ' ';

    //         j = j + p[i];
    //     }

    //     cout << "\n";
    // }
    
    return 0;
}
