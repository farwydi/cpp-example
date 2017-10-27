#include <string>
#include <sstream>
#include <iostream>

int main()
{
    int dd = 25;
    int mm = 10;
    int yyyy = 1917;

    std::stringstream ss;
    ss << dd << "/" << mm << "/" << yyyy;

    std::cout << ss.str() << "!" << std::endl;

    return 0;
}