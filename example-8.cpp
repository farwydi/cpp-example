#include <iostream>

class Vector
{
  public:
    Vector(int _x, int _y, int _z)
        : x(_x), y(_y), z(_z) {}

    Vector &operator*=(const Vector &v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;

        return *this;
    }

    Vector &operator*=(const int scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;

        return *this;
    }

    int x;
    int y;
    int z;
};

int main()
{
    Vector a(1, 8, 14);
    Vector b(4, 85, 1);

    std::cout << "a = " << a.x << " - " << a.y << " - "<< a.z << std::endl;
    std::cout << "b = " << b.x << " - " << b.y << " - "<< b.z << std::endl;

    a *= 45;

    std::cout << "a * 45 = " << a.x << " - " << a.y << " - "<< a.z << std::endl;

    a *= b;

    std::cout << "a * b = " << a.x << " - "<< a.y << " - "<< a.z << std::endl;

    return 0;
}
