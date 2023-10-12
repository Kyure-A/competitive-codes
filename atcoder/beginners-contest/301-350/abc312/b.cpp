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
  
  int h, w; cin >> h >> w;
  vector<string> s(h); rep(i, h) cin >> s[i];

  bool cond = false;
  
  for (int i = 0; i < h; ++i)
    {
      if (cond) break;
      
      char TakCode[15][15] = {'x'};
      
      for (int j = 0; j < w; ++j)
	{
	  if (i + 8 >= h or j + 8 >= w)
	    {
	      continue;
	    }
	  
	  for (int k = 0; k <= 8; ++k)
	    {
	      for (int l = 0; l <= 8; ++l)
		{
		  if (i + k >= h or j + l >= w) continue;
		  
		  TakCode[k][l] = s[i + k][j + l];
		}
	    }
	  
	  if (// 左上黒
	      TakCode[0][0] == '#' and
	      TakCode[0][1] == '#' and
	      TakCode[0][2] == '#' and
	      TakCode[1][0] == '#' and
	      TakCode[1][1] == '#' and
	      TakCode[1][2] == '#' and
	      TakCode[2][0] == '#' and
	      TakCode[2][1] == '#' and
	      TakCode[2][2] == '#' and
	      // 左上白
	      TakCode[3][0] == '.' and
	      TakCode[3][1] == '.' and
	      TakCode[3][2] == '.' and
	      TakCode[3][3] == '.' and
	      TakCode[0][3] == '.' and
	      TakCode[1][3] == '.' and
	      TakCode[2][3] == '.' and
	      // 右下黒
	      TakCode[6][6] == '#' and
	      TakCode[6][7] == '#' and
	      TakCode[6][8] == '#' and
	      TakCode[7][6] == '#' and
	      TakCode[7][7] == '#' and
	      TakCode[7][8] == '#' and
	      TakCode[8][6] == '#' and
	      TakCode[8][7] == '#' and
	      TakCode[8][8] == '#' and
	      // 右下白
	      TakCode[5][5] == '.' and
	      TakCode[5][6] == '.' and
	      TakCode[5][7] == '.' and
	      TakCode[5][8] == '.' and
	      TakCode[6][5] == '.' and
	      TakCode[7][5] == '.' and
	      TakCode[8][5] == '.')
	    {
	      cout << i + 1 << " " << j + 1 << endl;
	    }
	}
    }

  return 0;
}
