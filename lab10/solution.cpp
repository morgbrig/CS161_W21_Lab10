
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>

using namespace std;


int get_memory_usage_kb (long *vmrss_kb, long *vmsize_kb);							


// int add (int* &nums, int i) {

//   if (i == 0) {

//     return nums[0];

//   } else {

//     return nums[i] + add(nums, i - 1);
//   }
// }


short int* runningSum (short int *nums, short int size) {
  
  short int *a = new short int[size];
  short int prev = 0;
  
  for (short int i = 0; i < size; i++) {
    
    a[i] = nums[i] + prev;
    prev = a[i];
  }
  
  return a;
}


void print_arr (short int *nums, short int size) {
  
  for (int i = 0; i < size; i++) {
    
    cout << nums[i] << " ";
    
  }
  
  cout << "\n";
}


int main (int argc, char const *argv[]) {
  
  //variables for memory calculation
  long vmrss, vmsize;
  
  short int arr1[4] = {1,2,3,4};
  short int arr2[5] = {1,1,1,1,1};
  short int arr3[5] = {3,1,2,10,1};
  
  //get time stamp before testing
  auto start = chrono::high_resolution_clock::now(); 
  
  short int *num1 = runningSum(arr1,4);
  short int *num2 = runningSum(arr2,5);
  short int *num3 = runningSum(arr3,5);
  
  //get time stamp after testing
  auto end = chrono::high_resolution_clock::now(); 
  
  cout << "\nTest 1...\nExpected: 1 3 6 10\nActual: ";
  print_arr(num1, 4);
  
  cout << "\nTest 2...\nExpected: 1 2 3 4 5\nActual: ";
  print_arr(num2, 5);
  
  cout << "\nTest 3...\nExpected: 3 4 6 16 17\nActual: ";
  print_arr(num3, 5);

  //calculate and print time taken
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count() * 1e-9; 
  
  cout << "\nTime taken by program is: " << fixed << time_taken << setprecision(9) << " sec\n"; 
  
  //  calculate total memory usage
  get_memory_usage_kb(&vmrss, &vmsize);
  printf("Current memory usage: VmRSS = %6ld KB, VmSize = %6ld KB\n", vmrss, vmsize);
  
  delete [] num1;
  num1 = NULL;
  delete [] num2;
  num2 = NULL;
  delete [] num3;
  num3 = NULL;
  
  return 0;
}
