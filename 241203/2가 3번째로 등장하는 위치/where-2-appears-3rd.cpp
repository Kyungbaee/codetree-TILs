#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, cnt=0;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        int num;
        cin >> num;

        if(num==2) cnt++;
        if(cnt==3){
            cout << i;
            break;
        }
    }
    return 0;
}