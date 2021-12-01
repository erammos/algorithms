#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "hash_map.h"
using namespace std;


int main() {

HashMap<int,string> map;
map.Insert(2,"two");
map.Insert(10,"ten");
map.Insert(1,"one");
map.Insert(102,"102");

map.Insert(1020,"1020");
map.Insert(9090,"9090");
cout << map.Find(2) << endl;
cout << map.Find(1) << endl;
cout << map.Find(10) << endl;
cout << map.Find(9090) << endl;
cout << map.Find(1020) << endl;
}

