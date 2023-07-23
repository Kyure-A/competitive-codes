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

  unsigned long long n; cin >> n;
  bitset<60> st(n);
  vector<int> flag;
  
  for (int i = 0; i <= 60; ++i)
    {
      if (st[i]) flag.emplace_back(i);
    }

  set<unsigned long long> ans;
  ans.emplace(0);

  for (int bit = 0; bit < (1 << flag.size()); ++bit) // 2^n 回探索
    {
      bitset<60> tmp(0);
      for (int i = 0; i < flag.size(); ++i)
	{
	  if (bit & (1 << i)) // bit が立っている場合の処理
	    {
	      tmp.set(flag[i]);
	      ans.emplace(tmp.to_ullong());
	    }
	}
    }

  for (auto x : ans) cout << x << endl;
  
  return 0;
}
