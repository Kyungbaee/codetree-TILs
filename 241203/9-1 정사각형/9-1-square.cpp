#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, cnt = 9;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << cnt;
            cnt -= 1;
            if(cnt==0) cnt = 9;
        }
        cout << "\n";
    }
    return 0;
}