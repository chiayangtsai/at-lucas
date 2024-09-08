#include "includes.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  int testID = 2;

  switch (testID) {
  case 0:
    cout << "hello world!" << endl;
    break;
  case 1: // sort : bubble sort
    leetcode_bubble_sort();
    break;
  case 2:
    leetcode_bubble_sort_descending();
    break;
  case 3:
    leetcode_shuffle_lists();
    break;
  case 5: // pointer, reference
    basic_pointer_reference();
    break;
  default:
    printf("not a supported test ID : %d\n", testID);
    exit(-1);
  }

  return 0;
}

void leetcode_shuffle_lists() {

  int arraySize = 5;
  int a[5] = {2, 5, 3, 8, 1};
  int b[5] = {6, 1, 8, 4, 0};
  int c[10];
  // Q : shuffle elements in "a" and "b" to "c" following index order
  //   For exmaple: if a= {2, 5, 3, 8, 1} and b= {6, 1, 8, 4, 0}
  //                expected results
  //                c= {2, 6, 5, 1, 3, 8, 8, 4, 1, 0}
  //

  // HW0904 (optional)

  printf("results c=");
  for (int i = 0; i < arraySize * 2; i++) {
    printf("%d ", c[i]);
  }
  printf("\n");
}

void leetcode_bubble_sort() {

  // swap a and b
  int a = 6;
  int b = 2;
  printf("before swap: a= %d, b=%d\n", a, b);
  // int b1 = b;
  // b = a;
  // a = b1;
  // naming (not official) : buffer, buf, temp, tmp
  int tmp = a; // step 1: beffer the overrided variable
  a = b;       // step 0: don't care
  b = tmp;     // step 2 : get the buffered value

  printf("after swap: a= %d, b=%d\n", a, b);

  int in[7] = {5, 1, 0, 9, 3, 7, 2};
  int inSize = 7;
  printf("original: ");
  for (int i = 0; i < inSize; i++)
    printf("%d ", in[i]);
  printf("\n");

  // Q: shift the max value to the last position
  //{5, 1, 0, 9, 3, 7, 2}
  //  ^^^^ 0th compare - index 0-1
  //  1, 5, 0, 9, 3, 7, 2
  //     ^^^^ 1st compare - index 1-2
  //  1, 0, 5, 9, 3, 7, 2
  //        ^^^^ 2nd compare - index 2-3
  //
  for (int comp = 0; comp < inSize - 1; comp++) {
    if (in[comp] > in[comp + 1]) {
      // swap
      int buf = in[comp];
      in[comp] = in[comp + 1];
      in[comp + 1] = buf;
    }
  }
  printf("shift max to the last position: ");
  for (int i = 0; i < inSize; i++)
    printf("%d ", in[i]);
  printf("\n");

  // ascending sort (由小排到大- 左邊是小, 右邊是大)
  for (int j = inSize; j > 1; j--) {           // j: data size
    for (int comp = 0; comp < j - 1; comp++) { // comp: number of comparison
      if (in[comp] > in[comp + 1]) {
        // swap
        int buf = in[comp];
        in[comp] = in[comp + 1];
        in[comp + 1] = buf;
      }
    }
  }

  printf("bubble sort: ");
  for (int i = 0; i < inSize; i++)
    printf("%d ", in[i]);
  printf("\n");
}

int addAB(int a, int b) {
  int x = a + b;
  return x;
}

void basic_pointer_reference() {
  int a = 5; // only valid within the { } scope
  // int : 4 bytes = 32 bits

  // pointer: memory address of a variable / key to the drawer

  // call-by-value
  int b = 3;
  int c = addAB(a, b);

  // call-by-reference
}

void leetcode_bubble_sort_descending() {
  int data[10] = {5, 2, 9, 1, 0, 3, 5, 10, 4, 2};
  int dataSize = 10;

  // Q : descending sort for data

  // HW0904
  for (int l = dataSize; l > 1; l--) {
    for (int n = 0; n < l - 1; n++) {
      if (data[n] < data[n + 1]) {
        int buf = data[n];
        data[n] = data[n + 1];
        data[n + 1] = buf;
      }
    }
  }
  printf("bubble sort: ");
  for (int i = 0; i < dataSize; i++)
    printf("%d ", data[i]);
  printf("\n");
}