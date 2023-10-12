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

bool f (pair<int, int> left, pair<int, int> right)
{
  if (left.first == right.first)
    {
      return right.second < left.second;
    }
  else return right.first > left.first;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<string> s(n); rep(i, n) cin >> s[i];
  vector<pair<int, int>> winners;

  for (int i = 0; i < n; ++i)
    {
      int win = 0;
      
      for (int j = 0; j < n; ++j)
	{
	  if (s[i][j] == 'o') win++;
	}

      winners.push_back({win, i + 1});
    }

  sort(winners.begin(), winners.end(), f());

  for (auto x : winners)
    {
      cout << x.first << " ";
    }
  
  return 0;
}
