#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string s, ans="";
    cin >> s;

    for(int i=0; i<s.length(); i++)
    {
        if(i%2==1){
            ans = s[i]+ans;
        }
    }

    cout << ans;
    return 0;
}