#include "bst.h"
#include "btree.h"
#include "avl.h"
#include <cstdlib>
#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <cstring>

const int N = 10000;
bool VERBOSE = true;

static timeval begin;
static timeval end;

void start_stopwatch() {
  gettimeofday(&begin, NULL);
}

void stop_stopwatch() {
  gettimeofday(&end, NULL);

  static timeval diff;
  timersub(&end, &begin, &diff);

  {
    using namespace std;
    if(VERBOSE) cout << "    ";
    if(VERBOSE) cout << setfill(' ') << setw(7);
    cout << diff.tv_sec * 1000000 + diff.tv_usec;
    if(VERBOSE) cout << "us";
    cout << endl;
  }
}

// insert in increasing order, 
// access in increasing order,
// delete in increasing order
void test_1(btree* bst) {
  std::cout << "insert in increasing order..." << std::endl;
  start_stopwatch();
  for(int x=0; x<N; x++)
    if(bst->insert(x) == false) exit(1);
  stop_stopwatch();
  std::cout << "access in increasing order..." << std::endl;
  start_stopwatch();
  for(int x=0; x<N; x++)
    if(bst->contains(x) == false) exit(1);
  stop_stopwatch();
  std::cout << "delete in increasing order..." << std::endl;
  start_stopwatch();
  for(int x=0; x<N; x++)
    if(bst->erase(x) == false) exit(1);
  stop_stopwatch();
}

// insert in increasing order, 
// access in decreasing order,
// delete in decreasing order
void test_2(btree* bst) {
  std::cout << "insert in increasing order..." << std::endl;
  start_stopwatch();
  for(int x=0; x<N; x++)
    if(bst->insert(x) == false) exit(1);
  stop_stopwatch();
  std::cout << "access in decreasing order..." << std::endl;
  start_stopwatch();
  for(int x=N-1; x>=0; x--)
    if(bst->contains(x) == false) exit(1);
  stop_stopwatch();
  std::cout << "delete in decreasing order..." << std:: endl;
  start_stopwatch();
  for(int x=N-1; x>=0; x--)
    if(bst->erase(x) == false) exit(1);
  stop_stopwatch();
}

// insert in random order, 
// access in same random order,
// delete in same random order
void test_3(btree* bst) {
  //store N random ints to use
  std::vector<int> v; v.reserve(N);
  std::set<int> s;
  while(v.size() < N) {
    int n = rand();
    if(s.find(n) == s.end()) { // if n is not in s
      v.push_back(n);
      s.insert(n);
    }
  }
  std::cout << "insert in random order..." << std::endl;
  start_stopwatch();
  for(int x=0; x<N; x++)
    if(bst->insert(v[x]) == false) exit(1);
  stop_stopwatch();
  std::cout << "access in same random order..." << std::endl;
  start_stopwatch();
  for(int x=0; x<N; x++)
    if(bst->contains(v[x]) == false) exit(1);
  stop_stopwatch();
  std::cout << "delete in same random order..." << std::endl;
  start_stopwatch();
  for(int x=0; x<N; x++)
    if(bst->erase(v[x]) == false) exit(1);
  stop_stopwatch();
}

void test(btree* bstt) {
  test_1(bstt);
  test_2(bstt);
  test_3(bstt);
}

void all() {
  btree* bstt;

  std::cout << "bst:" << std::endl;
  bstt = new bst();
  test(bstt);
  delete bstt;

  std::cout << "avl:" << std::endl;
  bstt = new avl();
  test(bstt);
  delete bstt;
}

int main(int argc, char** argv) {
  std::cout << "TESTING RUNTIMES" << std::endl;
  all();
}

