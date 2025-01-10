#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

void DFS(int v, vector<vector<int>>& adj, vector<bool>& is_visited) {
  is_visited[v] = true;
  
  cout << v << " ";  // Exibe o vértice

  for (int u: adj[v]) {
    if (!is_visited[u]) {
      DFS(u, adj, is_visited);
    }
  }
}

int main () {

  const int number_of_vertices = 4;
  
  //lista de adjacencia
  vector<vector<int>> adj{{1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2}};
  
  vector<bool> is_visited(number_of_vertices, false);

  DFS(0, adj, is_visited);

  return 0;
}