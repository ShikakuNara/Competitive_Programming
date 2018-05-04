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


// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}


int main()
{
    // ifstream cin("in.txt");
    // ofstream cout("out.txt");

    int n;
    cin >> n;

    vi a;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        a.pb(tmp-1);
    }


    vi check(n, 0);

    for (int i = 0; i < n; ++i)
        check[ a[i] ]++;


    int possible = 1;
    for (int i = 0; i < n; ++i)
        if(check[i] != 1)
        {
            possible = 0;
            break;
        }

    if(!possible)
    {
        cout << -1;
    }
    else
    {
        vi visited(n, 0);
        int M = 1;

        for (int i = 0; i < n; ++i)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
                int j = a[i];
                int size = 1;
                while(j != i && visited[j] == 0)
                {
                    visited[j] = 1;
                    size++;
                    j = a[j];

                }

                if(j == i)
                { 
                    if(size % 2 == 0)
                        size /= 2;

                    M = lcm(M, size);
                }
            }
        }
        cout << M;
    }


    // cout.close();
    // cin.close();
    
    return 0;
}