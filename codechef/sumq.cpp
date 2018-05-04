// #include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long int ll;
typedef vector <ll> vll;
typedef vector <int> vii;
 
const ll M  = 1000000007;
 
ll func(ll y, ll xsum, ll zsum, ll vx, ll vz)
{
//     ll ans1 = (y * (((xsum * vz) %M + (zsum * vx) %M) %M) )%M ;
//     ll ans2 = (vx * (vz * (y * y) %M) %M) %M ;
//     ll ans3 = (xsum * zsum) %M;
//     return ans1 + ans2 + ans3;
 
    return (y * (   (   ((xsum * vz) %M )+ ((zsum * vx)%M)  )%M          )   )%M
                        + (vx * ((vz * ((y * y) %M)        ) %M)      ) %M
                        + (xsum * zsum) %M       ;
}
 
int main()
{
    // ifstream cin("in.txt");
    // ofstream cout("out.txt");
 
    int t;
    cin >> t;
 
    for (int i = 0; i < t; ++i)
    {
        ll p, q, r;
        cin >> p >> q >> r;
 
        vll a , b, c;
 
        for (int i = 0; i < p; ++i){
            ll tmp;
            cin >> tmp;
            a.push_back(tmp);
        } sort(a.begin(), a.end());
        for (int i = 0; i < q; ++i){
            ll tmp;
            cin >> tmp;
            b.push_back(tmp);
        } sort(b.begin(), b.end());
        for (int i = 0; i < r; ++i){
            ll tmp;
            cin >> tmp;
            c.push_back(tmp);
        } sort(c.begin(), c.end());
 
        ll sum = 0;
        ll xsum = 0, zsum = 0, vx = 0, vz = 0;
 
        for (int i = 0; i < q; ++i)
        {
            for (int j = vx; a[j] <= b[i] && j < p; ++j){
                vx++;
                xsum = ( xsum + a[j]) % M;
            }
            for (int j = vz; c[j] <= b[i] && j < r; ++j){
                vz++;
                zsum = ( zsum + c[j]) % M;
            }
 
            sum = ( sum + func(b[i], xsum, zsum, vx, vz)   ) % M;
        }
 
        cout << sum << "\n";
    }
 
    // cout.close();
    // cin.close();
    
    return 0;
} 