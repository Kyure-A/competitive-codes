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

bool comp_deliciousness(pair<int, int> e1, pair<int,int> e2) {return e1.second > e2.second;}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<pair<int, int>> icecream(n); rep(i, n) cin >> icecream[i].first >> icecream[i].second;
  sort(icecream.begin(), icecream.end(), comp_deliciousness);

  int s = icecream[0].second;
  int t = -1;
  
  for (int i = 1; i < n; ++i)
    {
      if (icecream[i].first == icecream[0].first)
	{
	  t = max(t, icecream[i].second / 2);
	}
      else t = max(t, icecream[i].second);
    }

  cout << s + t << endl;
  
  return 0;
}
