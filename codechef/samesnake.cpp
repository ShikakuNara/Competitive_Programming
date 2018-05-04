#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vii;



int main()
{
    ll t;
    cin >> t;
    
    for(; t > 0; t--)
    {
        ll xa1, ya1, xa2, ya2, xb1, yb1, xb2, yb2;

        cin >> xa1 >> ya1 >> xa2 >> ya2 >> xb1 >> yb1 >> xb2 >> yb2;

        int okay = 0;

        char da, db;

        if(xa1 == xa2 && ya1 == ya2)
            da = 's';
        else if(xa1 == xa2)
            da = 'y';
        else if(ya1 == ya2)
            da = 'x';

        if(xb1 == xb2 && yb1 == yb2)
            db = 's';
        else if(xb1 == xb2)
            db = 'y';
        else if(yb1 == yb2)
            db = 'x';

        if(da == db && da == 's')
        {
            if(xa1 == xb1 && ya1 == yb1)
                okay = 1;
        }
        else if(da == 's')
        {
            if(xa1 == xb1)
            {
                if(ya1 <= yb1 && ya1 >= yb2)
                    okay = 1;
                else if (ya1 >= yb1 && ya1 <= yb2)
                    okay = 1;
            }
            else if( ya1 == yb1)
            {
                if(xa1 <= xb1 && xa1 >= xb2)
                    okay = 1;
                else if (xa1 >= xb1 && xa1 <= xb2)
                    okay = 1;
            }
        }
        else if(db == 's')
        {
            if(xb1 == xa1)
            {
                if(yb1 <= ya1 && yb1 >= ya2)
                    okay = 1;
                else if (yb1 >= ya1 && yb1 <= ya2)
                    okay = 1;
            }
            else if( yb1 == ya1)
            {
                if(xb1 <= xa1 && xb1 >= xa2)
                    okay = 1;
                else if (xb1 >= xa1 && xb1 <= xa2)
                    okay = 1;
            }
        }
        else if(db == da && da == 'x')
        {
            if(ya1 == yb1)
            {
                if(xa1 <= xb1 && xa1 >= xb2)
                    okay = 1;
                else if (xa1 >= xb1 && xa1 <= xb2)
                    okay = 1;
                else if(xa2 <= xb1 && xa2 >= xb2)
                    okay = 1;
                else if (xa2 >= xb1 && xa2 <= xb2)
                    okay = 1;
            }
        }
        else if (db == da && da == 'y')
        {
            if(xa1 == xb1)
            {
                if(ya1 <= yb1 && ya1 >= yb2)
                    okay = 1;
                else if (ya1 >= yb1 && ya1 <= yb2)
                    okay = 1;
                else if(ya2 <= yb1 && ya2 >= yb2)
                    okay = 1;
                else if (ya2 >= yb1 && ya2 <= yb2)
                    okay = 1;
            }
        }
        else if( da !=  db)
        {
            if(xa1 == xb1 && ya1 == yb1)
                okay = 1;
            else if(xa1 == xb2 && ya1 == yb2)
                okay = 1;
            else if(xa2 == xb1 && ya2 == yb1)
                okay = 1;
            else if(xa2 == xb2 && ya2 == yb2)
                okay = 1;
        }


        if(okay == 1)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    
    return 0;
}


// 12
// 0 1 0 0 -1 2 -2 2
// -1 0 1 0 0 -1 0 1
// 0 -1 0 0 1 0 0 0
// -1 0 0 0 0 -1 0 0
// 0 0 0 1 0 0 1 0 
// -1 0 0 0 0 0 0 1 
// 0 0 0 3 3 2 3 5
// -2 3 2 3 0 0 5 0
// 0 -1 0 1 0 0 0 2
// -1 0 1 0 0 0 2 0 
// 0 -1 0 0 0 1 0 2
// -1 0 0 0 2 0 1 0