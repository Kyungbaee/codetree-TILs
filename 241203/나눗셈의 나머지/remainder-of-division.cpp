#include <iostream>
using namespace std;
int nums[1001];

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b, sum=0;
    cin >> a >> b;

    while(a>1)
    {
        nums[a%b]++;
        a /= b;
    }

    for(int i=1000; i>=0; i--)
    {
        if(nums[i]>0) sum += (nums[i]*nums[i]); 
    }
    cout << sum;
    return 0;
}