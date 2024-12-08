#include <iostream>
using namespace std;

int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
int nums[100][100];

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, x=0, y=0, dir=0;
    cin >> n >> m;

    for(int i=1; i<=(n*m); i++)
    {
        nums[x][y] = i;

        int nx = x+dx[dir], ny = y+dy[dir];

        if(nx>=0 && nx<n && ny>=0 && ny<n && nums[nx][ny]==0)
            x = nx, y = ny;
        else
            {
                dir = (dir+1)%4;
                x = x+dx[dir], y = y+dy[dir];
            }
    }


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout << nums[i][j] << " ";
        cout << "\n";
    }
    return 0;
}