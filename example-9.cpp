#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
    ifstream f("example.txt");

    string word1, word2;
    map<string, string> dt;

    while (!f.eof())
    {
        f >> word1;
        f >> word2;
        dt.insert(pair<string, string>(word1, word2));
    }

    for (auto &x : dt)
    {
        cout << x.first << " - " << x.second << endl;
    }

    return 0;
}