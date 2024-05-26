#include <iostream>
#include <queue>
#include <vector>
#include <functional>

#include "i_graph.hpp"
#include "list_graph.hpp"
#include "matrix_graph.hpp"
#include "set_graph.hpp"
#include "arc_graph.hpp"


void BFS(const IGraph& graph, int vertex, std::vector<bool> &visited, std::function<void(const int)> visit)
{
  std::queue<int> bfsQueue;
  bfsQueue.push(vertex);
  visited[vertex] = true;

  while (!bfsQueue.empty()) {
    int current = bfsQueue.front();
    bfsQueue.pop();
    visit(current);
    for (int nextVertex: graph.GetNextVertices(current)) {
      if (!visited[nextVertex]) {
        visited[nextVertex] = true;
        bfsQueue.push(nextVertex);
      }
    }
  }
}

void mainBFS(const IGraph &graph, const std::function<void(int)> &func)
{
  std::vector<bool> visited(graph.VerticesCount(), false);

  for (int i = 0; i < graph.VerticesCount(); ++i) {
    if (!visited[i]) {
      BFS(graph, i, visited, func);
    }
  }
}

void DFS(const IGraph &graph, int vertex, std::vector<bool> &visited, const std::function<void(int)> &visit)
{
  visited[vertex] = true;
  visit(vertex);

  for (int nextVertex: graph.GetNextVertices(vertex)) {
    if (!visited[nextVertex]) {
      DFS(graph, nextVertex, visited, visit);
    }
  }
}

void mainDFS(const IGraph &graph, const std::function<void(int)> &func)
{
  std::vector<bool> visited(graph.VerticesCount(), false);

  for (int i = 0; i < graph.VerticesCount(); ++i) {
    if (!visited[i]) {
      DFS(graph, i, visited, func);
    }
  }
}

int main() {
    ListGraph listGraph(7);

    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 5);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 5);
    listGraph.AddEdge(1, 6);
    listGraph.AddEdge(3, 2);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(5, 4);
    listGraph.AddEdge(5, 6);
    listGraph.AddEdge(6, 4);

    std::cout << "DFS ListGraph: ";
    mainDFS(listGraph, [](int v) { std::cout << v << " "; });
    std::cout << std::endl;

    std::cout << "BFS ListGraph: ";
    mainBFS(listGraph, [](int v) { std::cout << v << " "; });
    std::cout << std::endl;

    MatrixGraph matrixGraph(listGraph);

    std::cout << "DFS MatrixGraph: ";
    mainDFS(matrixGraph, [](int v) { std::cout << v << " "; });
    std::cout << std::endl;

    std::cout << "BFS MatrixGraph: ";
    mainBFS(matrixGraph, [](int v) { std::cout << v << " "; });
    std::cout << std::endl;

    ArcGraph arcGraph(matrixGraph);

    std::cout << "DFS ArcGraph: ";
    mainDFS(arcGraph, [](int v) { std::cout << v << " "; });
    std::cout << std::endl;

    std::cout << "BFS ArcGraph: ";
    mainBFS(arcGraph, [](int v) { std::cout << v << " "; });
    std::cout << std::endl;

    SetGraph setGraph(arcGraph);

    std::cout << "DFS SetGraph: ";
    mainDFS(setGraph, [](int v) { std::cout << v << " "; });
    std::cout << std::endl;

    std::cout << "BFS SetGraph: ";
    mainBFS(setGraph, [](int v) { std::cout << v << " "; });
    std::cout << std::endl;

    std::cout << "OK" << std::endl;
}
