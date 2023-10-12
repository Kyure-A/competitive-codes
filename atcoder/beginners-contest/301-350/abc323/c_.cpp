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

bool g (pair<int, int> &left, pair<int, int> &right)
{
  if (left.first == right.first)
    {
      return right.second > left.second;
    }
  else return right.first < left.first;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<pair<int, int>> a(m);

  for (int i = 0; i < m; ++i)
    {
      int _a; cin >> _a;
      a[i] = {_a, i};
    }
  
  vector<string> s(n); rep(i, n) cin >> s[i];
  vector<int> players(n, 0);
  vector<bitset<100>> players_solved(n);

  for (int i = 0; i < n; ++i)
    {
      players[i] += i + 1;
      for (int j = m - 1; j >= 0; --j)
	{
	  if (s[i][j] == 'o')
	    {
	      players[i] += a[j].first;
	    }
	}
    }

  int max_solved_player_score = -1;
  
  for (int i = 0; i < n; ++i)
    {
      if (max_solved_player_score < players[i])
	{
	  max_solved_player_score = players[i];
	}
    }

  sort(all(a), g);

  auto f = [&](int player_score, int x) -> int
  {
    int result = 0;
    for (int i = 0; i < m; ++i)
      {
	if (player_score < max_solved_player_score)
	  {
	    if (s[x][a[i].second] == 'x')
	      {
		result++;
		player_score += a[i].first;
	      }
	  }
	else break;
      }
    
    return result;
  };

  for (int i = 0; i < n; ++i)
    {
      cout << f(players[i], i) << endl;
    }

    return 0;
}
