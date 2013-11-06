//Alexander Smith
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <sstream>
#include "bst.h"
#include "avl.h"
#include "btree.h"

bool ends_with(std::string const &haystack, 
    std::string const &suffix) {
  if(haystack.length() >= suffix.length()) {
    return 0 == haystack.compare(
        haystack.length()-suffix.length(),
        suffix.length(), suffix);
  } else {
    return false;
  }
}

btree* create_bst(std::string kind) {
  if(ends_with(kind, "avl"))
    return new avl();
  else if(ends_with(kind, "bst"))
    return new bst();
  else
    return NULL;
}

int main(int argc, char** argv) {
  using namespace std;
  btree* bst= create_bst(argv[0]);
  if(bst== NULL) {
    cerr << "please rename this executable 'avl' OR 'bst'" << endl;
    return 1;
  }

string line;
  while(getline(cin,line)) {
    int i;
    size_t pos = line.find(" ");
    string cmd, value;
    if(pos == std::string::npos){
      cmd = line;
    }

    else{
      cmd = line.substr(0, pos);
      value = line.substr(pos+1, line.length() - pos -1);
      istringstream buffer(value);
      buffer >> i;
    }

    if(cmd.compare("insert") == 0) {
      if(bst->insert(i))
	cout << "Element inserted" << endl;
      else {
	cout << "Element already present" << endl; 
      }
    } 
    else if(cmd.compare("access") == 0) {
      if(bst->contains(i))
	cout << "Element accessed " << endl;
      else
	cout << "Element not found" << endl;
    } 
    
    else if(cmd.compare("delete") == 0) {
      if(bst->erase(i))
	cout << "Element deleted" << endl;
      else
	cout << "item not present in the tree" << endl;
    } 
    else if(cmd.compare("print") == 0) {
      bst->print();
    }
  }
}

