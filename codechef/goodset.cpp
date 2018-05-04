#include "/usr/local/include/bits/stdc++.h"
// #include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vii;

int main()
{
    // ifstream in("in.txt");
    // ofstream out("out.txt");

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n; 
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            cout << 400 + i;
            if(i == n - 1)
                cout << "\n";
            else
                cout << " ";
        }

        cout << "\n";
    }

    // out.close();
    // in.close();
    
    return 0;
}