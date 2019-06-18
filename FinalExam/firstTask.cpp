#include <iostream>
#include <vector>
#include <string>
//#include "MapSet.h"

template <typename S, typename V>
class MapElement {
    S source;
    std::vector<V> values;
public:
    MapElement() = default;
    MapElement(S initSource, V initValue) {
      source = initSource;
      values.push_back(initValue);
    }
    S getSource() {
      return source;
    }

    bool addValue(V value) {
      values.push_back(value);

      return true;
    }

    std::vector<V> getValues() {
      return values;
    }
};

template <typename S, typename V>
class MapSet {
  std::vector<MapElement<S, V>> elements;
public:
    MapSet() = default;
    void print() {
      for (auto &element : elements) {
        std::cout << element.getSource() << std::endl;
      }
    }
    bool add(S source, V value) {
      int set = -1;
      for (int i = 0; i < elements.size(); ++i) {
        if (elements.at(i).getSource() == source) {
          set = i;
        }
      }

      if (set != -1) {
        elements.at(set).addValue(value);
      } else {
        elements.push_back(MapElement<S, V>(source, value));
      }
      return false;
    }

    bool hasValue(S source, V value) {
      for (auto &element : elements) {
        if (element.getSource() == source) {
          for (auto &destination : element.getValues()) {
            if (destination == value) {
              return true;
            }
          }
        }
      }
      return false;
    }
};


int main() {
  MapSet<int, std::string> sets;
  sets.add(0, "cat");
  std::cout << sets.hasValue(0, "cat") << ", " << sets.hasValue(0, "dog") << std::endl; // true, false
  sets.add(0, "dog");
  sets.add(1, "dog");
  std::cout << sets.hasValue(0, "cat") << ", " << sets.hasValue(0, "dog") << std::endl; // true, true
  std::cout << sets.hasValue(1, "cat") << ", " << sets.hasValue(1, "dog") << std::endl; // false, true
//  sets.print();
  return 0;
}

