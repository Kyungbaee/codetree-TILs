#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, cnt=65;
    cin >> n;

    for(int i=n; i>0; i--)
    {
        for(int j=n; j>0; j--)
        {
            if(j>i) cout << "  ";
            else
            {
                cout << char(cnt) << " ";
                cnt++;
                if(cnt >= (65+26)) cnt=65;
            }
        }
        cout << "\n";
    }
    return 0;
}