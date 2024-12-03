#include <iostream>
using namespace std;
int nums[101];

int main() {
    // 여기에 코드를 작성해주세요.
    int n, cnt;
    cin >> n;
    cnt = n;

    while(n--)
    {
        int num;
        cin >> num;
        nums[n] = num;
    }

    for(int i=0; i<cnt; i++)
    {
        if(nums[i]%2==0) cout << nums[i] << " ";
    }
    return 0;
}