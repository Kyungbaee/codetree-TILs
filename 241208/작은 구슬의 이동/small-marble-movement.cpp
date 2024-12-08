#include <iostream>
using namespace std;

int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

int main() {
    // 여기에 코드를 작성해주세요.
    int n, t, r, c, dir;
    char d;
    cin >> n >> t >> r >> c >> d;

    if (d == 'U') dir=0;
    if (d == 'R') dir=1;
    if (d == 'D') dir=2;
    if (d == 'L') dir=3;

    while(t--)
    {
        int nx = r+dy[dir], ny = c+dx[dir];

        if(nx>=1 && nx<=n && ny>=1 && ny<=n)
            r = nx, c = ny;
        else
            dir = (dir+2)%4;
    }

    cout << r << " " << c;
    
    return 0;
}