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

  int n, q; cin >> n >> q;
  vector<multiset<int>> box(n + 1);
  vector<set<int>> card(3 * 1e5);
  
  while (q--)
    {
      int query; cin >> query;

      if (query == 1)
	{
	  int i, j; cin >> i >> j;
	  box[j].emplace(i);
	  card[i].emplace(j);
	}

      else if (query == 2)
	{
	  int i; cin >> i;
	  for (auto x : box[i]) cout << x << " ";
	  cout << endl;
	}

      else if (query == 3)
	{
	  int i; cin >> i;
	  for (auto x : card[i]) cout << x << " ";
	  cout << endl;
	}
    }

  return 0;
}
