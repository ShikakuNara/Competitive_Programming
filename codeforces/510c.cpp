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

const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e6 + 3;
const ll factRange = 1000000;

#define _  %  MOD
#define __ %= MOD
#define end '\n'

// Functions
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

int n, mar[26], vis[26];
vll e[26]; si tlist;

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
    cout << "Impossible\n";
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
  for (size_t i = 0; i < 26; i++) {
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

    cin >> n;

    string s; cin >> s;

    char u,v;
    for (size_t i = 0; i < n - 1; i++) {
      string a; cin >> a;

      int tmp = strcc(s, a, u, v);
      if( tmp == -1)
      {
        cout << "Impossible\n";
        return 0;
      }

      if( tmp == 1)
      {
        mar[u - 'a'] = 1; mar[v - 'a'] = 1;
        e[u-'a'].pb((int)(v-'a'));
        s = a;
      }
    }


    // int ll;
    // for (size_t i = 0; i < 26; i++) {
    //   if(mar[i] == 1)
    //   {
    //     ll = i; break;
    //   }
    // }
    //
    // for (size_t i = 0; i < 26; i++) {
    //   if(mar[i] == 0)
    //   {
    //     mar[i] = 1; e[ll].pb(i);
    //   }
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
      cout << (char)(tlist.top() + 'a');
      tlist.pop();
    }

    // cout.close(); cin.close();
    return 0;
}
