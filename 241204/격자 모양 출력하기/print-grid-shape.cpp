#include <iostream>
using namespace std;
int sqr[10][10];

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    while(m--)
    {
        int x, y;
        cin >> x >> y;
        sqr[x-1][y-1]= x*y;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout << sqr[i][j] << " ";
        cout << "\n";
    }
    return 0;
}