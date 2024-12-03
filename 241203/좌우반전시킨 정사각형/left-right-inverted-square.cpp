#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        for(int j=n; j>0; j--)
            cout << j*i << " ";
        cout << "\n";
    }
    return 0;
}