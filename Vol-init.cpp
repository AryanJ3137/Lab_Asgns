#include <iostream>
using namespace std;

class box
{
    double l;
    double w;
    double h;

public:
    box(double length, double width, double height)
    {
        l = length;
        w = width;
        h = height;
    }

    double display()
    {
        return l * w * h;
    }
};

int main()
{
    double l, w, h;

    cout << "Enter length, width and height of box 1: ";
    cin >> l >> w >> h;

    box box1(l, w, h);

    cout << "Volume of box 1: " << box1.display() << endl;

    cout << "Enter length, width and height of box 2: ";
    cin >> l >> w >> h;

    box box2(l, w, h);

    cout << "Volume of box 2: " << box2.display() << endl;

    return 0;
}
