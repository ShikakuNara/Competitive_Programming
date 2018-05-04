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

    // int n;
    // cin >> n;
    //
    // for (int i = 0; i < n; ++i)
    // {
    //     char c, prev;
    //     string s;
    //     int count = 0, max = 0;
    //
    //     cin >> s;
    //
    //     int j;
    //     for (j = 0; s[j] == '='; ++j);
    //
    //     if( s[j] == '<' || s[j] =='>')
    //     {
    //         count++;
    //
    //         prev = s[j];
    //     } j++;
    //
    //     for (; s[j] != '\0'; ++j)
    //     {
    //         if(s[j] == prev)
    //         {
    //             count++;
    //         }
    //         else if ( s[j] != '=')
    //         {
    //             prev = s[j];
    //
    //             if(count > max)
    //                 max = count;
    //             count = 1;
    //         }
    //     }
    //
    //     if(count > max)
    //         max = count;
    //
    //     cout << max + 1 << '\n';
    // }

    cout << "hello87\n";

    cout.close();
    cin.close();

    return 0;
}
