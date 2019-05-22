#include <iostream>
#include <vector>

template <typename T>
class Elem {
    T value;
    std::pair<long, long> coordinates; /* first = row, second = col */
public:
    Elem(T value, long row, long col) : value(value), coordinates(std::make_pair(row, col)) {}
    long getRow() {
      return this->coordinates.first;
    }
    long getCol() {
      return this->coordinates.second;
    }
    T getValue() {
      return this->value;
    }
    void print() {
      std::cout << value << " at <" << getRow() << ", " << getCol() << ">" << std::endl;
    }
};

template <typename T>
class Triangle {
    long maxRows;
    std::vector<Elem<T>> elements;
    std::pair<long, long> nexTPosition; /* first = nextElemPositionRow, second = nextElemPositionCol */
public:
    Triangle(): maxRows(10), nexTPosition(std::make_pair(0, 0)) {
      this->addElement(10);
    }
    Triangle(std::vector<T> elements): nexTPosition(std::make_pair(0, 0)), elements(elements), maxRows(100) {}
    Triangle(std::vector<T> elements, long maxRows): nexTPosition(std::make_pair(0, 0)), elements(elements), maxRows(maxRows) {}
    long getRows() {
      long highestRow = 0;
      for (const auto &element : elements) {
        if (element.getRow() + 1 > highestRow) {
          highestRow = element.getRow() + 1;
        }
      }

      return highestRow;
    }

    bool addElement(T value) {
      this->elements.push_back(Elem<T>(value, nexTPosition.first, nexTPosition.second));

      if (nexTPosition.first == nexTPosition.second) {
        nexTPosition.first++;
        nexTPosition.second = 0;
      } else {
        nexTPosition.second++;
      }

      return true;
    }

    bool operator+=(T items[]) {
      for (const auto &item : items) {
        this->addElement(item);
      }
    }

    bool operator!=(const Triangle &rhs) const {
      return !(rhs == *this);
    }

    T getAt(long i, long j) {
      for (auto &element : elements) {
        if (element.getRow() == i && element.getCol() == j) {
          return element.getValue();
        }
      }

      return getAt(0, 0);
    }

    bool isStable() {
      /* TODO redo if time - does not handle shuffled elements */
      T lastRowMaxValue = getAt(0, 0);
      long lastRowIndex = 0;
      for (auto &element : elements) {
        if (element.getCol() != 0 && element.getRow() != 0) {
          if (element.getCol() > lastRowIndex && element.getValue() < lastRowMaxValue) return false;
          else if (element.getValue() < lastRowMaxValue) {
            lastRowIndex = element.getCol();
            lastRowMaxValue = element.getValue();
          }
        }
      }

      return true;
    }

    void print() {
      for (auto &element : elements) {
        element.print();
      }
    }

};

int main() {
  Triangle<long> triangle;
//  std::cout << triangle.getAt(0, 0) << std::endl;
  triangle.addElement(100);
  triangle.addElement(101);
  triangle.addElement(102);
  triangle.addElement(103);
  triangle.addElement(1);
  std::cout << triangle.isStable() << std::endl;
  triangle.print();
  return 0;
}

