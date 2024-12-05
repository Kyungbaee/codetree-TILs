#include <iostream>
#include <string>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string s;
    cin >> s;


    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='e'){
            s.erase(s.begin()+i);
            break;
        }
    }

    cout << s;
    return 0;
}