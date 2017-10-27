#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool customSort(const std::string &i, const std::string &j)
{
    return (i.length() < j.length());
}

int main()
{
    std::vector<std::string> x;

    x.push_back("today");
    x.push_back("is");
    x.push_back("duty");
    x.push_back("on");
    x.push_back("?");
    x.push_back("who");

    std::sort(x.begin(), x.end(), customSort);

    for (auto &word : x)
    {
        std::cout << word << std::endl;
    }
}