#include "/usr/local/include/bits/stdc++.h"
// #include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vii;

int main()
{
    ifstream cin("in.txt");
    ofstream cout("out.txt");

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        ll x, y; 
        cin >> x >> y;

        ll ans = (x+y) * (x+y+1) / 2 + x + 1;

        cout << ans << "\n";
    }

    cout.close();
    cin.close();
    
    return 0;
}