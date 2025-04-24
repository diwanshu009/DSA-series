#include<bits/stdc++.h>
using namespace std;

// -- Graph and types
// -- Graph representation (adjacency list and adjacency matrix)

// BFS
void bfs(vector<int>adj[],vector<bool>&vis,int u){
    queue<int>q;
    q.push(u);
    vis[u] = 1;
    while(!q.empty()){
        int front = q.front();
        cout << front << endl;
        q.pop();
        for(auto i:adj[front]){
            if(!vis[i]){
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

// DFS
void dfs(vector<int>adj[],vector<bool>&vis,int u){
    vis[u] = 1;
    cout << u << endl;
    for(auto i:adj[u]){
        if(!vis[i]){
            dfs(adj,vis,i);
        }
    }
}

// problems - 1. Rotten oranges
// 2. no. of islands plus the variety
// 3. cycle detection in undirected graph --> (parent method by both dfs and bfs)
    //  --> if any node is visited before and is not the parent of current node then cycle is present
// 4. Word Ladder-1 and Word Ladder-2
// 5. Bipartite graph 

int main(){

}