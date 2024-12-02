#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    for(int i=n; i>=1; i--)
    {
        if(n>1)
        {
            cout << "* ";
            if(i!=n && i!=1)
            {
                for(int j=1; j<=n-2; j++)
                {
                    if(n-i > j)
                        cout << "* ";
                    else
                        cout << "  ";
                }
            }
            else
            {
                for(int j=1; j<=n-2; j++)
                    cout << "* ";
            }

        }
        cout << "*\n";
    }
    return 0;
}