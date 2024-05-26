#pragma once
#include "i_graph.hpp"
#include <vector>

class ListGraph : public IGraph {
public:
  ListGraph(int size);
  ListGraph(const IGraph& graph);
  ~ListGraph() {}

  // IGraph
  virtual void AddEdge(int from, int to) override;
  virtual int VerticesCount() const override;
  virtual std::vector<int> GetNextVertices(int vertex) const override;
  virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
  std::vector<std::vector<int>> adjacencyLists;
};
