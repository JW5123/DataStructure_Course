#include <bits/stdc++.h>
using namespace std;
#define N 100000
#define INF 2147483647
vector<pair<int,int> > adj[N];
int d[N], p[N];
bool B[N] = {false};

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }
    int source = 0;
    for(int i = 0; i < n; i++){
        d[i] = INF;
    }
    for(int i = 0 ; i < n; i++){
        p[i] = -1;
    }
    priority_queue<pair<int,int> > PQ;
    PQ.push({d[source] = 0, source});
    while(!PQ.empty()){
        auto a = PQ.top();
        PQ.pop();
        int v = a.second;
        if(B[v]){
            continue;
        }
        B[v] = true;
        for(auto e: adj[v]){
            int u = e.first, w = e.second;
            if(d[v] + w < d[u]){
                d[u] = d[v] + w;
                p[u] = v;
                PQ.push({-d[u], u});
            }
        }
    }
    int mx = -1, count = 0, far;
    for(int i = 0 ; i < n; i++){
        if(d[i] < INF){
            if(d[i] > mx){
                mx = d[i], far = i;
            }
        }
        else{
            count++;
        }
    }
    cout << mx << "\n" << count << "\n";
    return 0;
}
