#include<bits/stdc++.h>
using namespace std;

// Minimum spanning tree (MST): MST have N nodes, N-1 edges and no cycles possible with the shortest edge weight sum.

// Prim's Algo for MST: 
int prims(vector<vector<int>>& edges, int n){
	vector<pair<int,int>>adj[n];
	for(int i=0;i<edges.size();i++){
		adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
		adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
	}
	int ans = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,0});
	vector<bool>vis(n,0);
	while(!pq.empty()){
		int front = pq.top().second;
		int dist = pq.top().first;
		pq.pop();
		if(vis[front]) continue;
		vis[front] = 1;
		ans += dist;
		for(auto i:adj[front]){
			if(!vis[i.first]){
				pq.push({i.second,i.first});
			}
		}
	}
	return ans;
}

// Disjoint set data structure (union by rank, size)
class ds{
	vector<int>rank,size,parent;
	public:
	ds(int n){
		rank.resize(n+1,0);
		parent.resize(n+1,0);
		size.resize(n+1,0);
		for(int i=0;i<=n;i++){
			parent[i] = i;
			size[i] = 1;
		}
	}
	int findPar(int node){
		if(node == parent[node]) return node;
		return parent[node] = findPar(parent[node]);
	}
	void UnionByRank(int u,int v){
		int x = findPar(u);
		int y = findPar(v);
		if(x == y) return;
		if(rank[x]<rank[y]) parent[x] = y;
		else if(rank[x]>rank[y]) parent[y] = x;
		else{
			parent[y] = x;
			rank[x]++;
		}
	}
	void UnionBySize(int u, int v){
        int x = findPar(u);
        int y = findPar(v);
        if (x == y) return;
        if (size[x] < size[y]){
            parent[x] = y;
            size[y] += size[x];
        }
        else{
            parent[y] = x;
            size[x] += size[y];
        }
    }
};

// Problems (dsu) : 1. Kruskal Algorithm
// 2. Number of operations to make network connected
// 3. Accounts merge
// 4. Making a large island

int main(){

}