#include "/usr/local/include/bits/stdc++.h"
// #include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vii;
 
#define MAXN   1000001
 
int main()
{
    ifstream cin("in.txt");
    ofstream cout("out.txt");

    int max, n;
    cin >> n;
    cout << n << ", ";
    while (n != -1)
    {
    	cin >> n;
        if( n > max)
        {
        	max = n;
        	cout << n << ", ";
        }
    }


    cout.close();
    cin.close();    
    return 0;
}
