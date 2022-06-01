#include <bits/stdc++.h>
using namespace std;

int main(){
    
    vector<pair<int,int> > adj;
    int node, edge, source, goal;

    cin >> node >> edge;
    cin >> source >> goal;

    //if (begin == dest){ 

        //cout<<"0\n0\n"; 

    //} 

    //else{

    for(int i = 0; i < node; i++){
        adj.push_back({INT_MAX,INT_MIN});
    }
    adj[source].first = adj[source].second = 0;

    int begin, end, w;

    for(int i = 0; i < edge; i++){
        cin >> begin >> end >> w;
        adj[end].first = min(adj[end].first, adj[begin].first + w);
        adj[end].second = max(adj[end].second, adj[begin].second + w);
    }
    if(adj[goal].first == INT_MAX){
        cout << "No path\nNo path\n";
    }
    else{
        cout << adj[goal].first << "\n" << adj[goal].second << "\n";
    }

    return 0;
}