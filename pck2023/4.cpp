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

long double euclidean_distance (pair<int, int> point1, pair<int, int> point2)
{
  long long x2 = (point2.first - point1.first) * (point2.first - point1.first);
  long long y2 = (point2.second - point1.second) * (point2.second - point1.second);
  long long z2 = x2 + y2;
  return sqrt(z2);
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  set<pair<int, int>> st;
  vector<pair<int, int>> points;
  for (int i = 0; i < 4; ++i)
      {
	int x, y; cin >> x >> y;
	st.insert({x, y});
	points.push_back({x, y});
      }

  bool cond1 = true;
  bool cond2 = true;
  bool cond3 = true;
  
  if (st.size() != 4) cond1 = false;
  vector<long double> dist(4);

  dist[0] = euclidean_distance(points[0], points[1]);
  dist[1] = euclidean_distance(points[1], points[2]);
  dist[2] = euclidean_distance(points[2], points[3]);
  dist[3] = euclidean_distance(points[3], points[0]);

  for (int i = 0; i < 4; ++i)
    {
      for (int j = 0; j < 4; ++j)
	{
	  if (i == j) continue;
	  if (dist[i] != dist[j]) cond2 = false;
	}
    }

  if (euclidean_distance(points[3], points[1]) != euclidean_distance(points[0], points[2])) cond3 = false;
  
  cout << (cond1 and cond2 and cond3 ? "Yes" : "No") << endl;
  
  return 0;
}
