#include <bits/stdc++.h>
using namespace std;

vector<int> Dijktras_for_cost(int V, vector<vector<int>> adj[], int S, vector<int> &par)
{
    vector<int> dis(V, INT_MAX);
    dis[S] = 0;
    // par[S]=S;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    p.push({0, S});
    while (!p.empty())
    {
        auto x = p.top();
        int a = p.top().second;
        p.pop();
        for (int j = 0; j < adj[a].size(); j++)
        {

            if (dis[adj[a][j][0]] > adj[a][j][1] + dis[a])
            {
                dis[adj[a][j][0]] = adj[a][j][1] + dis[a];
                par[adj[a][j][0]] = a;
                p.push({dis[adj[a][j][0]], adj[a][j][0]});
            }
        }
    }
    return dis;
}

vector<int> Dijktras_for_Time(int V, vector<vector<int>> adj[], int S, vector<int> &par)
{
    vector<int> time(V, INT_MAX);
    time[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    p.push({0, S});
    while (!p.empty())
    {
        auto x = p.top();
        int a = p.top().second;
        p.pop();
        for (int j = 0; j < adj[a].size(); j++)
        {

            if (time[adj[a][j][0]] > adj[a][j][2] + time[a])
            {
                time[adj[a][j][0]] = adj[a][j][2] + time[a];
                par[adj[a][j][0]] = a;
                p.push({time[adj[a][j][0]], adj[a][j][0]});
            }
        }
    }
    return time;
}
void path(vector<int> &par, int j)
{
    if (par[j] == -1)
        return;
    path(par, par[j]);
    cout << j+1 << " ";
}

int main()
{
    // freopen("./graph2.txt", "r", stdin);
    // freopen("./Dijktras_algo.txt", "w", stdout);
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    int i = 0;
    while (i++ < E)
    {
        int u, v, wp, wt;
        cin >> u >> v >> wp >> wt;
        u--;
        v--;
        adj[u].push_back({v, wp, wt});
        adj[v].push_back({u, wp, wt});
    }
    int q;
    cin >> q;
    while (q--)
    {
        int src, dst;
        cin >> src >> dst;
        vector<int> par(V, -1);
        vector<int> res_C = Dijktras_for_cost(V, adj, src - 1, par);
        cout << "Minimum Cost: " << res_C[dst - 1] << endl;
        cout << "Minimum Cost Path: ";
        cout << src << " ";
        path(par, dst - 1);
        cout << endl;
        par = {-1};
        vector<int> res_T = Dijktras_for_Time(V, adj, src - 1, par);
        cout << "Minimum Time: " << res_T[dst - 1] << endl;
        cout << "minimum time Path: ";
        cout << src << " ";
        path(par, dst - 1);
        cout << endl;
        cout << "......................................................................" << endl;
    }

    return 0;
}
