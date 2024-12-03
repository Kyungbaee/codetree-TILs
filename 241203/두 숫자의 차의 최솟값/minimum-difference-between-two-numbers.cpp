#include <iostream>
using namespace std;
int nums[11];

int main() {
    // 여기에 코드를 작성해주세요.
    int n, dif=100;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
        if(i!=0)
        {
            dif = min(dif, nums[i]-nums[i-1]);
        }
    }
    cout << dif;
    return 0;
}