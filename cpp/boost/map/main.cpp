// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <iostream>
#include <iomanip>
#include <map>
#include <string>

class parent {
public:
  std::string name;
  int* a;
};

class child {
public:
  std::string name;
  parent* p;
};

int main () {
  std::cout << "hello world!" << std::endl;
  std::map<std::string, child> cmap;
  child c1 = child();
  c1.name = "taro";
  parent* p = new parent();
  p->a = 0;
  p->name = "haha1";
  c1.p = p;
  cmap["child1"] = c1;
  cmap["child2"] = c1;

  std::cout << "child:" << std::setw(8) << std::hex << std::uppercase << &(c1) << std::endl;
  std::cout << "child1:" << std::setw(8) << std::hex << std::uppercase << &(cmap["child1"]) << std::endl;
  std::cout << "child2:" << std::setw(8) << std::hex << std::uppercase << &(cmap["child2"]) << std::endl;
  std::cout << "p:" << std::setw(8) << std::hex << std::uppercase << p << std::endl;
  std::cout << "child1.p:" << std::setw(8) << std::hex << std::uppercase << cmap["child1"].p << std::endl;
  std::cout << "child2.p:" << std::setw(8) << std::hex << std::uppercase << cmap["child2"].p << std::endl;
  std::cout << "child1.name:" << std::setw(8) << std::hex << std::uppercase << cmap["child1"].name << std::endl;
  c1.name = "jiro";
  std::cout << "child2.name:" << std::setw(8) << std::hex << std::uppercase << cmap["child2"].name << std::endl;

  std::cout << "child1.p->name:" << std::setw(8) << std::hex << std::uppercase << cmap["child1"].p->name << std::endl;
  p->name = "haha2";
  std::cout << "child2.p->name:" << std::setw(8) << std::hex << std::uppercase << cmap["child2"].p->name << std::endl;

  return 0;
};

// int main(){
//   map<string, int> mapstriHeight;
//   // 山の名前から高さを得る連想配列を用意する。
//   mapstriHeight["Fuji"] = 3776;
//   mapstriHeight["Everest"] = 8848;
//   // 富士山の高さを登録する。
//   int iHeightOfFuji = mapstriHeight["Fuji"];
//   // 富士山の高さを読み出す。
//   cout << "Height of Fuji is " << mapstriHeight["Fuji"] << endl;
//   cout << "Height of Everest is " << mapstriHeight["Everest"] << endl;
// }

