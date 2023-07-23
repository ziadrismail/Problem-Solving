#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = (int) 2e5 + 5;

int n , m;
vector < int > g[N];
bool vis[N];
int cntV , cntE;

void dfs(int u){
        vis[u] = 1;
        cntV++;
        cntE += (int) g[u].size();
        for(auto v : g[u]){
                if(vis[v])
                        continue;
                dfs(v);
        }
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> m;
        while (m--){
                int u , v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
        }
        bool ans = 1;
        for (int i = 1; i <= n; ++i) {
                if(vis[i])
                        continue;
                cntE = cntV = 0;
                dfs(i);
                ans &= cntV == (cntE / 2);
        }
        cout << (ans ? "Yes" : "No");
        return 0;
}
