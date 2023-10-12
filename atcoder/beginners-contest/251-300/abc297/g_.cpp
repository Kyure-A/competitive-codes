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

unordered_map<int, int> grundy;

int calculateGrundy(int x, int L, int R)
{
  if (grundy.find(x) != grundy.end())
    {
      return grundy[x];
    }
  vector<bool> s(R + 1);
  for (int i = L; i <= R; i++)
    {
      if (x - i >= 0)
	{
	  s[calculateGrundy(x - i, L, R)] = true;
	}
    }
  int mex = 0;
  while (s[mex])
    {
      mex++;
    }
  return grundy[x] = mex;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N, L, R;
  cin >> N >> L >> R;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  
  int result = 0;
  for (int i = 0; i < N; i++)
    {
      result ^= calculateGrundy(A[i], L, R);
    }

  if (result != 0)
    {
      cout << "First" << endl;
    }
  else
    {
      cout << "Second" << endl;
    }

  return 0;
}
