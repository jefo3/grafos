#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int start, vector<vector<int>>& adj, vector<bool>& is_visited) {
  queue<int> vertices_queue;
  is_visited[start] = true;
  vertices_queue.push(start);

  while(!vertices_queue.empty()) {
    int current_vertex = vertices_queue.front();
    vertices_queue.pop();
    cout << current_vertex << " ";

    for (int neighbor: adj[current_vertex]) {
      if (!is_visited[neighbor]) {
        is_visited[neighbor] = true;
        vertices_queue.push(neighbor);
      }
    }
  }
}

int main() {

  vector<vector<int>> adj {
        {1, 2},    // Vértice 0 conectado aos vértices 1 e 2
        {0, 3, 4}, // Vértice 1 conectado aos vértices 0, 3 e 4
        {0},       // Vértice 2 conectado ao vértice 0
        {1},       // Vértice 3 conectado ao vértice 1
        {1}        // Vértice 4 conectado ao vértice 1
    };
  
  vector<bool> is_visited(adj.size(), false);

  BFS(0, adj, is_visited);

  return 0;
}