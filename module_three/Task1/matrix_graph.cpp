#include "matrix_graph.hpp"
#include "i_graph.hpp"
#include <cassert>
#include <vector>

MatrixGraph::MatrixGraph(int size) {
  graphSize = size;
  adjacencyMatrix.resize(size, std::vector<bool>(size, false));
}

MatrixGraph::MatrixGraph(const IGraph &graph) {
  int vertexCount = graph.VerticesCount();
  adjacencyMatrix.resize(vertexCount, std::vector<bool>(vertexCount, false));

  for (int i = 0; i < vertexCount; ++i) {
    std::vector<int> nextVertices = graph.GetNextVertices(i);
    for (int j : nextVertices) {
      adjacencyMatrix[i][j] = true;
    }
  }
}

int MatrixGraph::VerticesCount() const {
  return (int)adjacencyMatrix.size();
}

void MatrixGraph::AddEdge(int from, int to) {
  assert(0 <= from && from < VerticesCount());
  assert(0 <= to && to < VerticesCount());
  adjacencyMatrix[from][to] = true;
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
  assert(0 <= vertex && vertex < VerticesCount());
  std::vector<bool> currentRow = adjacencyMatrix[vertex];
  int vertexCount = VerticesCount();

  std::vector<int> nextVertices;
    for (int i = 0; i < vertexCount; ++i) {
      if (currentRow[i]) {
        nextVertices.push_back(i);
      }
    }

  return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
  int vertexCount = VerticesCount();
  assert(vertex >= 0 && vertex < vertexCount);

  std::vector<int> prevVertices;
  for (int i = 0; i < vertexCount; ++i) {
    if (adjacencyMatrix[i][vertex]) {
      prevVertices.push_back(i);
    }
  }

  return prevVertices;
}
