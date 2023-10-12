#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/modint>
// using namespace atcoder;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
// #define int long long
const double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int m; cin >> m;
  vector<int> d(m);
  vector<pair<int, int>> bucket(20000, {0, 0});
  int now = 1;
  for (int i = 0; i < m; ++i)
    {
      cin >> d[i];
      for (int j = 1; j < 1 + d[i]; ++j)
	{
	  bucket[now] = {i + 1, j};
	  now++;
	}
    }
  
  int mid = (accumulate(d.begin(), d.end(), 0) + 1) / 2;

  cout << bucket[mid].first << " " << bucket[mid].second << endl;

  return 0;
}
