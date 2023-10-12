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

  vector<vector<int>> a_copy2(n, vector<int>(n));
  
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  a_copy2[i][j] = a_copy1[n - 1 - j][i];
	}
    }

  vector<vector<int>> a_copy3(n, vector<int>(n));
  
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  a_copy3[i][j] = a_copy2[n - 1 - j][i];
	}
    }

  vector<vector<int>> a_copy4(n, vector<int>(n));
  
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  a_copy4[i][j] = a_copy3[n - 1 - j][i];
	}
    }
  
  ////

  bool flag[5] = {true};
  
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  if (!(b[i][j] == 1 and a[i][j] == 1)) flag[0] = false;
	}
    }

  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  if (!(b[i][j] == 1 and a_copy1[i][j] == 1)) flag[1] = false;
	}
    }

  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  if (!(b[i][j] == 1 and a_copy2[i][j] == 1)) flag[2] = false;
	}
    }

  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  if (!(b[i][j] == 1 and a_copy3[i][j] == 1)) flag[3] = false;
	}
    }

  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  if (!(b[i][j] == 1 and a_copy4[i][j] == 1)) flag[4] = false;
	}
    }

  if (flag[0] or flag[1] or flag[2] or flag[3] or flag[4]) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
