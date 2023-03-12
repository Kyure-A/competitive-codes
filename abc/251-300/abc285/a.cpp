/* include */
#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all> using namespace atcoder;

/* Macro */
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define per3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))

/* Type */
// #define int long long
#define cauto const auto&
typedef long long i64;
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;


signed main ()
{
  int a, b;
  cin >> a >> b;
  vector<vector<int>> Graph(30);
  Graph[1].push_back(2);
  Graph[1].push_back(3);
  Graph[2].push_back(1);
  Graph[2].push_back(4);
  Graph[2].push_back(5);
  Graph[3].push_back(1);
  Graph[3].push_back(6);
  Graph[3].push_back(7);
  Graph[4].push_back(2);
  Graph[4].push_back(8);
  Graph[4].push_back(9);
  Graph[5].push_back(2);
  Graph[5].push_back(10);
  Graph[5].push_back(11);
  Graph[6].push_back(3);
  Graph[6].push_back(12);
  Graph[6].push_back(13);
  Graph[7].push_back(3);
  Graph[7].push_back(14);
  Graph[7].push_back(15);
  Graph[8].push_back(4);
  Graph[9].push_back(4);
  Graph[10].push_back(5);
  Graph[11].push_back(5);
  Graph[12].push_back(6);
  Graph[13].push_back(6);
  Graph[14].push_back(7);
  Graph[15].push_back(7);


  bool flag[2] = {false};
  
  for (auto x : Graph[a])
    {
      if (x == b) flag[0] = true;
    }

  for (auto x : Graph[b])
    {
      if (x == a) flag[1] = true;
    }

  if (flag[0] and flag[1]) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
