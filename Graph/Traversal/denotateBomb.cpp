// You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle with the center as the location of the bomb.
// The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.
// You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. These bombs will further detonate the bombs that lie in their ranges.
// Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.
//LC : https://leetcode.com/problems/detonate-the-maximum-bombs/description/

#include <bits/stdc++.h>
using namespace std;


// We can represent the bombs and their detonation relationships as a directed graph, where each bomb is a node and there is a directed edge from bomb A to bomb B if bomb B is within the range of bomb A. Then we can use DFS or BFS to find the maximum number of bombs that can be detonated starting from each bomb.

void dfs(int node, vector<vector<int>>& adj, unordered_set<int>& visited) {
    visited.insert(node);
    for (int neighbor : adj[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, adj, visited);
        }
    }
}

int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    int m = bombs[0].size();
    vector<vector<int>>adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                long long r = bombs[i][2];
                if (dx * dx + dy * dy <= r * r) {
                    adj[i].push_back(j);
                }
            }
        }
    }

    // Now we need to find the maximum number of bombs that can be detonated starting from each bomb.
    // We can use DFS or BFS for this.
    unordered_set<int> visited(n);
    int maxDetonated = 0;
    for(int i = 0; i < n; i++) {
        dfs(i, adj, visited);
        maxDetonated = max(maxDetonated, (int)visited.size());
        visited.clear();
    }
    return maxDetonated;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> bombs(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> bombs[i][0] >> bombs[i][1] >> bombs[i][2];
    }

    // The logic to solve the problem will go here. We will need to create a graph where each bomb is a node and there is a directed edge from bomb A to bomb B if bomb B is within the range of bomb A. Then we can use DFS or BFS to find the maximum number of bombs that can be detonated starting from each bomb.
    
    return 0;   
}