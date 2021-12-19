#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void addEdge(vector<int>* graph, int a, int b) {
  graph[a].push_back(b);
  graph[b].push_back(a);
}
void bfs(vector<int>* graph, int n) {
  vector<bool> visited(n, false);
  queue<int> _queue;
  _queue.push(0);
  visited[0] = true;
  while (!_queue.empty()) {
    int u = _queue.front();
    _queue.pop();
    cout << u << endl;
    for (const auto& v : graph[u]) {
      if (!visited[v]) {
        _queue.push(v);
        visited[v] = true;
      }
    }
  }
}
void dfs(vector<int>* graph, int n) {
  vector<bool> visited(n, false);
  stack<int> _stack;
  _stack.push(0);
  visited[0] = true;
  while (!_stack.empty()) {
    int u = _stack.top();
    _stack.pop();
    cout << u << endl;
    for (const auto& v : graph[u]) {
      if (!visited[v]) {
        _stack.push(v);
        visited[v] = true;
      }
    }
  }
}
int main() {
  int n = 6;

  vector<int>* graph;

  graph = new vector<int>[n];
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 3, 4);
  addEdge(graph, 2, 5);
  addEdge(graph, 2, 3);

  bfs(graph, n);
  cout << "*****" << endl;
  dfs(graph, n);
}
