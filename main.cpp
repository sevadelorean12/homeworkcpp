#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;


class Shape {
    protected:
        double x;
        double y;
    public:
        Shape(double x, double y) : x(x), y(y) {};
        virtual ~Shape() {};
        virtual double area() const = 0;
};

class Circle : public Shape {
    protected:
        double r;
    public:
        Circle(double x, double y, double r1): Shape(x, y) {
            r = r1;
        }
        virtual double area() const {
            return M_PI * r * r;
        }
        virtual ~Circle() {};
};

class Rectangle : public Shape {
    protected:
        double w;
        double h;
    public:
        Rectangle(double x, double y, double w1, double h1): Shape(x, y) {
            w = w1;
            h = h1;
        }
        virtual double area() const {
            return w * h;
        }
        virtual ~Rectangle() {};
};

vector<Shape*> V;

int main() {
    Circle a = Circle(3, 5, 7);
    Rectangle b = Rectangle(0, 0, 5, 6);
    V.push_back(&a);
    V.push_back(&b);
    for (int i = 0; i < V.size(); i++) {
        cout << V[i] -> area() << '\n';
    }
    return 0;
}
