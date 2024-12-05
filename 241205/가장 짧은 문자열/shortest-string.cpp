#include <iostream>
#include <string>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n=3, long_s=0, short_s=21;

    while(n--)
    {
        string s;
        cin >> s;
        if (s.length()>long_s) long_s=s.length();
        if (s.length()<short_s) short_s=s.length();
    }
    cout << long_s-short_s;
    return 0;
}