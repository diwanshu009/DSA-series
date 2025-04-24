#include<bits/stdc++.h>
using namespace std;

// Cycle Detect in directed Graph --> using pathVis array (using dfs)
bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
    vis[node] = 1;
    pathVis[node] = 1;

    // traverse for adjacent nodes
    for (auto it : adj[node]) {
        // when the node is not visited
        if (!vis[it]) {
            if (dfsCheck(it, adj, vis, pathVis) == true)
                return true;
        }
        // if the node has been previously visited
        // but it has to be visited on the same path
        else if (pathVis[it]) {
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
} 

//  Topo Sort --> 
                // In topological sorting, node u will always appear before node v if there is a directed edge 
                // from node u towards node v(u -> v). Only on DAGs
//  Finding topo Sort using kahn's Algorithm

vector<int> topoSort(int V, vector<int> adj[]){
	vector<int>indeg(V,0);
	for (int i = 0; i < V; i++) {
		for (auto it : adj[i]) {
			indeg[it]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < V; i++) {
		if (indeg[i] == 0) q.push(i);
	}
	vector<int> topo;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		topo.push_back(node);

		for (auto it : adj[node]) {
			indeg[it]--;
			if (indeg[it] == 0) q.push(it);
		}
	}

	return topo;
}

// Cycle detection in directed graph by BFS --> if topo sort size != to total number of nodes, cycle present.

// Problems --> 1. Course schedule 1 and 2
// 2. Alien dictionary

int main(){

}