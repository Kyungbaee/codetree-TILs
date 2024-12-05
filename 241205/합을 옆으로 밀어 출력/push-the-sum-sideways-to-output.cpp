#include <iostream>
#include <string>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, sum=0;
    cin >> n;

    while(n--)
    {
        int num;
        cin >> num;
        sum += num;
    }

    string s = to_string(sum);
    for(int i=1; i<s.length(); i++)
    {
        cout << s[i];
    }
    cout << s[0];
    return 0;
}