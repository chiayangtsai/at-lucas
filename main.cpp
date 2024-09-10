#include "includes.h"
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int testID = 6;

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
  case 5:
    leetcode_shuffle_lists_ii();
    break;
  case 6:
    leetcode_revert_integer();
    break;
  case 7: // pointer, reference
    basic_pointer_reference();
    break;
  default:
    printf("not a supported test ID : %d\n", testID);
    exit(-1);
  }

  return 0;
}

#define ENABLE_SHUFFLE_OLD_CODE 0

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

#if ENABLE_SHUFFLE_OLD_CODE
  int ind = 0;
  int count = 1;
  while (ind < 10) {
    if (ind % 2 == 0) {
      c[ind] = a[ind / 2];
      ind += 1;
      count += 1;
    } else if (ind % 2 != 0 && count == 2) {
      c[ind] = b[0];
    } else {
      c[ind] = b[ind / 2 + 1];
      ind += 1;
    }
  }
#else
  int ind = 0;
  while (ind < arraySize * 2) {
    // grab a
    c[ind] = a[ind / 2];
    ind++;

    // grab b
    c[ind] = b[ind / 2];
    ind++;
  }
#endif
  printf("results c=");
  for (int i = 0; i < arraySize * 2; i++) {
    printf("%d ", c[i]);
  }
  printf("\n");
}

void shuffle_two_lists(int a[], int aSize, int b[], int bSize, int c[]) {
  // define index
  // while ...
  // if ..index > aSize
  //   grab from a
  // if ..index > bSize
  //   grab from b

  int ind = 0;
  int ia = 0;
  int ib = 0;
  while (ind < aSize + bSize) // satisfied condition = ~ (break condition)
  {

    // general case
    if (ia < aSize) {
      c[ind] = a[ia];
      ia++;
      ind++;
    }

    if (ib < bSize) {
      c[ind] = b[ib];
      ib++;
      ind++;
    }

    // break condition
    //  if(ind == aSize + bSize){
    //    break;
    //  }
  }
}

void leetcode_shuffle_lists_ii() {

  int a[7] = {2, 5, 3, 8, 1, 7, 9};
  int aSize = 7;
  int b[5] = {6, 1, 8, 4, 0};
  int bSize = 5;

  int c[12];
  // Q : shuffle elements in "a" and "b" to "c" following index order
  //                expected results
  //                c= {2, 6, 5, 1, 3, 8, 8, 4, 1, 0, 7, 9}
  //

  // grab a
  // grab b
  shuffle_two_lists(a, aSize, b, bSize, c);

  printf("results c=");
  for (int i = 0; i < (aSize + bSize); i++) {
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
  {
    int a = 5; // only valid within the { } scope
    // int : 4 bytes = 32 bits

    // pointer: memory address of a variable / key to the drawer

    // call-by-value
    int b = 3;
    int c = addAB(a, b);
  }
  // pointer : memory address of a memory
  {
    int a = 10; // &a : memory address of a
    int *key = &a;

    *key = 5;
    printf("a= %d\n", a);

    int data[5] = {3, 2, 6, 1, 8};
    //            ^   ^
    //          data  data+1
    //   data ===  &(data[0])     <== definition
    printf("index-0 value = %d\n", data[0]);
    printf("index-1 value = %d\n", *(data + 1));

    for (int i = 0; i < 5; i++) {
      printf("%d ", *(data + i)); // *(data+i) == data[i]
    }
    printf("\n");
  }
  ///

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
  for (int i = 0; i < dataSize; i++){
    printf("%d ", data[i]);
  }
  printf("\n");
}

int revertInteger(int num) {
  //separate digits from each other
  //save individual digits into an array
  //print the array in reverse
  int digits = log10(num)+1;
  int powerof = 0;
  int c[digits];
  for(int i = 0; i < digits; i++){
    powerof = pow(10, i+1);
    c[i] = (num % powerof)/pow(10, i);
    num = num - (c[i]*pow(10, i));
  }
  int output = 0;
  for(int r = 0; r < digits; r++){
    output = output*10 + c[r];
  }
  return output;
  // HW0907
  //2024.9.9: code can execute without returning errors
}

int revertIntegerNoLogPow(int num) {
  
  //HW0907 : don't use log and pow
  return -1; //please modify it
}

void leetcode_revert_integer() {
  // https://zerojudge.tw/ShowProblem?problemid=a038

  printf("--- version 0 -- use log ---\n");
  int num = 12345;
  num = revertInteger(num);
  printf("reverted number = %d (ans : 54321)\n", num);

  printf("--- version 1 -- don't use log and pow---\n");
  num = 12345;
  num = revertIntegerNoLogPow(num);
  printf("reverted number = %d (ans : 54321)\n", num);

  
}
