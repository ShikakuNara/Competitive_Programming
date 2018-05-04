// #include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;
typedef vector <int> vi;
typedef stack <int>  si;
typedef stack <ll> sll;
typedef stack < pair<int, int> > sii;
typedef queue < pair<int, int> > qii;

#define sz(a) ll((a).size())
#define pb push_back
#define all(c)        (c).begin(),(c).end()
#define tr(c,i)       for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)  ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mp(a, b)       (make_pair(a, b) )
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend())
#define fill(a)       (memset(a, 0, sizeof (a)))
#define end '\n'

int n, mar[26], vis[36], ind[36]; char ch[36];
vll e[36]; si tlist; int ccc, c;

int strcc ( string s, string a, char& u, char& v){
    if(s.compare(a) == 0)
    {
      return 0; //same strings
    }


    int flag = 0;
    for (size_t j = 0; j < s.length() && j < a.length() && flag == 0; j++)
    {
      if(s[j] != a[j])
      {
        cout << s << ", " << a << end;
        u = s[j];
        v = a[j];
        flag = 1;
      }
    }

    if(flag == 0)
    {
      if(a.length() < s.length())
        return -1;//not possible
      else if(a.length() > s.length())
        return 0;// nothing to change
      else
        cout << "Tiny Rick!!\n";
    }
    return 1;
}
int topologicalsort(ll i){
  if(vis[i] == 1)
  {
    cout << "Impossibletopo\n";
    return -1;
  }
  if(vis[i] == 2)
  {
    return 0;
  }

  vis[i] = 1;

  for (size_t j = 0; j < e[i].size(); j++) {
    if(topologicalsort(e[i][j]) == -1)
    {
      return -1;
    }
  }

  tlist.push(i);
  vis[i] = 2;

  return 0;
}
int allvisited(){
  for (size_t i = 0; i <= c; i++) {
    if(vis[i] == 0)
    {
      return i;
    }
  }

  return -1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // ifstream cin("in.txt"); ofstream cout("out.txt");

    fill(mar);
    fill(vis);
    for (size_t i = 0; i < 36; i++) {
      ind [i] = -1;
      /* code */
    }

    string s; cin >> s;  c = -1;

    char u,v; ccc  = 1;
    while(s.compare("#") != 0){

      string a; cin >> a;
      if(a.compare("#") == 0)
        break;
      ccc++;

      // cout << "loop for " << s << ", " << a << end;


      int tmp = strcc(s, a, u, v);

      if( tmp == -1)
      {
        cout << "Impossiblestrcc\n";
        return 0;
      }

      if(tmp == 1)
      {
        if( ind[u - 'A'] == -1)
        {
          ch[++c] = u;
          ind[u- 'A'] = c;
        }
        if( ind[v - 'A'] == -1)
        {
          ch[++c] = v;
          ind[v - 'A'] = c;
        }

        // cout << s << ", " << a << ", u :"<< u << ", v: "<< v << end ;
        e[ind[u - 'A'] ].pb(ind[ v - 'A']);
        // cout << ind[u - 'A'] << end;
      }
        s = a;
    }

    // cout << "c :" << c << end;
    // for (size_t i = 0; i <= c; i++) {
    //   cout << ch[i] << ": " << e[i].size();
    //   for (size_t j  = 0; j < e[i].size(); j++) {
    //     cout << ch[e[i][j]] << ", ";
    //     /* code */
    //   }
    //   cout << end;
    //   /* code */
    // }

    while(allvisited() != -1)
    {
      int tmp = allvisited();
      if(topologicalsort(tmp) == -1)
      {
        return 0;
      }
    }

    while(tlist.empty() == 0)
    {
      cout << ch[tlist.top()];
      tlist.pop();
    }

    // cout.close(); cin.close();
    return 0;
}
