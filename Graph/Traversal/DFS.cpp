#include <bits/stdc++.h>
using namespace std;


vector<int>dfsTraversal(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& dfs) {
    visited[node] = true;
    dfs.push_back(node);
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsTraversal(neighbor, graph, visited, dfs);
        }
    }
    return dfs;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // For undirected graph
    }

    vector<bool> visited(n, false);
    vector<int>dfs;
    dfs= dfsTraversal(0, graph, visited ,dfs);
    return 0;   
}

// T.C : O(V + E) where V is the number of vertices and E is the number of edges in the graph. This is because we visit each vertex and edge at most once during the DFS traversal.
// S.C : O(V) in the worst case, when the graph is a complete graph and all vertices are visited. This is because we need to store the visited array and the DFS result, which can both grow up to O(V) in size. In the best case, when the graph is a tree, the space complexity can be O(H) where H is the height of the tree, due to the recursive call stack.


// java code
// import java.util.ArrayList;

// class GFG {
//     static void dfsRec(ArrayList<ArrayList<Integer>> adj,
//            boolean[] visited, int s, ArrayList<Integer> res)
//     {
//         visited[s] = true;
//         res.add(s);

//         // Recursively visit all adjacent vertices 
//         // that are not visited yet
//         for (int i : adj.get(s)) {
//             if (!visited[i]) {
//                 dfsRec(adj, visited, i, res);
//             }
//         }
//     }

//     static ArrayList<Integer>dfs(ArrayList<ArrayList<Integer>> adj) {
//         boolean[] visited = new boolean[adj.size()];
//         ArrayList<Integer> res = new ArrayList<>();
//         dfsRec(adj, visited, 0, res);
//         return res;
//     }
    
//     static void addEdge(ArrayList<ArrayList<Integer>> adj, int u, int v) {
//         adj.get(u).add(v);
//         adj.get(v).add(u);
//     }
    
//     public static void main(String[] args) {
//         int V = 5;
//         ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        
//         // creating adjacency list
//         for (int i = 0; i < V; i++)
//             adj.add(new ArrayList<>());

//         addEdge(adj, 1, 2);
//         addEdge(adj, 1, 0);
//         addEdge(adj, 2, 0);
//         addEdge(adj, 2, 3);
//         addEdge(adj, 2, 4);

//         // Perform DFS starting from vertex 0
//         ArrayList<Integer> res = dfs(adj);

//         for (int i = 0; i < res.size(); i++) {
//             System.out.print(res.get(i) + " ");
//         }
//     }
// }


