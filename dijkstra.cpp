#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra(int source, vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
  int n = graph.size();
  vector<bool> visited(n, false);

  dist[source] = 0;

  for(int i = 0; i < n; i++) {
    int min_distance = INT_MAX;
    int current_vertex = -1;

    for(int j = 0; j < n; j++) {
      if(!visited[j] && dist[j] < min_distance) {
        min_distance = dist[j];
        current_vertex = j;
      }
    }

    if(current_vertex == -1) break;

    visited[current_vertex] = true;

    for(auto neihhbor: graph[current_vertex]) {
      int neighbor_vertex = neihhbor.first;
      int weight = neihhbor.second;

      if(dist[current_vertex] + weight < dist[neighbor_vertex]) {
        dist[neighbor_vertex] = dist[current_vertex] + weight;
      }
    }


  }
}

void dijkstra_with_priority_queue(int source, vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  dist[source] = 0;
  pq.push({0, source});

  while(!pq.empty()) {
    int current_distance = pq.top().first;
    int current_vertex = pq.top().second;

    pq.pop();

    if(dist[current_vertex] < current_distance) continue;

    for(auto neighbor: graph[current_vertex]) {
      int neighbor_vertex = neighbor.first;
      int weight = neighbor.second;

      if(current_distance + weight < dist[neighbor_vertex]) {
        dist[neighbor_vertex] = current_distance + weight;
        pq.push({dist[neighbor_vertex], neighbor_vertex});
      }
    }
  }
}

int main() {
  vector<vector<pair<int, int>>> graph {
    {{1, 4}, {2, 1}}, // 0
    {{0, 4}, {2, 2}, {3, 5}}, // 1
    {{0, 1}, {1, 2}, {3, 8}}, // 2
    {{1, 5}, {2, 8}} // 3
  };

  vector<int> dist(graph.size(), INT_MAX);

  dijkstra(0, graph, dist);

  cout << "Dijkstra" << "\n";
  for(int i = 0; i < dist.size(); i++) {
    cout << "Distance from 0 to " << i << " is " << dist[i] << "\n";
  }

  dijkstra_with_priority_queue(0, graph, dist);

  cout << "Dijkstra with priority queue" << "\n";
  for(int i = 0; i < dist.size(); i++) {
    cout << "Distance from 0 to " << i << " is " << dist[i] << "\n";
  }

  return 0;
}