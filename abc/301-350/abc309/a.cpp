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
constexpr double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int a, b; cin >> a >> b;
  vector<vector<bool>> grid(10, vector<bool>(10, false));
  grid[1][2] = true;
  // grid[1][4] = true;
  
  grid[2][1] = true;
  grid[2][3] = true;
  // grid[2][5] = true;
  
  grid[3][2] = true;
  // grid[3][6] = true;
  
  // grid[4][1] = true;
  // grid[4][7] = true;
  grid[4][5] = true;
  
  // grid[5][2] = true;
  grid[5][6] = true;
  grid[5][4] = true;
  // grid[5][8] = true;
  
  // grid[6][3] = true;
  grid[6][5] = true;
  // grid[6][9] = true;
  
  // grid[7][4] = true;
  grid[7][8] = true;

  // grid[8][5] = true;
  grid[8][7] = true;
  grid[8][9] = true;
  
  // grid[9][6] = true;
  grid[9][8] = true;

  if (grid[a][b]) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
