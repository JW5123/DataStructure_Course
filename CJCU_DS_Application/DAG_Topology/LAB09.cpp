#include <bits/stdc++.h>
using namespace std;
#define N 20
int main()
{
    vector<int> adj[N];
    int indeg[N] = {0};
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++){
        int from, to;
        scanf("%d%d", &from, &to);
        adj[from].push_back(to);
        indeg[to]++;
    }
    int topo[N], head = 0, tail = 0;
    for (int i = 0; i < n; i++){
        if (indeg[i] == 0){
            topo[tail++] = i;
        }
    }
    while (head < tail){
        int v = topo[head++];
        for (int u : adj[v]){
            if (--indeg[u] == 0)
                topo[tail++] = u;
        }
    }
    if (tail < n)
        printf("No a DAG\n");
    else{
        for (int i = 0; i < n; i++)
            printf("%d ", topo[i]);
        printf("\n");
    }
    return 0;
}


/*
0 1
2 0
2 3
1 3
3 4
3 5
4 6
4 7
6 5
7 5
*/