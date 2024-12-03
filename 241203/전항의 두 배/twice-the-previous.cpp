#include <iostream>
using namespace std;
int nums[11];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> nums[0];
    cin >> nums[1];
    cout << nums[0] << " " << nums[1] << " ";
    for(int i=2; i<10; i++)
    {
        nums[i] = nums[i-1] + 2*nums[i-2];
        cout << nums[i] << " ";
    }
    return 0;
}