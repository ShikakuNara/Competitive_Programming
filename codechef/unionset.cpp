#include "/usr/local/include/bits/stdc++.h"
// #include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;
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
        int n, k;
        cin >> n >> k;

        vll len;
        vvl a; 

        for (int i = 0; i < n; ++i)
        {
            ll tmp;
            cin >> tmp;

            len.push_back(tmp);

            vll temp;
            for (int i = 0; i < tmp; ++i)
            {
                int lol;
                cin >> lol;
                temp.push_back(lol);
            }
            a.push_back(temp);
        }  

        ll count = 0;

        for (int i = 0; i < n-1; ++i)
        {
            for (int j = i+1; j < n; ++j)
            {
                if(len[i] + len[j] >= k)
                {
                    vll num(k, 0);

                    for(int l = 0; l < len[i]; l++)
                        num[ a[i][l]-1 ] = 1;

                    for(int l = 0; l < len[j]; l++)
                        num[ a[j][l]-1 ] = 1;
 
                    int sum = 0;
                    for(int l = 0; l < k; l++)
                        sum += num[l];
                    if (sum == k)
                        count++;
                }
            }
        }



        // cout << "\n";
        cout << count << "\n";
    }

    cout.close();
    cin.close();
    
    return 0;
}