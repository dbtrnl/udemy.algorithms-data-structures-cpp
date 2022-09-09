#include <iostream>
#include <vector>
#include "GraphColoring.h"
using std::vector;

int main(int argc, const char * argv[]) {
  /* 
    First array is first node. It is connected to second and fourth nodes.
    Seconr node is connected to first, third and fourth, and so on and so on...
   */
  const vector<vector<int>> graphMatrix = {
    {0,1,0,1,0},
    {1,0,1,1,0},
    {0,1,0,1,0},
    {1,1,1,0,1},
    {0,0,0,1,0},
  };

  constexpr int numOfColors = 3;

  GraphColoring graphColoring(graphMatrix, numOfColors);
  graphColoring();

  return 0;
}