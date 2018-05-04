#include "/usr/local/include/bits/stdc++.h"
// #include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef std::vector <ll> vll;
typedef std::vector <int> vii;
typedef std::vector<vll> vvl;

bool wayToSort(int i, int j) { return i > j; }

int main()
{
    ifstream cin("in.txt");
    ofstream cout("out.txt");

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;

        vll a;
        for (int i = 0; i < n; ++i)
        {
        	ll tmp;
        	cin >> tmp;
        	a.push_back(tmp);
        }

        int foundPos = 0;
        for (int i = 0; i < n; ++i)
        	if(a[i] > 0)
        		foundPos++;

       	if(!foundPos)
       	{
	        ll sum = 0;
	        for (int i = 0; i < n; ++i)
	        {
	        	sum += a[i];
	        }

	        cout << sum << "\n";
	    }
	    else
	    {
	    	// vll pos;
            vll neg;
            ll x = 0, y = 0; ll sum = 0, negsum = 0;

            for (ll i = 0; i < n; ++i)
            {
                if(a[i] >= 0)
                {
                    //pos.push_back(a[i]);
                    x++;
                    sum += a[i];
                }
                else
                {
                    neg.push_back(a[i]);
                    negsum += a[i];
                    y++;
                }
            }


            ll ans, max = sum * x + negsum;

            if(y > 0)
            {
                sort(neg.begin(), neg.end(), wayToSort);

                ll i = 0;
                while(sum >= 0 && i < y)
                {

                    sum += neg[i];
                    negsum -= neg[i];

                    x++;
                    i++;

                    if(sum * x + negsum > max)
                    {
                        max = sum * x + negsum;
                    }
                }

                ans = max;

            }
            else
            {
                ans = sum * x;
            }

            cout << ans << "\n";
	    }
    }

    cout.close();
    cin.close();
    
    return 0;
}