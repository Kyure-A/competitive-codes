/* include */
#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all> using namespace atcoder;

/* Macro */
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define per3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))

/* Type */
// #define int long long
#define cauto const auto&
typedef long long i64;
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;

// korega "DFS" rasii desu

signed main ()
{
  string s;
  cin >> s;
  set<string> x;
  stack<string> y;
  int n = s.length();
  string answer = "Yes";
  
  for (int i = 0; i < n; ++i)
    {
      if (s.substr(i, 1) == "(") y.push("");
      
      else if (s.substr(i, 1) == ")")
	{
	  x.erase(y.top());
	  y.pop();
	}
      
      else
	{
	  if (x.count(s.substr(i, 1)) == 1)
	    {
	      answer = "No";
	      break;
	    }
	  
	  else
	    {
	      x.insert(s.substr(i, 1));
	      y.push(s.substr(i, 1));
	    }
	}
    }

  cout << answer << endl;

  return 0;
}
