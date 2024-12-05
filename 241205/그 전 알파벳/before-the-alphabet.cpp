#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    char alpha;
    cin >> alpha;

    if(int(alpha)==97) cout << char(122);
    else cout << char(int(alpha)-1);
    return 0;
}