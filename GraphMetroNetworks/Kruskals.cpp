#include <bits/stdc++.h>
using namespace std;

class DSU {
	public:
	vector<int> head;
	vector<int> size;
	DSU(int n) {
		head.assign(n, 0);
		size.assign(n, 1);
		for(int i = 0; i < n; i++) {
			head[i] = i;
		}
	}
	int get(int x) {
		if (x != head[x]) {
			head[x] = get(head[x]);
		}
		return head[x];
	}
	void U(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b)
			return;
		if (size[a] < size[b])
			swap(a, b);
		head[b] = a;
		size[a] += size[b];
	}
};

void Minimum_Spanning_Tree(int v_cnt, int e_cnt, vector<vector<int>>& edges) {
	DSU set(v_cnt);
	sort(edges.begin(), edges.end(), [&](auto& x, auto& y) {
		return x[2] < y[2];
	});
	vector<vector<int>> MST;
	for(int e = 0; e < e_cnt; e++) {
		if(set.get(edges[e][0]) != set.get(edges[e][1])) {
			MST.push_back(edges[e]);
			set.U(edges[e][0], edges[e][1]);
		}
	}
	int ans = 0;
	for(int e = 0; e < v_cnt - 1; e++) {
		ans += MST[e][2];
	}
	cout << "Total weight of spanning tree: " << ans << endl;
	cout << "Spanning tree edges" << endl;
	for(int e = 0; e < v_cnt - 1; e++) {
		cout << MST[e][0] + 1 << ' ' << MST[e][1] + 1 << '\n';
	}
}

int32_t main() {
	// freopen("./testcases/graph_0.txt", "r", stdin);
	// freopen("./Kruskals.txt", "w", stdout);
	int v_cnt, e_cnt;
	const int inf = 1e8;
	cin >> v_cnt >> e_cnt;
	vector<vector<int>> cost, time;
	for (int e = 0; e < e_cnt; e++)	{
		int u, v, c, t;
		cin >> u >> v >> c >> t;
		u--; v--;
		cost.push_back(vector<int> {u, v, c});
		time.push_back(vector<int> {u, v, t});
	}
	cout << "Cost MST\n--------\n";
	Minimum_Spanning_Tree(v_cnt, e_cnt, cost);
	cout << "\nTime MST\n--------\n";
	Minimum_Spanning_Tree(v_cnt, e_cnt, time);
	return 0;
}