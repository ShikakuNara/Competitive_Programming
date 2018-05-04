// #include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef stack <int>  si;
typedef stack <ll> sll;


int main()
{
    // ifstream cin("in.txt");
    // ofstream cout("out.txt");

    int n, t;
    cin >> n >> t;
    t--;

    vi a;
    for (int i = 0; i < n-1; ++i)
    {
        int tmp;   
        cin >> tmp;
        a.push_back(tmp);
    }

    vi visited(n, 0);

    si s;
    s.push(0);

    while(!s.empty())
    {
        int top = s.top();
        s.pop();

        if(visited[top] == 1)
            continue;
        else
            visited[top] = 1;
        
        if(top == t)
        {
            cout << "YES\n";
            break;
        }
        else if( top > t || top >= n-1)
        {
            cout << "NO\n";
            break;
        }

        s.push(top+a[top]);
    }

    // cout.close();
    // cin.close();
    
    return 0;
}