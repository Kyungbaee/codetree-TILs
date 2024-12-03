#include <iostream>
using namespace std;

int nums[11];

int main() {
    // 여기에 코드를 작성해주세요.
    int cnt=0;

    while(true)
    {
        int num;
        cin >> num;

        if(num%3==0) 
        {
            cout << nums[cnt-1];
            break;
        }
        else nums[cnt] = num;
        cnt++;
    }
    return 0;
}