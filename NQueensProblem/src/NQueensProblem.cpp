#include "NQueensProblem.h"
#include <iostream>
using std::cout;

QueensProblem::QueensProblem(int _numOfQueens)
  : numOfQueens(_numOfQueens)
{
  chessTable.resize(numOfQueens);
  for (auto &chessRow : chessTable)
    chessRow.resize(numOfQueens);
}

void QueensProblem::solve() {
  if (setQueens(0)) printQueens();
  else cout << "There is no solution...\n";
}

bool QueensProblem::setQueens(int colIndex) {
  // If as many queens as the number of Row/Col have been considered, problem is done
  if (colIndex == numOfQueens) {
    return true;
  }

  // consider all the rows in a single column to find where to put the queen
  for (int rowIndex = 0; rowIndex < numOfQueens; ++rowIndex) {
    // If current queen position is valid, set a queen on that square
    if (isPlaceValid(rowIndex, colIndex)) {
      chessTable[rowIndex][colIndex] = 1;
      if (setQueens(colIndex + 1)) return true;
      // If no valid positions are found, BACKTRACK
      chessTable[rowIndex][colIndex] = 0;
    }
  }
  // Backtracking the location of the first queen, incrementing the row
  return false;
}

bool QueensProblem::isPlaceValid(int rowIndex, int colIndex) const {
  for (int i = 0; i < colIndex; i++) {
    // If there's another queen in the same row
    if (chessTable[rowIndex][i] == 1) return false;
  }

  // If there's another queen in the diagonal (top left to bottom right)
  for (int i = rowIndex, j = colIndex; i >= 0 && j >= 0; i--, j--) {
    if(chessTable[i][j] == 1) return false;
  }

  // If there's another queen in the diagonal (top right to bottom left)
  for (int i = rowIndex, j = colIndex; i > numOfQueens && j >= 0; i++, j--) {
    if(chessTable[i][j] == 1) return false;
  }
  return true;
}

void QueensProblem::printQueens() const {
  // There is a queen where the table contains a 1 else there is no queens (0 value)
  // * represents the queens and - is an empty square
  for (size_t i = 0; i < chessTable.size(); i++) {
    for (size_t j = 0; j < chessTable.size(); j++) {
      if (chessTable[i][j] == 1) cout << " * ";
      else cout << " - ";
    }
    cout << '\n';
  }
}