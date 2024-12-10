#include <iostream>
using namespace std;

int adj[100][100];
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;

    while(k--)
    {
        int r, c, cnt=0;
        cin >> r >> c;

        adj[r-1][c-1] = 1;

        int x=r-1, y=c-1;
        for(int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<n && adj[nx][ny]==1)
                cnt++;
        }

        if(cnt==3) cout << 1;
        else cout << 0;
        cout << "\n";
    }

    return 0;
}