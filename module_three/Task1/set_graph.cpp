#include "set_graph.hpp"
#include "i_graph.hpp"
#include <cassert>
#include <vector>
#include <unordered_set>
#include <set>

SetGraph::SetGraph(int size) {
  adjacencySets.resize(size);
}

SetGraph::SetGraph(const IGraph &graph) {
  adjacencySets.resize(graph.VerticesCount());

  for (int from = 0; from < graph.VerticesCount(); ++from) {
    std::vector<int> nextVertices = graph.GetNextVertices(from);
    for (int to : nextVertices) {
      adjacencySets[from].insert(to);
    }
  }
}

void SetGraph::AddEdge(int from, int to) {
  assert(0 <= from && from < adjacencySets.size());
  assert(0 <= to && to < adjacencySets.size());
  adjacencySets[from].insert(to);
}

int SetGraph::VerticesCount() const {
  return (int)adjacencySets.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
  int vertexCount = VerticesCount();
  assert(vertex >= 0 && vertex < vertexCount);

  std::vector<int> nextVertices;
  for (int v : adjacencySets[vertex]) {
    nextVertices.push_back(v);
  }

  return nextVertices;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
  assert(0 <= vertex && vertex < adjacencySets.size());
  std::vector<int> prevVertices;

  for (int from = 0; from < adjacencySets.size(); ++from) {
    for (int to: adjacencySets[from]) {
      if (to == vertex)
        prevVertices.push_back(from);
    }
  }
  return prevVertices;
}
