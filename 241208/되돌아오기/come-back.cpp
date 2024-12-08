#include <iostream>
using namespace std;

int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

int main() {
    // 여기에 코드를 작성해주세요.
    int n, cnt=0, dir=0, x=0, y=0;
    cin >> n;

    while(n--)
    {
        char dir;
        int len;

        cin >> dir >> len;

        if(dir == 'N') dir=0;
        if(dir == 'E') dir=1;
        if(dir == 'S') dir=2;
        if(dir == 'W') dir=3;

        while(len--){
            x += dx[dir], y += dy[dir];
            cnt++;

            if(x==0 && y==0) break;
        }

        if(x==0 && y==0) break;
    }

    if(x==0 && y==0) cout << cnt;
    else cout << -1;
    return 0;
}