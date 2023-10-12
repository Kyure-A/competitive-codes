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

bool is_bingo (int x, int y, int z)
{
  vector<int> vec = {x, y, z};
  sort(all(vec));

  if ((vec[0] == 0 and vec[1] == 4 and vec[2] == 8) or
      (vec[0] == 2 and vec[1] == 4 and vec[2] == 6) or
      (vec[0] == 1 and vec[1] == 4 and vec[2] == 7) or
      (vec[0] == 3 and vec[1] == 4 and vec[2] == 5) or
      (vec[0] == 2 and vec[1] == 5 and vec[2] == 8) or
      (vec[0] == 6 and vec[1] == 7 and vec[2] == 8) or
      (vec[0] == 0 and vec[1] == 3 and vec[2] == 6) or
      (vec[0] == 0 and vec[1] == 1 and vec[2] == 2)) return true;
  else return false;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  vector<int> num(9);
  rep(i, 9) cin >> num[i];

  vector<int> indexes = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  
  long double dividend = 0;
  long double divisor = 362880;
  // 9! = 362880 回探索
  do
    {
      for (int i = 2; i < 9; ++i)
	{
	  if (num[indexes[i - 2]] == num[indexes[i - 1]] and
	      num[indexes[i - 2]] != num[indexes[i]] and
	      is_bingo(indexes[i], indexes[i - 1], indexes[i - 2]))
	    {
	      dividend++;
	      break;
	    }
	}
    }
  while (next_permutation(indexes.begin(), indexes.end()));

  long double answer = 1;
  long double subtracter = dividend / divisor;

  cout << setprecision(30) << answer - subtracter << endl;
  
  return 0;
}
