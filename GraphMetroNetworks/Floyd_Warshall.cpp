#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Floyd_Warshall(int v_cnt, vector<vector<int>>& weight) {
  vector<vector<int>> ans(v_cnt, vector<int>(v_cnt));
  for(int u = 0; u < v_cnt; u++) {
    for(int v = 0; v < v_cnt; v++) {
      if(u == v) {
        ans[u][v] = 0;
      } else {
        ans[u][v] = weight[u][v];
      }
    }
  }
  for(int i = 0; i < v_cnt; i++) {
    for(int u = 0; u < v_cnt; u++) {
      for(int v = 0; v < v_cnt; v++) {
        if(ans[u][i] + ans[i][v] < ans[u][v]) {
          ans[u][v] = ans[u][i] + ans[i][v];
        }
      }
    }
  }
  return ans;
}

vector<bool> vis;
void recur(int u, int v, int v_cnt, vector<vector<int>>& weight, vector<vector<int>>& ans) {
  cout << u + 1 << ' ';
  vis[u] = 1;
  if(u == v) {
    return ;
  }
  for(int i = 0; i < v_cnt; i++) {
    if(!vis[i] && ans[u][i] == weight[u][i]) {
      return recur(i, v, v_cnt, weight, ans);
    }
  }
}

int32_t main() {
  // freopen("./testcases/graph_0.txt", "r", stdin);
  // freopen("./Floyd_Warshall.txt", "w", stdout);
  int v_cnt, e_cnt;
  const int inf = 1e8;
  cin >> v_cnt >> e_cnt;
  vector<vector<int>> cost(v_cnt, vector<int>(v_cnt, inf)), time(v_cnt, vector<int>(v_cnt, inf));
  for(int e = 0; e < e_cnt; e++) {
    int u, v, c, t;
    cin >> u >> v >> c >> t;
    u--; v--;
    cost[u][v] = c;
    cost[v][u] = c;
    time[u][v] = t;
    time[v][u] = t;
  }
  vector<vector<int>> cost_ans = Floyd_Warshall(v_cnt, cost);
  vector<vector<int>> time_ans = Floyd_Warshall(v_cnt, time);
  int q_cnt;
  cin >> q_cnt;
  for(int q = 1; q <= q_cnt; q++) {
    cout << "Processing query #" << q << " ...\n";
    int u, v;
    cin >> u >> v;
    u--; v--;
    cout << "Minimum cost required: " << cost_ans[u][v] << endl;
    cout << "The min-cost path is: ";
    vis.assign(v_cnt, 0);
    recur(u, v, v_cnt, cost, cost_ans);
    cout << endl;
    cout << "Minimum time required: " << time_ans[u][v] << endl;
    cout << "The min-time path is: ";
    vis.assign(v_cnt, 0);
    recur(u, v, v_cnt, time, time_ans);
    cout << endl << endl;
  }
  return 0;
}