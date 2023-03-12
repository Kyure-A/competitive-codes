/* ------------------------------ include ------------------------------ */
#include <bits/stdc++.h>
// #include <atcoder/all>
// #include <boost/multiprecision/cpp_int.hpp>
/* ------------------------------  using  ------------------------------ */
using namespace std;
// using namespace atcoder;
// using namespace boost::multiprecision;
/* ------------------------------  define ------------------------------ */
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define per3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
// #define int long long
/* ------------------------------  const  ------------------------------ */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;
/* ------------------------------  code   ------------------------------ */

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  
  vector<int> c(m);
  vector<vector<int>> s(m);
  
  // input
  for (int i = 0; i < m; ++i)
    {
      cin >> c[i];
      for (int j = 0; j < c[i]; ++j)
	{
	  int a; cin >> a;
	  s[i].emplace_back(a);
	}
    }


  int answer = 0;
  
  // solve
  for (int bit = 0; bit < (1 << m); ++bit)
    {
      vector<int> hoge(10 + 1, 0);
      for (int i = 0; i < m; ++i)
	{
	  if (bit & (1 << i))
	    {
	      for (auto a : s[i])
		{
		  hoge[a]++;
		}
	    }
	}
      
      bool flag = true;
      for (int x = 1; x <= n; ++x)
	{
	  if (hoge[x] < 1) flag = false;
	}
      if (flag) answer++;
    }
  
  cout << answer << "\n";
  
  return 0;
}
