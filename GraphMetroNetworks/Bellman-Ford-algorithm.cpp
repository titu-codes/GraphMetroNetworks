#include <bits/stdc++.h>
using namespace std;
int Bellman_ford_for_cost(int n, vector<vector<int>> &e, vector<int> &par, vector<int> &dis)
{

    for (int i = 1; i <= n; i++)
    {
        for (auto &j : e)
        {
            if (dis[j[0]] != INT_MAX && dis[j[0]] + j[2] < dis[j[1]])
            {
                dis[j[1]] = dis[j[0]] + j[2];
                par[j[1]] = j[0];
            }
        }
    }
    for (auto &j : e)
    {
        if (dis[j[0]] != INT_MAX && dis[j[0]] + j[2] < dis[j[1]])
        {
            cout << "Negative Cycle Detected" << endl;
            return -1;
        }
    }
    return 1;
}
int Bellman_ford_for_time(int n, vector<vector<int>> &e, vector<int> &par, vector<int> &dis)
{

    for (int i = 1; i <= n; i++)
    {
        for (auto &j : e)
        {
            if (dis[j[0]] != INT_MAX && dis[j[0]] + j[3] < dis[j[1]])
            {
                dis[j[1]] = dis[j[0]] + j[3];
                par[j[1]] = j[0];
            }
        }
    }
    for (auto &j : e)
    {
        if (dis[j[0]] != INT_MAX && dis[j[0]] + j[3] < dis[j[1]])
        {
            cout << "Negative Cycle Detected" << endl;
            return -1;
        }
    }
    return 1;
}

void path(vector<int> &par, int j)
{
    if (par[j] == -1)
        return;
    path(par, par[j]);
    cout << j + 1 << " ";
}

int main()
{

    // freopen("./graph3.txt", "r", stdin);
    // freopen("./Bellman_ford_for_cost.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int x, y, wc, wt;
        cin >> x >> y >> wc >> wt;
        x--;
        y--;
        edges.push_back({x, y, wc, wt});
        // if (wc < 0 || wt < 0)
        //     edges.push_back({y, x, wc, wt});

    }
    int q;
    cin >> q;
    while (q--)
    {
        int src, dst;
        cin >> src >> dst;
        src--;
        dst--;
        vector<int> par(n, -1);
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
        int ans = Bellman_ford_for_cost(n, edges, par, dis);

        if (ans == -1)
            continue;
        // cout << "There is Negative weight cycle Present is this Graph" << endl;
        cout << "Minimum Cost: " << dis[dst] << endl;
        cout << "Minimum Cost Path: ";
        cout << src + 1 << " ";
        path(par, dst);
        cout << endl;
        par = {-1};
        dis = {INT_MAX};
        dis[src] = 0;
        int ans2 = Bellman_ford_for_time(n, edges, par, dis);
        if (ans2 == -1)
            continue;
        cout << "Minimum Time: " << dis[dst] << endl;
        cout << "Minimum Time Path: ";
        cout << src + 1 << " ";
        path(par, dst);
        cout << "..................................................." << endl;
    }

    return 0;
}