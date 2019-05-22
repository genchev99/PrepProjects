#include <utility>
#include <iostream>
#include <vector>

class Animal {
protected:
    std::string name;
public:
    Animal(): name("no name") {}
    Animal(std::string name): name(std::move(name)) {}
    Animal(const Animal &other) {
      this->name = other.name;
    }
    std::string getName() {
      return this->name;
    }
    virtual void askForFood() = 0;
};

class Parrot: public Animal {
public:

    Parrot() = default;
    Parrot(std::string name):Animal(name) {}
    Parrot(const Parrot &other) {
      this->name = other.name;
    }
    void askForFood() override {
      std::cout << "parrot " << this->getName() << " whistles for food" << std::endl;
    }

};

class Monkey: public Animal {
public:
    Monkey() = default;
    Monkey(std::string name): Animal(name) {}
    Monkey(const Monkey &other) {
      this->name = other.name;
    }
    void askForFood() override {
      std::cout << "monkey " << this->getName() << " cries for food" << std::endl; /* tajno */
    }
};

class Zoo {
    std::vector<Animal *> animals;
    long maxAnimals;
public:
    Zoo(): maxAnimals(100) {}
    Zoo(const Zoo &other) {
      /*for (auto &animal : other.animals) {
        this->animals.push_back(new animal));
      }*/
      this->maxAnimals = other.maxAnimals;
      this->animals.insert(this->animals.begin(), other.animals.begin(), other.animals.end());
    }
    bool addAnimal(Animal *animal) {
      if (this->maxAnimals == animals.size()) return false;

      animals.push_back(animal);
      return true;
    }

    void morningSounds() {
      for (auto &animal : animals) {
        animal->askForFood();
      }
    }

    ~Zoo() {
      for (auto &item : animals) {
        delete item;
      }

      animals.clear();
    }

};

int main() {
  Zoo zoo;
  zoo.addAnimal(new Monkey("Pesho"));
  zoo.addAnimal(new Monkey("Pesho1"));
  zoo.addAnimal(new Monkey("Pesho2"));

  zoo.addAnimal(new Parrot("Mitko"));
  zoo.addAnimal(new Parrot("Mitko2"));
  zoo.addAnimal(new Parrot("Mitko1"));

  zoo.addAnimal(new Monkey("Pesho3"));

  zoo.morningSounds();
  return 0;
}
