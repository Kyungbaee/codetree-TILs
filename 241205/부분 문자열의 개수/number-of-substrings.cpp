#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string a, b;
    int cnt=0;

    cin >> a >> b;

    for(int i=0; i<=a.length()-b.length(); i++)
    {
        bool chk = true;
        for(int j=0; j<b.length(); j++)
        {
            if(a[i+j] != b[j])
            {
                chk = false;
                break;
            }
        }

        if(chk) cnt++; 
    }

    cout << cnt;
    return 0;
}