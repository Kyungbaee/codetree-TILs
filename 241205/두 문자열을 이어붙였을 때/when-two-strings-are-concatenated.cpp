#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string a, b, ab="", ba="";

    cin >> a >> b;
    ab = a+b;
    ba = b+a;

    if(ab == ba) cout << "true";
    else cout << "false";

    return 0;
}