#include <bits/stdc++.h>
using namespace std;

void bfsTraversal(int startNode, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& bfs) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    vector<bool> visited(n, false);
    vector<int> bfs;
    bfsTraversal(0, adjList, visited, bfs);

    cout << "BFS Traversal: ";
    for (int node : bfs) {
        cout << node << " ";
    }
    return 0;   
}

// T.C : O(V + E) where V is the number of vertices and E is the number of edges in the graph. This is because we visit each vertex and edge at most once during the BFS traversal.
// S.C : O(V) in the worst case, when the graph is a complete graph and all vertices are visited. This is because we need to store the visited array and the BFS result, which can both grow up to O(V) in size. In the best case, when the graph is a tree, the space complexity can be O(W) where W is the maximum width of the tree, due to the queue used for BFS traversal.    

// java code
// import java.util.ArrayList;
// import java.util.Queue;
// import java.util.LinkedList;

// class GFG {
//     // BFS for single connected component
//     static ArrayList<Integer> bfs(ArrayList<ArrayList<Integer>> adj) {
//         int V = adj.size();
//         boolean[] visited = new boolean[V];
//         ArrayList<Integer> res = new ArrayList<>();
        
//         int src = 0;
//         Queue<Integer> q = new LinkedList<>();
//         visited[src] = true;
//         q.add(src);

//         while (!q.isEmpty()) {
//             int curr = q.poll();
//             res.add(curr);

//             // visit all the unvisited
//             // neighbours of current node
//             for (int x : adj.get(curr)) {
//                 if (!visited[x]) {
//                     visited[x] = true;
//                     q.add(x);
//                 }
//             }
//         }
        
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

//         ArrayList<Integer> res = bfs(adj);

//         for (int x : res)
//             System.out.print(x + " ");
//     }
// }