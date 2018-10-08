#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;


vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}


vector<string> filter(vector<string> v) {
    vector<string> new_v;

    for (string word : v) {
        if (atoi(word.c_str()) != 0) {
            new_v.push_back(word);
        }
    }

    return new_v;
}

int main() {
//    char str[80] = "1 abc 25 kim 0 34 11";
    char str[80];
    cin.getline(str, 80);
    string s = string(str);

    auto split_string = split(s, ' ');

    auto onli_int = filter(split_string);

    stringstream n;
    for (auto wint :onli_int) {

        n << wint << ' ';
    }

    cout << n.str() << endl;

    return 0;
}
