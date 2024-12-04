#include <iostream>
using namespace std;
int sqr1[11][11];
int sqr2[11][11];

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin >> sqr1[i][j];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin >> sqr2[i][j];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(sqr1[i][j]==sqr2[i][j])
            {
                sqr1[i][j] = 0;
            }
            else sqr1[i][j] = 1;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout << sqr1[i][j] << " ";
        cout << "\n";
    }
    return 0;
}