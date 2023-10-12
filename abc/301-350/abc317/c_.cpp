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

signed solve(int N, int M, vector<vector<int>>& roads) {
  unordered_map<int, vector<pair<int, int>>> road_dict;
  for (int i = 0; i < M; ++i) {
    int A = roads[i][0];
    int B = roads[i][1];
    int C = roads[i][2];
    road_dict[A].emplace_back(B, C);
    road_dict[B].emplace_back(A, C);
  }

  
    
  int result = 0;
  for (int start_node = 1; start_node <= N; ++start_node) {
    set<int> visited = {start_node};
        
    auto dfs = [&](auto&& self, int node, const set<int>& visited) {
      if (visited.size() == N) {
	return 0;
      }
            
      int max_length = 0;
      for (const auto& neighbor_info : road_dict[node]) {
	int neighbor = neighbor_info.first;
	int length = neighbor_info.second;
	if (visited.find(neighbor) == visited.end()) {
	  set<int> new_visited = visited;
	  new_visited.insert(neighbor);
	  max_length = max(max_length, length + self(self, neighbor, new_visited));
	}
      }
            
      return max_length;
    };
        
    result = max(result, dfs(dfs, start_node, visited));
  }
    
  return result;
}

signed main () {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N, M;
  cin >> N >> M;
    
  vector<vector<int>> roads(M, vector<int>(3));
  for (int i = 0; i < M; ++i) {
    cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
  }
    
  int answer = solve(N, M, roads);
  cout << answer << endl;

  return 0;
}
