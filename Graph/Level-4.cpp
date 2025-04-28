#include<bits/stdc++.h>
using namespace std;

// some other important algorithms

// 1. Kosaraju algorithm (To find strongly connected components)
// It can only be applied to directed graphs
void dfs(vector<int>adj[],int front,stack<int>&st,vector<bool>&vis){
	vis[front] = 1;
	for(auto i:adj[front]){
		if(!vis[i]){
			dfs(adj,i,st,vis);
		}
	}
	st.push(front);
}

void dfs2(vector<bool>&vis,vector<int>adj2[],int front){
	vis[front] = 1;
	for(auto i:adj2[front]){
		if(!vis[i]){
			dfs2(vis,adj2,i);
		}
	}
}

int stronglyConnectedComponents(int n, vector<vector<int>> &edges){
	vector<int>adj[n];
	vector<int>adj2[n];
	for(int i=0;i<edges.size();i++){
		int u = edges[i][0];
		int v = edges[i][1];
		adj[u].push_back(v);
		adj2[v].push_back(u);
	}
	vector<bool>vis(n,0);
	stack<int>st;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(adj,i,st,vis);
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++) vis[i]=0;
	while(!st.empty()){
		int top = st.top();
		st.pop();
		if(!vis[top]){
			ans++;
			dfs2(vis,adj2,top);
		}
	}
	return ans;
}

// 2. Tarzan Algorithm (To find bridges in the graph)
void dfs(int u,int parent,vector<bool>&vis,vector<int>adj[],int tin[],int low[],vector<vector<int>>&ans,int &time){
    vis[u] = 1;
    tin[u] = low[u] = time;
    time++;
    for(auto i:adj[u]){
        if(i == parent) continue;
        if(!vis[i]){
            dfs(i,u,vis,adj,tin,low,ans,time);
            if(low[i]>tin[u]){
                ans.push_back({u,i});
            }
        }
        low[u] = min(low[u],low[i]);
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>>ans;
    int time = 1;
    vector<bool>vis(n,0);
    vector<int>adj[n];
    for(int i=0;i<connections.size();i++){
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
    }
    int tin[n];
    int low[n];
    dfs(0,-1,vis,adj,tin,low,ans,time);
    return ans;
}

// 3. Articulation point in Graph
class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[],
            vector<int> &mark, vector<int>adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            }
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }
public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<int> mark(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0) return { -1};
        return ans;
    }
};