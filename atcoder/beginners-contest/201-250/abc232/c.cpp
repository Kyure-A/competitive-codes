#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

constexpr double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - '0'
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
/* ------------------------------ code  ------------------------------ */

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;
  
  vector<vector<int>> takahashi(n);
  
  for (int i = 0; i < m; ++i)
    {
      int a, b; cin >> a >> b;
      a--; b--;
      takahashi[a].emplace_back(b);
      takahashi[b].emplace_back(a);
    }
  
  vector<int> c(m), d(m); rep(i, m) cin >> c[i] >> d[i];
  rep(i, m) {c[i]--; d[i]--;}
  
  vector<int> p;
  rep(i, n) p.emplace_back(i + 1);
  do
    {
      vector<vector<int>> aoki(n);
      
      for (int i = 0; i < m; ++i)
	{
	  int C = p[c[i]];
	  int D = p[d[i]];
	  C--; D--;
	  aoki[C].emplace_back(D);
	  aoki[D].emplace_back(C);
	}

      if (takahashi == aoki)
	{
	  cout << "Yes" << "\n";
	  return 0;
	}
    }
  while (next_permutation(p.begin(), p.end()));

  cout << "No" << "\n"; 

  return 0;
}
