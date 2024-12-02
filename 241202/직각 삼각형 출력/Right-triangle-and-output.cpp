#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    for(int r=1; r<=n; r++)
    {
        for(int i=0; i<r*2-1; i++)
            cout << "*";
        cout << "\n";   
    }
    
    
    return 0;
}