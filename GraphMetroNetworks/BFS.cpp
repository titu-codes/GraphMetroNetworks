#include <bits/stdc++.h>
using namespace std;
vector<int> BFS_for_cost(vector<vector<pair<int, pair<int, int>>>> &adj, int s, int V, vector<int> &par)
{
    queue<pair<int, int>> q;
    q.push({s, 0});
    vector<int> dis(V, INT_MAX);
    dis[s] = 0;
    vector<int> vis(V, false);
    while (!q.empty())
    {
        int d = q.front().second;
        int a = q.front().first;
        q.pop();
        if (!vis[a])
        {
            for (auto &j : adj[a])
            {
                if (dis[j.first] > d + j.second.first)
                {
                    par[j.first] = a;
                    dis[j.first] = d + j.second.first;
                    q.push({j.first, dis[j.first]});
                }
            }
        }
        vis[a] = true;
    }
    return dis;
}
vector<int> BFS_for_time(vector<vector<pair<int, pair<int, int>>>> &adj, int s, int V, vector<int> &par)
{
    queue<pair<int, int>> q;
    q.push({s, 0});
    vector<int> dis(V, INT_MAX);
    dis[s] = 0;
    vector<int> vis(V, false);
    while (!q.empty())
    {
        int d = q.front().second;
        int a = q.front().first;
        q.pop();
        if (!vis[a])
        {
            for (auto &j : adj[a])
            {
                if (dis[j.first] > d + j.second.second)
                {
                    dis[j.first] = d + j.second.second;
                    par[j.first] = a;
                    q.push({j.first, dis[j.first]});
                }
            }
        }
        vis[a] = true;
    }
    return dis;
}

void path(vector<int> &par, int j)
{
    if (par[j] == -1)
        return;
    path(par, par[j]);
    cout << j << " ";
}

int main()
{
    // freopen("./graph1.txt", "r", stdin);
    // freopen("./BFS.txt", "w", stdout);
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, pair<int, int>>>> adj(V);

    for (int i = 0; i < E; i++)
    {
        int u, v, wc, wt;
        cin >> u >> v >> wc >> wt;
        u--;
        v--;
        adj[u].push_back({v, {wc, wt}});
        adj[v].push_back({u, {wc, wt}});
    }
    int q;
    cin >> q;
    while (q--)
    {
        int src, dst;
        cin >> src >> dst;
        vector<int> par(V, -1);
        vector<int> res_C = BFS_for_cost(adj, src - 1, V, par);
        cout << "Minimum Cost: " << res_C[dst - 1] << endl;
        cout << "Minimum Cost Path: ";
        cout << src - 1 << " ";
        path(par, dst - 1);
        cout << endl;
        par = {-1};
        vector<int> res_T = BFS_for_time(adj, src - 1, V, par);
        cout << "Minimum Time: " << res_T[dst - 1] << endl;
        cout << "minimum time Path: ";
        cout << src - 1 << " ";
        path(par, dst - 1);
        cout << endl;
        cout << "......................................................................" << endl;
    }

    return 0;
}
