#include <iostream>
using namespace std;

int n_map[100][100];
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

int main() {
    // 여기에 코드를 작성해주세요.
    int n, ans=0;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cin >> n_map[i][j];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int cnt = 0;

            for(int d=0; d<4; d++)
            {
                int nx = i+dx[d], ny = j+dy[d];

                if(nx>=0 && nx<n && ny>=0 && ny<n && n_map[nx][ny]==1)
                    cnt += 1;
            }

            if(cnt >= 3) ans += 1;
        }
    }

    cout << ans;
    return 0;
}