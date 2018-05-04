// #include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vii;

int main()
{
    ifstream cin("in.txt");
    ofstream cout("out.txt");

    int k,  n, w;
    cin >> k >> n >> w;


    ll ans = n - ((w * (w+1) ) / 2)* k;

    if(ans)
    {
        cout << ans;
    }
    else
    {
        cout << 0;
    }

    cout.close();
    cin.close();
    
    return 0;
}