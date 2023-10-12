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

  int h, w; cin >> h >> w;
  vector<vector<int>> p(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> p[i][j];

  int answer = 0;
  
  for (int bit = 0; bit < (1 << h); ++bit) // 2^n 回探索
    {
      // 正しいグリッドかの判定
      bitset<8> bt(bit);
      vector<int> flag;
      for (int i = 0; i < 8; ++i)
	{
	  if (bt.test(i)) flag.emplace_back(i);
	}
      
      sort(flag.begin(), flag.end());
      
      for (int i = 0; i < flag.size() - 1; ++i)
	{
	  if (flag[i + 1] - flag[i] != 1) continue;
	}
      
      // bit 全探索
      vector<int> count(10, 0);
      for (int i = 0; i < h; ++i)
	{
	  if (bit & (1 << i)) // bit が立っている場合の処理
	    {
	      for (int j = 0; j < w; ++j)
		{
		  count[p[i][j]]++;
		}
	    }
	}

      for (int i = 1; i <= 9; ++i)
	{
	  answer = max(answer, count[i]);
	}
    }

  cout << answer << endl;

  return 0;
}
