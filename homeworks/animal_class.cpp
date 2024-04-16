#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Animal {
  protected:
    string name;
    int weight;
  public:
    Animal(string name, int weight): name(name), weight(weight) {};
    ~Animal() {};
    virtual void print() = 0;
};

class Cat : public Animal {
  protected:
    string breed;
  public:
    Cat(string name, int weight, string breed) : Animal(name, weight), breed(breed) {};
    ~Cat() {};
    virtual void print() {
      cout << "Name: " + name + ", weight: " + to_string(weight);
    }
};


class Dog : public Animal {
  protected:
    string breed;
  public:
    Dog(string name, int weight, string breed) : Animal(name, weight), breed(breed) {};
    ~Dog() {};
    virtual void print() {
      cout << "Name: " + name + ", weight: " + to_string(weight);
    }
};


int main() {
  vector<Animal*> V;
  Cat ball("Shareeque", 4, "Terrier");
  Dog bob("Robert", 6, "Bulldog");
  V.push_back(&ball);
  V.push_back(&bob);
  for (auto beast : V) {
    beast->print();
    cout << '\n';
  }
  return 0;
}
