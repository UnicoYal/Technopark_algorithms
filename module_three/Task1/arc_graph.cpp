#include "arc_graph.hpp"
#include "i_graph.hpp"
#include <cassert>
#include <vector>

ArcGraph::ArcGraph(int size) {
  edges.reserve(size);
}

ArcGraph::ArcGraph(const IGraph &graph) {
  edges.reserve(graph.VerticesCount());

  int vertexCount = graph.VerticesCount();
  edges.reserve(vertexCount);

  for (int i = 0; i < vertexCount; ++i) {
    std::vector<int> nextVertices = graph.GetNextVertices(i);
    for (int j : nextVertices) {
      edges.emplace_back(i, j);
    }
  }
}

void ArcGraph::AddEdge(int from, int to) {
  assert(0 <= from && from < edges.size());
  assert(0 <= to && to < edges.size());
  edges.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
  int maxVertexIndex = -1;
  for (const auto& edge : edges) {
    maxVertexIndex = std::max(maxVertexIndex, std::max(edge.first, edge.second));
  }
  return maxVertexIndex + 1;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const
{
  std::vector<int> nextVertices;
  for (const auto& edge : edges) {
    if (edge.first == vertex) {
      nextVertices.push_back(edge.second);
    }
  }
  return nextVertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const
{
  std::vector<int> prevVertices;
  for (const auto& edge : edges) {
    if (edge.second == vertex) {
      prevVertices.push_back(edge.first);
    }
  }
  return prevVertices;
}
