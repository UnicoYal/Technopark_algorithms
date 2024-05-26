#pragma once
#include "i_graph.hpp"
#include <vector>

class MatrixGraph : public IGraph {
public:
  MatrixGraph(int size);
  MatrixGraph(const IGraph& graph);
  ~MatrixGraph() {}

  // IGraph
  virtual void AddEdge(int from, int to) override;
  virtual int VerticesCount() const override;
  virtual std::vector<int> GetNextVertices(int vertex) const override;
  virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
  int graphSize;
  std::vector<std::vector<bool>> adjacencyMatrix;
};
