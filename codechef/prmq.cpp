#include "/usr/local/include/bits/stdc++.h"
// #include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef std::vector <ll> vll;
typedef std::vector <int> vii;
typedef std::vector<vll> vvl;

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,  197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

int main()
{
    ifstream cin("in.txt");
    ofstream cout("out.txt");
    
    ll n;
    cin >> n;

    vll a ;
    for (int i = 0; i < n; ++i)
    {
    	ll tmp;
    	cin >> tmp;
    	a.push_back(tmp);
    }

    ll q;
    cin >> q;

    for (int i = 0; i < q; ++i)
    {
    	ll l, r, x, y;
    	cin >> l >> r >> x >> y;
    	l--; 

    	if( x > 997) //no primes > 1000 divide numbers below 1,000,000
    	{
    		cout << 0 << "\n";
    		return 0;
    	}

    	if( y > 997) //reason stated above
    		y = 997;

    	ll k = 0, result = 0;

    	while(prime[k] < x)
    		k++;

    	while(prime[k] <= y)
    	{
    		//check for exponenets in all numbers
    		for(int j = l; j <= r; j++)
    		{
    			ll num = a[j];

    			while(num % prime[k] == 0 && num > 0)
    			{
    				num = num / prime[k];
    				result++;
    			}
    		}
    		//move to the next prime
    		k++;
    	}

    	cout << result << "\n";
    }

    cout.close();
    cin.close();
    
    return 0;
}