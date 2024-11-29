#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a;
    cin >> a;

    if(!(a%3)) cout << "YES";
    else cout << "NO";
    cout << "\n";

    if(!(a%5)) cout << "YES";
    else cout << "NO";

    return 0;
}