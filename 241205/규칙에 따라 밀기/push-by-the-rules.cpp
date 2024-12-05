#include <iostream>
#include <string>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string s, st;
    cin >> s >> st;

    int cnt=0;
    for(int i=0; i<st.length(); i++)
    {
        if(st[i]=='L') cnt++;
        else cnt--;

        if(cnt<0 || cnt==s.length())
        {
            cnt = (cnt+s.length()) % s.length();
        }
    }

    for(int i=cnt; i<s.length(); i++)
    {
        cout << s[i];
    }

    for(int i=0; i<cnt; i++)
    {
        cout << s[i];
    }
    return 0;
}