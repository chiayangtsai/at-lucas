#include "includes.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

// Goolge : c++ keyword
//  - Cplusplus
//  - geeksforgeeks
//  - stackoverflow

using namespace std;

int main() {
  int testID = 17;

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
  case 15:
    leetcode_shuffle_lists_iv();
    break;
  case 16: // string
    basic_string_usage();
    break;
  case 17:
    leetcode_letters_histogram();
    break;
  case 18:
    leetcode_find_num_digits();
    break;
  case 19:
    leetcode_find_num_prefix_matches();
    break;
  case 30: // struct, class, object
    basic_class_struct();
    break;
  default:
    printf("not a supported test ID : %d\n", testID);
    exit(-1);
  }

  // string
  // digit manipulation
  // struct
  // class
  // std::sort
  // unordered_map, map
  // recursive

  return 0;
}

void basic_class_struct() {}
void leetcode_letters_histogram() {
  // Q : print out the histogram of alphbet apperance with alphbet order.
  //
  //   NOTE: non-existence and non-alphabet shall not be printed
  //
  // Example: "a; b69ad*b%a^a;"
  //     a : 4
  //     b : 2
  //     d : 1
  string testStr = "a; b69ad*b%a^a;";

  //HW0929
  int i_a = 0;
  int i_b = 0;
  int i_d = 0;
  while(testStr.find("a") != string::npos || testStr.find("b") != string::npos || testStr.find("d") != string::npos){
    if(testStr.find("a") != string::npos){
      i_a++;
      testStr.erase(auto *ita = testStr.find("a"));
    }
    if(testStr.find("b") != string::npos){
      i_b++;
      testStr.erase(testStr.find("b"));
    }
    if(testStr.find("d") != string::npos){
      i_d++;
      testStr.erase(testStr.find("d"));
    }
  }
  cout << i_a << ", " << i_b << ", " << i_d << endl;
  
}

int findPrefix(vector<string> &words) {
  // TBD
  return -1;
}

void leetcode_find_num_prefix_matches() {
  // Q: given a list of words and a prefix string, find number of words with
  // that prefix
  //  For example:
  //  words= {"abcd", "bce", "bab", "abe", "cabe", "ab"}
  //  prefix = "ab"
  //   - "abcd" => +1
  //   - "bce" =>X
  //   - "bab" =>X
  //   - "abe" => +1
  //   - "cabe" => X
  //   - "ab"  => +1
  //
  //   number of matches : 3
  //

  vector<string> words = {"abcd", "bce", "a", "abe", "ced"};

  int num = findPrefix(words);

  printf("number of matches: %d (ans: 3)\n", num);
}

void leetcode_find_num_digits() {
  string input = "98i6098kljgo987tglkujb.,j";

  int res = -1;
  //HW0929
  //int zero =  (int)'0';
  //0的ASCII code 

  printf("number of digits in string = %s \n", input.c_str());
  printf(" => %d (ans: 9)\n", res);
}

#define MERGE_SORTED_LIST_ALTER 1

void leetcode_merge_sorted_lists() {
  vector<int> x({6, 8, 10, 20, 21, 30});
  vector<int> y({1, 3, 4, 7, 14, 16, 100, 110});
  vector<int> z;

#if MERGE_SORTED_LIST_ALTER

  while (!x.empty() || !y.empty()) {
    // general case
#if 0
    vector<int>* p =  (!x.empty() && !y.empty())?
      ( (x.front() < y.front() )?( &x ):( &y) ):
      ( (!x.empty())?(&x ):( &y ) );
#else
    vector<int> *p = nullptr;
    // p <= x, y
    if (!x.empty() && !y.empty()) {
      p = (x.front() < y.front()) ? (&x) : (&y);
    } else if (!x.empty()) {
      p = &x;
    } else {
      p = &y;
    }
#endif
    // c.push_back( p->front())
    // p->erase( head )
    z.push_back(p->front());
    p->erase(p->begin());

    // ending condition
    //  both x y empty()
  }
#else
  // Q: x and y are sorted data. merge x and y to z as a sorted data as well.
  //  z = {1, 3, 4, 6, 7, 8, 10, 14, 16, 20, 21, 30, 100, 110}
  //
  //  NOTE: time complexity must be O(N)
  // HW0922 : optional
  // HW0925 : try to simplify / optimize the codes
  int c = 0;
  int ix = 0;
  int iy = 0;
  auto it_x = x.begin();
  auto it_y = y.begin();
  while (c < x.size() + y.size()) {
    if (ix < x.size()) {
      // it_y != y.end()
      if (it_y != y.end() && *it_x >= *it_y) {
        z.push_back(*it_y);
        it_y++;
        iy++;
        c++;
      } else {
        z.push_back(*it_x);
        it_x++;
        ix++;
        c++;
      }
    } else {
      z.push_back(*it_y);
      it_y++;
      c++;
    }
  }
#endif

  for (auto p : z) {
    printf("%d ", p);
  }
  printf("\n");
}

void basic_string_usage() {
  //
  //  https://cplusplus.com/reference/string/string/
  //

  // C-style usage & ASCII codes
  {
    int x;  // 4 bytes = 32 bit integer [-2^31, 2^31-1]
    char a; // 1 byte = 8 bit integer => 2^8 = 256 combination
    // Signed char (char) : data range [-128, 127] = [-2^7, 2^7-1]
    // unsigned char      : data range [0, 2^8-1]= [0, 255]
    char name[7] = "John"; // {'J', 'o', 'h', 'n', '\0',  ,  }
    printf("name = %s\n", name);
  }

  // C++ style usage
  //.size() : number of elements/
  //.push_back(element) : append an element to the end
  //.pop_back() : pop out the last element
  //.begin() : the 1st iterator (第一項的memory address)
  //.end() : the last iterator
  //.front(): the 1st reference
  //.back() : the last reference
  //.erase( iterator ) : erase the element @ iterator position
  //.erase(iterator 1, iterator 2) : erase the element(s) between
  //.insert( iterator, element) : insert new element @ iterator position
  //.clear() : clear everything
  //.empty() : return true if .size() == 0
  //.find(str) : find the matched "str" position in your string
  //             string::npos : not found
  {
    string name = "John";
    int pos= name.find("oh");
    printf("find \"oh\" matched position in string %s = %d\n", name.c_str(), pos);

    pos = name.find("apple");
    printf("find \"apple\" matched position in string %s = %d\n", name.c_str(), pos);

    string keyStr = "VK";
    if(name.find(keyStr) != string::npos){
      printf("found\n");
    }
    else{
      printf("not found\n");
    }

    
    
  }

  // iterations
  {
    string str = "This is AT class";

    for(auto ir : str){
      cout << ir << flush;
    }    
  }

  //erase
  {
    string str = "This is AT class";
    //Q: erase "A" from str
    string key = "AT";
    int pos = str.find(key);
    auto itPos = str.begin() + pos;
    str.erase(itPos, itPos + key.size()); //erase "AT"
    
  }

  //prefix and postfix //TBV
  {
    
  }

  //string to integer //TBV
  {
    
  }
  
}

void basic_vector_usage() {
  //
  // https://cplusplus.com/reference/vector/vector/
  //
  //.size() : number of elements/
  //.push_back(element) : append an element to the end
  //.pop_back() : pop out the last element
  //.begin() : the 1st iterator (第一項的memory address)
  //.end() : the last iterator
  //.front(): the 1st reference
  //.back() : the last reference
  //.erase( iterator ) : erase the element @ iterator position
  //.insert( iterator, element) : insert new element @ iterator position
  //.clear() : clear everything
  //
  //.empty() : return true if .size() == 0

  // static memory
  /*
  {
    int a[5] = {4, 3, 5, 2, 1};
    // dynamic memory

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
  */
  // push_back
  {
    vector<int> a({4, 1, 2});
    a.push_back(3);
    for (int i = 0; i < a.size(); i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
  }
  // iterator =\= pointer  , but similar
  printf("==== iterator ====== \n");
  {
    //       a= {  4,     3,       5,     2,      1}
    //            ^       ^       ^       ^       ^
    // pointer  &(a[0])  &(a[1]) &(a[2])  &(a[3]) &(a[4])

    //      after erasing "5",

    //       a= {  4,     3,              2,       1}
    //            ^       ^               ^        ^
    // pointer    a      a+1             a+2       a+3    (X)
    //          &(a[0])  &(a[1])       &(a[2])    &(a[3]) (0)
    // iterator  it      it+1            it+2      it+3   (0)

    //      a=  | 4   |  3    |  5    |  2   | 1   |
    //          ^ .begin()                          ^ .end()

    vector<int> a({4, 3, 5, 2, 1});

    // method 1: array index
    for (int i = 0; i < a.size(); i++) {
      printf("%d ", a[i]);
    }
    printf("\n");

    // method 2: iterator
    for (vector<int>::iterator it = a.begin(); it != a.end(); it++) {
      printf("%d ", *it);
    }
    printf("\n");

    int x = 4;
    auto y = x;

    // method 3 : use auto to simplified iterator claim
    for (auto it = a.begin(); it != a.end(); it++) {
      printf("%d ", *it);
    }
    printf("\n");

    // method 4 : use "python-like" experssion
    /*
    list = [3, 5, 6, 2, 3]
    for x in list:
    */
    for (auto &x :
         a) // => for any x in a; auto& x = a[0] 拿ref即跳過copy值的動作
    {
      printf("%d ", x);
      x = 0;
    }
    printf("\n");

    for (auto x : a) {
      printf("%d ", x);
    }
    printf("\n");
  }
  printf("==== front(), back() ====== \n");
  {
    vector<int> a({8, 3, 1, 6, 2, 5});
    // a= [4, 5, 1, 8, 2]
    //    a[0]        a[len(a)-1] == a[-1]
    printf("the first element : %d\n", a.front());
    printf("the last element : %d\n", a.back());

    a.front() = 0;
    a.back() = -1;

    for (auto it = a.begin(); it != a.end(); it++) {
      printf("%d ", *it);
    }
    printf("\n");
  }
  printf("==== .erase(iterator) , .insert(iterator, element) ====== \n");
  {
    vector<int> x({5, 2, 7, 1, 2});
    //            | 5 |  2  |  7  |  1  |  2  |
    //            ^ .begin()                  ^ .end()
    //            it  it+1  it+2  it+3 .....
    // Q : erase index-2 element from x
    auto it = x.begin() + 2;
    x.erase(it);
    for (auto y : x) {
      printf("%d ", y);
    }
    printf("\n");

    // Q : insert 0 to the last position
    it = x.end();
    x.insert(it, 0);
    for (auto y : x) {
      printf("%d ", y);
    }
    printf("\n");
  }

#if 1
  printf("use pointer/reference for accesing vector elements\n");
  // use pointer to switch between two vectors
  {
    vector<int> a;
    vector<int> b;

    vector<int> *p;
    p = &a;
    p->push_back(0);

    p = &b;
    p->push_back(0);
  }

  // use reference to alias an object (reference)
  {
    vector<int> a;
    vector<int> b;

    vector<int> &r = a;
    r.push_back(0);
    //不能直接r = b, 等同於蓋掉a (r) 的值
    vector<int> &rb = b;
    rb.push_back(0);
  }

  {
    vector<vector<int>> a = {{2, 3, 4}, {0}, {2, 9}};
    //      | {2, 3, 4} | {0} | { | 2 | 9 |} |
    //      ^           ^     ^              ^
    //  it_a1
    //        *it_a1 == {2, 3, 4}
    // a.size() == 3
    // a[0] == {2, 3, 4}  , a[0].size() == 3
    // a[1] == {0}        , a[1].size() == 1
    // a[2] == {2, 9}     , a[2].size() == 2

    // Q: print out the value in a
    for (int k = 0; k < a.size(); k++) {
      for (int i = 0; i < a[k].size(); i++)
        printf("%d ", a[k][i]);
    }
    printf("\n");

    //      | {2, 3, 4} | {0} | { | 2 | 9 |} |
    //      ^           ^     ^              ^
    //  it_a1
    //        *it_a1 == {2, 3, 4}
    for (auto it_a1 = a.begin(); it_a1 != a.end(); it_a1++) {
      for (auto it_a2 = (*it_a1).begin(); it_a2 != (*it_a1).end();
           it_a2++) { // it_a1 指的是第幾個vector的iterator (最上層); (*it_a1)
                      // 指的是第幾個vector (實體)
        printf("%d ", *it_a2);
      }
      printf("\n");
    }
    printf("\n");

    // | {2, 3, 4} | {0} | {  2, 9 } |
    // ^it
    for (auto it = a.begin(); it != a.end(); it++) {
      vector<int> &cur = *it; //把it代表的vector加了一個新的名字 cur
      for (auto ij = cur.begin(); ij != cur.end(); ij++) {
        printf("%d ", *ij);
      }
    }

    for (auto ir : a) {
      for (auto ij : ir) {
        printf("%d ", ij);
      }
    }
  }

#endif
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

  vector<int> a({2, 5, 3, 8, 1});
  vector<int> b({0, 1, 2});
  vector<int> c({4, 7, 1, 9, 0, 5});
  vector<int> d;

  // Q: shuffle a, b, c, following index order. Results will be in d.
  //.  expected results :
  //.  d= {2, 0, 4, 5, 1, 7, 3, 2, 1, 8, 9, 1, 0, 5}
  // HW0922 :
  // also print out the vector results of d

  int ind = 0;
  int ia = 0;
  int ib = 0;
  int ic = 0;
  auto it_a = a.begin();
  auto it_b = b.begin();
  auto it_c = c.begin();
  while (ind < a.size() + b.size() + c.size()) {
    if (ia < a.size()) { //(it_a != a.end())
      d.push_back(*it_a);
      it_a += 1;
      ia++;
      ind++;
    }
    if (ib < b.size()) {
      d.push_back(*it_b);
      it_b += 1;
      ib++;
      ind++;
    }
    if (ic < c.size()) {
      d.push_back(*it_c);
      it_c += 1;
      ic++;
      ind++;
    }
  }
  for (auto z : d) {
    printf("%d ", z);
  }
  printf("\n");

  printf("--- v2 : use more vector methods -----\n");

  a = {2, 5, 3, 8, 1};
  b = {0, 1, 2};
  c = {4, 7, 1, 9, 0, 5};
  d.clear();

  while (a.size() > 0 || b.size() > 0 || c.size() > 0)
  // while(!a.empty() || !b.empty() || !c.empty()) =>
  // 至少其中一個vector還不是空的
  {
    // general
    if (!a.empty()) {
      d.push_back(a.front());
      a.erase(a.begin());
    }

    if (!b.empty()) {
      d.push_back(b.front());
      b.erase(b.begin());
    }

    if (!c.empty()) {
      d.push_back(c.front());
      c.erase(c.begin());
    }

    // ending condition
    //  if(a.empty()  && b.empty() && c.empty()){
    //    break;
    //  }
  }
  for (auto &z : d) {
    printf("%d ", z);
  }
  printf("\n");
}

vector<int> shuffle_n_vector(vector<vector<int>> &data) {
  vector<int> res;

  //..res.push_back()
  // HW0925
  auto it = data.begin(); // it = iterator of data
  while (it != data.end()) {
    //    vector<int>& ir = *it;

    while (!(*it).empty()) {
      // general case
      res.push_back((*it).front());
      (*it).erase((*it).begin());
    }
    it++;
  }
  return res;
}

void leetcode_shuffle_lists_iv() {
  // Q : Given a list of vector, shuffle them to a single vector

  vector<vector<int>> data;
  data = {
      {2, 5, 3, 8, 1},   // a
      {0, 1, 2},         // b
      {4, 7, 1, 9, 0, 5} // c
  };

  vector<int> res = shuffle_n_vector(data);

  for (auto ir : res) {
    printf("%d ", ir);
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

#define TWOSUM_NON_REPEATED_PAIR 1

void funcTwoSum(int *data, int dataSize, int sum) {
  // please print out the pairs for targetSum
  // HW0911
  // HW0915
  // bubble sort

  // time complexity : O(N^2)

  // Mindset : pair, mapping, ==> dictionary / Look-up Table (LUT) / Hash
  // table
  // algorithm : use a LUT to indicate the "appearance"
  //     Example : {5, 1, 6, 3, 9, 4, 3, 6, 5};
  //      0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10........, 99
  //         1     1  1  1  1        1

#if TWOSUM_NON_REPEATED_PAIR
  int flags[100];
  for (int i = 0; i < 100; i++) {
    flags[i] = 0;
  }

  for (int i = 0; i < dataSize; i++) {
    int val = data[i];
    flags[val] = 1;
  }

#endif

  vector<int> pairs;
  for (int i = 0; i < dataSize - 1; i++) {
    /*
    i = 0; data[0] = 5; compare following pairs: (5,1) (5,6) (5,3)...(5,5)
    i = 1; data[1] = 1; compare: (1,6) (1,3) (1,9)...(1,5)
    i = 2; data[2] = 6; compare: (6,3) (6,9) (6,4)...(6,5)
    ...i = 5
    */
#if TWOSUM_NON_REPEATED_PAIR
    if (flags[data[i]] == 0) {
      continue;
    }
#endif

    for (int j = i + 1; j < dataSize; j++) { // j不能從1開始找
      // checks if the sum of an item with any of the other items is
      if (data[i] + data[j] == sum) {
#if TWOSUM_NON_REPEATED_PAIR
        if (flags[data[i]] == 0) {
          continue;
        }
#endif
        // equal to the given "sum" value
        // i = 0; checks (5,1)
        // i = 1; checks (1)
        pairs.push_back(data[i]);
        pairs.push_back(data[j]);

#if TWOSUM_NON_REPEATED_PAIR
        flags[data[i]] = 0;
        flags[data[j]] = 0;
#endif
      }
    }
  }

  for (int k = 0; k < (pairs.size()) / 2; k++) {
    cout << "(" << pairs[2 * k] << ", " << pairs[2 * k + 1] << ")" << endl;
  }
}

void funcTwoSumLUT(int *data, int dataSize, int sum) {
  int table[100];
  // O(1)
  for (int i = 0; i < 100; i++) {
    table[i] = 0;
  }

  // O(N)
  for (int j = 0; j < dataSize; j++) {
    int value = data[j];
    table[value] = 1;
  }
  // Double -loop
  //{5, 1, 6, 3, 9, 4, 3, 6, 5};
  // ^
  //    ^^^^^^^^^^^^^^^^^^^^^^^ for loop

  // LUT
  //{5, 1, 6, 3, 9, 4, 3, 6, 5};
  //     ^
  //    pair == 9  -> check table[9]

  // loop -> get data[i]
  //     => check if pair exists
  //     if pair exists => print, set table[value] and table[pair] = 0
  //     //otherwise, continue

  // O(N)
  for (int i = 0; i < dataSize; i++) {
    int val = data[i];
    int pairVal = sum - val;
    if (table[pairVal] == 1) {
      // pairVal exists
      // print out the val and pairVal
      printf("(%d %d)\n", val, pairVal);

      table[val] = table[pairVal] = 0;
    }
  }
}

void leetcode_two_sum() {
  int data[9] = {5, 1, 6, 3, 9, 4, 3, 6, 5};
  int dataSize = 9;
  int sum = 10;

  // Q: print out the pair with sum = 10
  //    expected results : (5, 5), (1, 9), (6, 4)
  //
  //    NOTE: integer k range  0<= k <= 99
  //    NOTE : Don't print out repeasted pairs

  enum _IMPLT_ID {
    IMPLT_DOUBLE_LOOP = 0, // O(N^2)
    IMPLT_LUT,             // O(N)
  };

  int impltID = IMPLT_LUT;

  if (impltID == IMPLT_DOUBLE_LOOP) {
    funcTwoSum(data, dataSize, sum);
  } else if (impltID == IMPLT_LUT) {
    funcTwoSumLUT(data, dataSize, sum);
  }
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
    int digits[count]; //? memory management may have "memory violation"
                       // problem

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
  將一個十進位正整數的奇數位數的和稱為A ，偶數位數的和稱為B，則A與B的絕對差值
  |A －B| 稱為這個正整數的秘密差。

  例如： 263541 的奇數位和 A = 6+5+1 =12，偶數位的和 B = 2+3+4 = 9 ，所以
  263541 的秘密差是 |12 －9|= 3 。

  給定一個 十進位正整數 X，請找出 X的秘密差。
  */
  int X = 263541;
  int diff = funcEvenOddDiff(X);
  printf("diff =%d (ans : 3)\n", diff);

  X = 131;
  diff = funcEvenOddDiff(X);
  printf("diff =%d (ans : 1)\n", diff);
}