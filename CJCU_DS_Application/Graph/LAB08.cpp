#include <bits/stdc++.h>
#define N 50000
using namespace std;

vector<int> adj[N];
int w[N];
bool Visit[N] = {false};
int DFS(int s){
    int weight = w[s];
    Visit[s] = true;
    for(auto &i : adj[s]){
        if(!Visit[i]){
            weight += DFS(i);
        }
    }
    return weight;
}
signed main(){
    int m, n, MAX = 0, total = 0;
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        cin >> w[i];
        total += w[i];
    }
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < m; i++){
        if(!Visit[i]){
            MAX = max(MAX, DFS(i));
        }
    }
    cout << MAX << endl;
    cout << "ans=" << MAX << ", total=" << total << endl;
}