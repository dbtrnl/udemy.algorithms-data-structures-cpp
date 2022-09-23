#include <iostream>
using namespace std;

int main() {
  const int SIZE = 10;

  // Size can't be changed
  int nums[SIZE] = {1,2,3,4,5,6,7,8,9,10};

  // O(1)
  cout << nums[2] << "\n";

  // Update and print number again = O(1)
  nums[2] = 100;
  cout << nums[2] << "\n";

  // O(n) > linear search until the desired value is found. One of the main disadvantages of Arrays
  for(int i=0; i<SIZE-1; i++) {
    if (nums[i] == 8) cout << "Index of the item we are looking for is " << i << "\n";
  }

  // Remove item:
  nums[2] = 0;
  // Iterating to shift items
  for (int i=2; i<SIZE-1; i++) nums[i] = nums[i+1];
  nums[SIZE-1] = 0;

  // Printing items
  for (int i=0; i<SIZE-1; i++) cout << nums[i] << "\n";

  return 0;
}