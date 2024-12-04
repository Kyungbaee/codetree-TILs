#include <iostream>
using namespace std;
int sqr[10][10];

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 || j==0)
                sqr[i][j] = 1;
            else
            {
                sqr[i][j] = sqr[i][j-1]+sqr[i-1][j]+sqr[i-1][j-1];
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout << sqr[i][j] << " ";
        cout << "\n";
    }
    return 0;
}