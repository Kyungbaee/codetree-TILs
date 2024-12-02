#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        if(i%2)
        {
            for(int j=n; j>i/2; j--)
                cout << "* ";
            cout << "\n";
        }
        else
        {
            for(int j=i/2; j>0; j--)
                cout << "* ";
            cout << "\n";
        }

    }

    for(int i=n; i>=1; i--)
    {
        if(i%2==0)
        {
            for(int j=i/2; j>0; j--)
                cout << "* ";
            cout << "\n";
        }
        else
        {
            for(int j=n; j>i/2; j--)
                cout << "* ";
            cout << "\n";
        }

    }

    return 0;
}