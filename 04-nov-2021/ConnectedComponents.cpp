#include <bits/stdc++.h>
#include <string>
using namespace std;

const int N = 30;
int vis[N], tc, n, e, comp;
vector<vector<int>> adj(N);
char chr;
priority_queue <char> pq;

void dfs(int x) {
    vis[x] = 1;
    pq.push(-x-97);
    for (int i = 0; i < adj[x].size(); i++)
        if (!vis[adj[x][i]])
            dfs(adj[x][i]);
}

int main () {
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < N; i++) adj[i].clear();
        comp = 0;

        cin >> n >> e;

        for (int i = 0; i < e; i++) {
            char a, b;
            cin>>a>>b;
            a -= 97; b -= 97;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        cout<<"Case #"<<t<<":";

        for (int i = 0; i < n; i++)
            if (!vis[i]) {
                comp++;
                cout<<"\n";
                dfs(i);
                while (!pq.empty()) {
                    cout <<(char)-pq.top()<<",";
                    pq.pop();
                }

            }

        cout<<"\n"<<comp<<" connected components\n\n";
    }
    return 0;
}