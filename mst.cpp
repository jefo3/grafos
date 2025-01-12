#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
  int startVertex, endVertex, weight;
  
  //sobreescrita do operador < para que a função sort possa ordenar os objetos da classe Edge
  bool operator<(const Edge& other) const {
    return weight < other.weight;
  }
};

class UnionFind {
  private:
    vector<int> parent, rank;
  
  public:
    UnionFind(int size) {
      parent.resize(size);
      rank.resize(size, 0);

      for (int i = 0; i < size; i++) {
        parent[i] = i;
      }
    }

    int find(int u) {
      if (parent[u] != u) {
        return parent[u] = find(parent[u]);
      }
      
      return parent[u];

    }

    void unite(int x, int y) {
      int root_x = find(x);
      int root_y = find(y);

      if (root_x == root_y) {
        return;
      }

      if(rank[root_x] > rank[root_y]) {
        parent[root_y] = root_x;
      } else if(rank[root_x] < rank[root_y]) {
        parent[root_x] = root_y;
      } else {
        parent[root_y] = root_x;
        rank[root_x]++;
      }

    }
};

class Kruskal {
  private:
    int vertices;
    vector<Edge> edges;

  public:
    Kruskal(int vertices) : vertices(vertices) {}

    Kruskal(vector<Edge> edges, int vertices) {
      this->edges = edges;
      this->vertices = vertices;
    }

    Kruskal(vector<Edge> edges) {
      this->edges = edges;
      this->vertices = 0;

      for(const Edge& edge: edges) {
        this->vertices = max(this->vertices, max(edge.startVertex, edge.endVertex) + 1);
      }
    }

    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    void find_mst() {
      sort(edges.begin(), edges.end());

      UnionFind uf(vertices);
      vector<Edge> mst;
      int totalWeight = 0;

      for(const Edge& edge: edges) {
        if(uf.find(edge.startVertex) != uf.find(edge.endVertex)) {
          uf.unite(edge.startVertex, edge.endVertex);
          mst.push_back(edge);
          totalWeight += edge.weight;
        }
      }

      cout << "Árvore Geradora Mínima:\n";
      for (const Edge& edge : mst) {
          cout << edge.startVertex << " - " << edge.endVertex << " (peso: " << edge.weight << ")\n";
      }
      cout << "Peso total: " << totalWeight << endl;
    }
};

int main() {
  int vertices = 4;
  vector<Edge> edges = {
    {0, 1, 1},
    {1, 2, 2},
    {0, 2, 2},
    {2, 3, 3},
    {1, 3, 4}
  };

  Kruskal kruskal(edges, vertices);

  kruskal.find_mst();

  return 0;
}