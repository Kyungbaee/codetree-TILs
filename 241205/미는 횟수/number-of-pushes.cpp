#include <iostream>
#include <string>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string a, b;
    cin >> a >> b;

    int n = a.length();

    while(n--)
    {
        string aa="";
        aa += a[a.length()-1];
        for(int i=0; i<a.length()-1; i++)
        {
            aa += a[i];
        }
        a = aa;

        if(a == b)
        {
            cout << a.length()-n;
            break;
        }
    }

    if(n==-1) cout << -1;
    return 0;
}