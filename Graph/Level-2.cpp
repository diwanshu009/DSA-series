#include<bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm - To find the shortest path to each node from the given source node (Fails on negative edges)
void help(vector<pair<int,int>>adj[],int u,vector<int>&ans){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,u});
    while(!pq.empty()){
        int dist = pq.top().first;
        int top = pq.top().second;
        pq.pop();
        for(auto i:adj[top]){
            if(dist+i.second<ans[i.first]){
                ans[i.first] = dist+i.second;
                pq.push({dist+i.second,i.first});
            }
        }
    }
}

// Problems - 1. Shortest Path in binary matrix
// 2. Cheapest flights within K stops
// 3. Number of Ways to Arrive at Destination

// Bellman-Ford Algorithm (Works on negative edges as well)
vector<int> bellman_ford(int n, vector<vector<int>>& edges, int S) {
    vector<int> dist(n, 1e8);
    dist[S] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    // Nth relaxation to check negative cycle
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return {-1};
        }
    }
    return dist;
}

// Floyd Warshall Algorithm
void shortest_distance(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) matrix[i][j] = 1e9;
            if (i == j) matrix[i][j] = 0;
        }
    }

    // try to reach every other node via every other node
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1e9) {
                matrix[i][j] = -1;
            }
        }
    }
    // If we want to check for a negative cycle :->
    // Outside those three loops, run a loop and check if any cell (i == j) contains a value less than 0.
}

int main(){

}