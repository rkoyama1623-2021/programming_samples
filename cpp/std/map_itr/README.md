# iterator with map

`std::map` is not indexed, so you cannot get "i*th*" element of map.

However, you may want to get all elements in map. In such case you should youse `std::iterator`.

```cpp
#include <iostream>
#include <map>
#include <iterator>

int main () {
  std::map<std::string, int> mp;
  mp["a"] = 1;
  mp["b"] = 2;
  mp["c"] = 3;

  for ( std::map<std::string, int>::iterator itr = mp.begin(); itr != mp.end(); itr++ ) {
    std::cout << itr->first << "=" << itr->second << std::endl;
  };


  return 0;
};
```

You can easily generate iterator of map by `std::map<std::string, int>::iterator itr`.
Since itr is a pointer to each map, you can use member variables, and methods of originals.

For example, map has first & second element, so you can access them by `itr->first`,`itr->first`.
