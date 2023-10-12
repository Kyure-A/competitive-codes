#include <bits/stdc++.h>
using namespace std;
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
// #define int long long
const double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
using int64 = long long;

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  string s; cin >> s;

  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  for (int k = 0; k < n; ++k)
	    {
	      if (i < j && j < k && j - i == 1 && k - j == 1 && s[i] == 'A' && s[j] == 'B' && s[k] == 'C')
		{
		  cout << i + 1 << endl;
		  return 0;
		}
	    }
	}
    }

  cout << -1 << endl;

  return 0;
}
