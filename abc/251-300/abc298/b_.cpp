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

  int n; cin >> n;
  vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> a[i][j];
  rep(i, n) rep(j, n) cin >> b[i][j];

  string answer = "No";
  
  vector<vector<int>> a_copy1(n, vector<int>(n));
  
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  a_copy1[i][j] = a[n - 1 - j][i];
	}
    }

  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  cout << a_copy1[i][j] << " ";
	}
      cout << endl;
    }

  cout << endl;
  
  if (b == a_copy1) answer = "Yes";

  vector<vector<int>> a_copy2(n, vector<int>(n));
  
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  a_copy2[i][j] = a_copy1[n - 1 - j][i];
	}
    }

  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  cout << a_copy2[i][j] << " ";
	}
      cout << endl;
    }

  cout << endl;
  
  if (b == a_copy2) answer = "Yes";

  vector<vector<int>> a_copy3(n, vector<int>(n));
  
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  a_copy3[i][j] = a_copy2[n - 1 - j][i];
	}
    }

  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  cout << a_copy3[i][j] << " ";
	}
      cout << endl;
    }

  cout << endl;

  if (b == a_copy3) answer = "Yes";

  cout << answer << endl;
  
  return 0;
}
