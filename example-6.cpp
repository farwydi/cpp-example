#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cout << "Inter a string " << std::endl;
    getline(std::cin, str);

    std::cout << str << std::endl;
}