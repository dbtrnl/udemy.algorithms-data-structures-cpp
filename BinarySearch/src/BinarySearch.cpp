#include <iostream>

using namespace std;

int binarySearch(int nums[], int low, int high, int num) {
  if (low > high) return -1;
  int middle = low + (high-low)/2;
  if(nums[middle] == num) return middle;
  if(num < nums[middle]) {
    return binarySearch(nums, low, middle-1, num);
  } else {
    return binarySearch(nums, middle + 1, high, num);
  }
}

int main() {
  int nums[] = {1,2,3,4,5,10,15,20,30,40,50,60,70};
  int desiredNum = 60;
  int n = sizeof(nums)/sizeof(nums[0]);

  cout << "Index of number " << desiredNum << " is: " << binarySearch(nums, 0, n-1, desiredNum) << endl;
  return 0;
}