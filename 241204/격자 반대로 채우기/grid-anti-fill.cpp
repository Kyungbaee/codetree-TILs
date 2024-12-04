#include <iostream>
using namespace std;
int sqr[10][10];
int main() {
    // 여기에 코드를 작성해주세요.
    int n, cnt=1;
    cin >> n;
    
    int dir=n;
    for(int i=n-1; i>=0; i--)
    {
        if((n-1-i)%2==1){
            for(int j=0; j<n; j++)
                sqr[j][i] = cnt++;
        }
        else
        {
            for(int j=n-1; j>=0; j--)
                sqr[j][i] = cnt++;
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