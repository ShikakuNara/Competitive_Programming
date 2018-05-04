// #include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef stack <int>  si;
typedef stack <ll> sll;
typedef stack < pair<int, int> > sii;
typedef queue < pair<int, int> > qii;

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define p(a, b) ( make_pair(a, b) )

int main()
{
    // ifstream cin("in.txt");
    // ofstream cout("out.txt");

    ll n, m;
    cin >> n >> m;

    if(n > m)
        cout << n-m;
    else
    {
        vi visited(30000, 0);

        qii s;
        s.push( p(n, 0));

        while(!s.empty())
        {
            int top = s.front().first;
            int step = s.front().second;

            s.pop();

            if(top <= 0 || top > 20000 || visited[top] == 1)
            {
                continue;
            }

            visited[top] = 1;
            
            if(top == m )
            {
                cout << step;
                break;
            }
            
            s.push( p(2 * top, step+1));
            s.push( p(top-1, step+1));



        }
    }

    // cout.close();
    // cin.close();
    
    return 0;
}