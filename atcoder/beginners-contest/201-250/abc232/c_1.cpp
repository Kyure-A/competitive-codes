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
  
  vector<int> a(m), b(m);
  for (int i = 0; i < m; ++i)
    {
      cin >> a[i] >> b[i];
      a[i]--; b[i]--;
    }
  
  vector<vector<int>> aoki(n);
  
  for (int i = 0; i < m; ++i)
    {
      int c, d; cin >> c >> d;
      c--; d--;
      aoki[c].emplace_back(d);
      aoki[d].emplace_back(c);
    }
  
  vector<int> p;
  rep(i, n) p.emplace_back(i + 1);
  do
    {
      vector<vector<int>> takahashi(n);
      for (int i = 0; i < m; ++i)
	{
	  int A = p[a[i]];
	  int B = p[b[i]];
	  A--; B--;
	  takahashi[A].emplace_back(B);
	  takahashi[B].emplace_back(A);
	}

      for (int i = 0; i < n; ++i)
	{
	  sort(all(takahashi[i]));
	  sort(all(aoki[i]));
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
