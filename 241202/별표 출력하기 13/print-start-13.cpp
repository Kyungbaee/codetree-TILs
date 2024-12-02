#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    if(n>1)
    {
        for(int i=0; i<n; i++)
            cout << "* ";
    }
    cout << "\n*\n";
    if(n>2)
    {
        for(int i=0; i<n-1; i++)
            cout << "* ";
        cout << "\n";
        for(int i=0; i<n-1; i++)
            cout << "* ";
    }
    cout << "\n*\n";
    if(n>1)
    {
        for(int i=0; i<n; i++)
            cout << "* ";
    }

    return 0;
}