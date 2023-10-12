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

  string s; cin >> s;
  int n = s.size();
  map<char, vector<int>> count; 
  
  for (int i = 0; i < n; ++i)
    {
      count[s[i]].emplace_back(i + 1);
    }

  if (count['R'][0] < count['K'][0]
      and count['K'][0] < count['R'][1]
      and count['B'][0] % 2 != count['B'][1] % 2)
    {
      cout << "Yes" << endl;
      return 0;
    }

  cout << "No" << endl;

  return 0;
}
