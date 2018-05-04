#include "/usr/local/include/bits/stdc++.h"
// #include <bits/stdc++.h>

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
#define rall(c) (c).rbegin(),(c).rend() 
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
    ifstream cin("in.txt"); 
    ofstream cout("out.txt");

    int n;
    cin >> n;

    vi a;

    for (int i = 0; i < n; ++i)
    {
        int tmp; cin >> tmp;
        a.pb(tmp);
    }

    sort(all(a));

    int possible = 1;

    int k = 1;
    while(possible && k <= n)
    {
        k++;

        int flag = 0;
        int num = n / k;
        
        if(n  % k != 0)
        {
            num++;
            flag = 1;
        }

        //checkifpossible
        for (int i = 1; possible == 1 && i <= k; ++i)
        {
            if(flag == 0)
            {
                if( a[n - num*i] < k - i)
                    possible = 0; //update possible
            }
            else
            {
                if( a[n - num*i + 1] < k - i)
                    possible = 0; //update possible
                if( a[n - num*i] < k - i - 1)
                    possible = 0; //update possible
            }
        }
    }

    k--;
    int num = n / k;
        if(n  % k != 0)
            num++;

    cout << k << " "<< num;

    cout.close();
    cin.close();
    
    return 0;
}