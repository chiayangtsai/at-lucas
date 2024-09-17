#include "includes.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int testID = 10;

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
  case 8: // vector
    basic_vector_usage();
    break;
  case 9:
    leetcode_shuffle_lists_iii();
    break;
  case 10:
    leetcode_two_sum();
    break;
  case 11:
    leetcode_fibonacci_seq();
    break;
  case 12:
    leetcode_even_odd_diff();
    break;
  case 14:
    leetcode_merge_sorted_lists();
    break;
  case 15: // string
    basic_string_usage();
    break;
  case 16:
    leetcode_letters_histogram();
    break;
  case 17: // struct, class, object
    basic_class_struct();
    break;
  default:
    printf("not a supported test ID : %d\n", testID);
    exit(-1);
  }

  // string
  // struct
  // cin, cout
  //

  return 0;
}

void basic_class_struct() {}
void leetcode_letters_histogram() {}

void leetcode_merge_sorted_lists() {}

void basic_string_usage() {
  // C-style usage & ASCII codes

  // C++ style usage

  // iterations
}

void basic_vector_usage() {
  // static memory
  { int a[5] = {4, 3, 5, 2, 1}; }
  // dynamic memory
  {
      // TBV
  } // vector
  {
    vector<int> a({4, 1, 2});

    a = {4, 3, 5, 2, 1};

    for (int i = 0; i < a.size(); i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
  }
  // push_back
  {
    vector<int> a({4, 1, 2});
    a.push_back(3);
    for (int i = 0; i < a.size(); i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
  }
  // TBV
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

void shuffle_two_lists(int *a, int aSize, int *b, int bSize, int *c) {
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

void leetcode_shuffle_lists_iii() {
  /*
  vector<int> a({2, 5, 3, 8, 1});
  vector<int> b({0, 1, 2});
  vector<int> c({4, 7, 1, 9, 0, 5});
  vector<int> d;

  //Q: shuffle a, b, c, following index order. Results will be in d.
  //.  expected results :
  //.  d= {2, 0, 4, 5, 1, 7, 3, 2, 1, 8, 9, 1, 0, 5}
*/
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

void addABPointer(int x, int y, int *z) { *z = x + y; }

void addABReference(int x, int y,
                    int &z) { //如果寫z 並沒有連動到c; but int& z是reference
                              //變動z的值也會同時改變c的值
  z = x + y;
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
      //*(data + i) = 0;
    }
    printf("\n");

    a = 5;
    int b = 3;
    int c = -1;
    std::cout << "a=" << a << " b=" << b << " c=" << c << std::endl;
    addABPointer(a, b, &c); // call-by-reference
    std::cout << "a=" << a << " b=" << b << " c=" << c << std::endl;
  }
  ///

  // reference : reference / memory
  {
    int a = 5;
    int b = 3;
    int c = -1;
    std::cout << "a=" << a << " b=" << b << " c=" << c << std::endl;
    addABReference(a, b, c); // call-by-reference
    std::cout << "a=" << a << " b=" << b << " c=" << c << std::endl;

    // int& r; (X)
    int &r = a; //(O)
  }
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
  for (int i = 0; i < dataSize; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");
}

int revertInteger(int num) {
  // separate digits from each other
  // save individual digits into an array
  // print the array in reverse
  int digits = log10(num) + 1;
  int powerof = 0;
  int c[digits];
  for (int i = 0; i < digits; i++) {
    powerof = pow(10, i + 1);
    c[i] = (num % powerof) / pow(10, i);
    num = num - (c[i] * pow(10, i));
  }
  int output = 0;
  for (int r = 0; r < digits; r++) {
    output = output * 10 + c[r];
  }
  return output;
  // HW0907
  // 2024.9.9: code can execute without returning errors
}

int revertIntegerNoLogPow(int num) {

  //任何正的小數 float a = 1.2;
  //做四捨五入 :   a = 1.2 => 1
  //             a = 1.6 ==> 2
  //         int b = (int)(a+0.5)

  // HW0907 : don't use log and pow

  int revert = 0;
  while (num) {

    // general
    //  get digit => num %10
    //  num = num /10
    //  revert = revert *10 + digit
    revert = revert * 10 + (num % 10);
    num /= 10;
    // ending condition
    // if num == 0 => break;
    // if(num == 0) break;
  }

  return revert;
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

void funcTwoSum(int *data, int dataSize, int sum) {
  // please print out the pairs for targetSum
  // HW0911
  // HW0915
  // bubble sort
  vector<int> pairs{};
  for (int i = 0; i < dataSize - 1; i++) {
    /*
    i = 0; data[0] = 5; compare following pairs: (5,1) (5,6) (5,3)...(5,5)
    i = 1; data[1] = 1; compare: (1,6) (1,3) (1,9)...(1,5)
    i = 2; data[2] = 6; compare: (6,3) (6,9) (6,4)...(6,5)
    ...i = 5
    */
    for (int j = 1; j < dataSize; j++) {
      if (data[i] + data[j] ==
          sum) { // checks if the sum of an item with any of the other items is
                 // equal to the given "sum" value
        // i = 0; checks (5,1)
        // i = 1; checks (1)
        pairs.push_back(data[i]);
        pairs.push_back(data[j]);
      }
    }
  }
  for (int k = 0; k < (pairs.size()) / 2; k += 2) {
    cout << "(" << pairs[k] << ", " << pairs[k + 1] << ")" << endl;
  }
}

void leetcode_two_sum() {
  int data[9] = {5, 1, 6, 3, 9, 4, 3, 6, 5};
  int dataSize = 9;
  int sum = 10;

  // Q: print out the pair with sum = 10
  //    expected results : (5, 5), (1, 9), (6, 4), (4, 6)
  //
  //    NOTE: integer k range  0<= k <= 99
  funcTwoSum(data, dataSize, sum);
}

// f(n)= n+2 : O(N)
// f(n) = n^2 : O(N^2)

int getFibSeq(int k) {
  // HW0911
  int i1 = 0;
  int i2 = 1;
  int n;
  if (k == 0) {
    return i1;
  } else {
    for (int i = 2; i <= k; i++) {
      n = i1 + i2;
      i1 = i2;
      i2 = n;
    }
  }
  return i2;
}
void leetcode_fibonacci_seq() {

  // Fibonacci (費氏函數)
  // Formula : X(n) = X(n-1) + X(n-2)
  //           X(0) = 0, X(1) = 1
  //  {0,   1,   1,    2, 3, 5, 8, 13....}
  //  X(0) X(1) X(2)  X(3) ........ X(N-1)
  //
  //
  //  Q: Given k, derive X(k)
  //.    For example : X(0) = 0, when k=0
  //.                  X(2) = 1, when k=2
  //                   X(4) = 3, when k=4
  // time complexity : O(N)

  // O(N^2)
  //  for()
  //    for()
  int k = 10;
  // O(N)
  int Xk = getFibSeq(k);

  printf("X%d= %d\n", k, Xk);
}

int funcEvenOddDiff(int x) {
  /*
  int k;
  if(x > 0) k = 1;
  else k = 2;

  //C style
  k = (x>0) ? 1 : 2;

  //python: k= 1 if x> 0 else 2
  */
  enum _IMPLT_ID {
    IMPLT_ORIG = 0, // original homework implementation
    IMPLT_FIRST,    // 1st improved version
    IMPLT_SECOND,
  };

  int flag = IMPLT_FIRST;
  int res;

  if (flag == IMPLT_ORIG) {
    // HW0911: don't use any built-in function
    //      for example : abs(x) => |x|
    int evensum = 0;
    int oddsum = 0;
    int count = 0;
    int xreverse = 0;
    while (x) {
      xreverse = xreverse * 10 + (x % 10);
      x /= 10;
      count += 1;
    }
    // static  :  靜態宣告
    int digits[count]; //? memory management may have "memory violation" problem

    count = 0;
    while (xreverse) {
      digits[count] = xreverse % 10;
      xreverse /= 10;
      count += 1;
    }
    for (int i = 0; i < count; i++) {
      if (i % 2 == 0) {
        evensum += digits[i];
      } else {
        oddsum += digits[i];
      }
    }
    res = oddsum - evensum;
  } else if (flag == IMPLT_FIRST) {
    /*
       12345 => 5 odd
       1234 => 4 even
       123 =>3 odd
       12 =>2 even
       1 =>1 odd
    */
    int evensum = 0;
    int oddsum = 0;
    int count = 0;
    while (x) {
      // get the digit
      int digit = (x % 10);

      if (count % 2)
        evensum += digit;
      else
        oddsum += digit;

      // shift out the digit from x
      x /= 10;
    }

    int diff = oddsum - evensum;

    res = (diff > 0) ? diff : (-diff);

  } else if (flag == IMPLT_SECOND) // 2nd improved version
  {
    // (a0+ a2 + a4) - (a1+a3+a5) = diff
    // (a0-a1) + (a2- a3) + (a4- a5) = diff
    int diff = 0;
    while (x) {
      diff += (x % 10);
      x /= 10;

      diff -= (x % 10);
      x /= 10;
    }
    res = (diff > 0) ? diff : (-diff);

  } else {
    printf("wrong flag value: %d\n", flag);
    exit(-1);
  }
  return res;
}

void leetcode_even_odd_diff() {
  // from zero judge - APCS
  // https://zerojudge.tw/ShowProblem?problemid=c290
  /*
  將一個十進位正整數的奇數位數的和稱為A ，偶數位數的和稱為B，則A與B的絕對差值 |A
  －B| 稱為這個正整數的秘密差。

  例如： 263541 的奇數位和 A = 6+5+1 =12，偶數位的和 B = 2+3+4 = 9 ，所以 263541
  的秘密差是 |12 －9|= 3 。

  給定一個 十進位正整數 X，請找出 X的秘密差。
  */
  int X = 263541;
  int diff = funcEvenOddDiff(X);
  printf("diff =%d (ans : 3)\n", diff);

  X = 131;
  diff = funcEvenOddDiff(X);
  printf("diff =%d (ans : 1)\n", diff);
}