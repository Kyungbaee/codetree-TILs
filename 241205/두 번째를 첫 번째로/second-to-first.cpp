#include <iostream>
#include <string>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string s;
    cin >> s;

    char first = s[0], chk = s[1];
    for(int i=1; i<s.length(); i++)
    {
        if(s[i]==chk) s[i]=first;
    }
    cout << s;
    return 0;
}