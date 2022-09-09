#include "GraphColoring.h"
#include <iostream>
using namespace std;

GraphColoring::GraphColoring(const vector<vector<int>> &graph, int _numOfColors): graphMatrix(graph), numOfColors(_numOfColors) {
  colors.resize(graphMatrix.size());
}

void GraphColoring::operator()() {
  if (solve(0)) showResult();
  else cout << "No solution with the given parameters...\n";
}

bool GraphColoring::solve(size_t nodeIndex) {
  // If all nodes have been considered, solve() is done.
  if (nodeIndex == graphMatrix.size()) return true;

  // Loop to try all colors
  for (int colorIndex = 1; colorIndex <= numOfColors; colorIndex++) {
    if (isColorValid(nodeIndex, colorIndex)) {
      colors[nodeIndex] = colorIndex;
      // Recursion related to backtracking begins here.
      if (solve(nodeIndex+1)) return true;
    }
  }
  /*
    All colors have been considered in the loop.
    If code reaches this point, it will backtrack.
    If all recursions are done, then the problem has no solution.
  */
  return false;
}

bool GraphColoring::isColorValid(size_t nodeIndex, size_t colorIndex) {
  for (size_t i = 0; i < graphMatrix.size(); i++) {
    if (graphMatrix[nodeIndex][i] == 1 && colorIndex == colors[i]) return false;
  }
  return true;
}

void GraphColoring::showResult() {
  for (size_t i = 0; i < graphMatrix.size(); i++) {
    cout << "Node " << (i+1) << " has color index: " << colors[i] << "\n";
  }
  cout << '\n';
}