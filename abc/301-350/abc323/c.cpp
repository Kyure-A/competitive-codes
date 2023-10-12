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

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<int> a(m); rep(i, m) cin >> a[i];
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
	      players[i] += a[j];
	      players_solved[i].set(j, 1);
	    }
	}
    }

  bitset<100> max_solved; max_solved.reset();
  int max_solved_player = -1;
  int max_solved_player_score = -1;
  
  for (int i = 0; i < n; ++i)
    {
      if (max_solved_player_score < players[i])
	{
	  max_solved_player = i;
	  max_solved_player_score = players[i];
	  max_solved = players_solved[i];
	}
    }

  for (int i = 0; i < n; ++i)
    {
      if (i == max_solved_player) cout << 0 << endl;
      else cout << max_solved.count() - players_solved[i].count() + 1<< endl;
    }

  return 0;
}
