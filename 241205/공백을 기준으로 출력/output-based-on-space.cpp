#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n=2;
    while(n--)
    {
        string s;
        getline(cin, s);
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        cout << s;
    }

    return 0;
}