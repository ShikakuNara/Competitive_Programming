#include "/usr/local/include/bits/stdc++.h"
// #include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef std::vector <ll> vll;
typedef std::vector <int> vii;
typedef std::vector<vll> vvl;

int main()
{
    ifstream cin("in.txt");
    ofstream cout("out.txt");

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n, q;
        cin >> n >> q;

        vll x;
        for (int i = 0; i < n; ++i)
        {
            ll tmp;
            cin >> tmp;
            x.push_back(tmp);
        }

        for (int i = 0; i < q; ++i)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            a--; b--; c--; d--;

            if(a == c && b == d)//complete overlap
            {
                cout<< "YES\n";
            }
            else if( a == c - 1)//one element not overlapping 
            {
                ll pre = x[a];
                ll post = x[d];

                if(pre == post)
                    cout << "YES\n";
                else
                {
                    ll min = x[a+1], max = x[a+1];

                    for (int i = a+2; i < b+1; ++i)
                    {
                        if(x[i] > max)
                            max = x[i];
                        if(x[i] < min)
                            min = x[i];
                    }


                    if(pre == min || post == max)
                        cout << "YES\n";
                    else
                        cout << "NO\n";
                }
            }
            else if (a == c + 1)//one element not overlapping 
            {
                ll pre = x[d];
                ll post = x[a];

                if(pre == post)
                    cout << "YES\n";
                else
                {
                    ll min = x[c+1], max = x[c+1];

                    for (int i = c+2; i < d+1; ++i)
                    {
                        if(x[i] > max)
                            max = x[i];
                        if(x[i] < min)
                            min = x[i];
                    }


                    if(pre == min || post == max)
                        cout << "YES\n";
                    else
                        cout << "NO\n";
                }
            }
            else if((b < d && b > c) || (a > c && a < d)) //partial over lap
            {

            }
            else //no overlap
            {
                vll y, z;
                for (int i = a; i < b+1; ++i)
                    y.push_back(x[i]); 
                for (int i = c; i < d+1; ++i)
                    z.push_back(x[i]); 

                sort(y.begin(), y.end());
                sort(z.begin(), z.end());

                int shieldUp = 1, wallUp = 1;
                for(int i = 0; i < b - a + 1; i++)
                {
                    if(y[i] != z[i])
                    {
                        if(shieldUp)
                            shieldUp = 0;
                        else
                            wallUp = 0;
                    }
                }

                if(wallUp)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
            
        }
    }

    cout.close();
    cin.close();
    
    return 0;
}