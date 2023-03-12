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


signed main ()
{
  string s;
  cin >> s;

  int n = s.length();

  map<string, int> ball;
  vector<int> count_leftparen(n, 0), count_rightparen(n, 0);
  
  string answer = "Yes";
  
  for (int i = 0; i < n; ++i)
    {
      if (s.substr(i, 1) != "(" or s.substr(i, 1) != ")")
	{
	  ball[s[i]]++;
	  s[i]
	    if (ball[s[i]] > 1)
	    {
	      answer = "No";
	      break;
	    }
	}
      
      else if (s.substr(i, 1) == ")")
	{
	  int current_i = i;
	  per(k, current_i)
	    {
	      if (s.substr(i, 1) == "(")
		{
		  rep(j, k) if (s.substr(i, 1) != "(" or s.substr(i, 1) != ")") s[j] = ""
										  }
	    }
	  
	  // per de gyakujyun ni tannsaku site s[i] wo kakutei site ball wo toridasu
	}
    }
  
  return 0;
}
