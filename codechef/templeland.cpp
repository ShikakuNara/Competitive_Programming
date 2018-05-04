#include "/usr/local/include/bits/stdc++.h"

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vii;



int main()
{
    int t;
    cin >> t;
    
    for(; t > 0; t--)
    {
        int n;
        cin >> n;

        vii h;
        for(int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            h.push_back(tmp);
        }

        int wrong = 0;
        if(n % 2 == 1)
        {
            for(int i = 0; i < n/2 + 1; i++)
                if(h[i] != i+1)
                    wrong = 1;

            for(int i = n/2 + 1; i < n; i++)
                if(h[i] != n/2 + 1 - i)
                    wrong  = 1;

            if(!wrong)
                cout << "yes\n";
            else
                cout << "no\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    
    return 0;
}