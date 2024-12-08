#include <iostream>
#include <string>
using namespace std;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    string s;
    cin >> s;
    int x=0, y=0, dir=0;

    for(auto c : s)
    {
        if(c=='L') dir -= 1;
        if(c=='R') dir += 1;
        dir = (dir+4)%4;

        if(c=='F') x += dx[dir], y += dy[dir];
    }

    cout << x << " " << y;

    // 여기에 코드를 작성해주세요.
    return 0;
}