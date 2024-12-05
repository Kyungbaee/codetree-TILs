#include <iostream>
#include <string>
using namespace std;

string strs[21];

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    while(n--)
    {
        cin >> strs[n]; 
    }

    int cnt=0;
    float avg=0.f;
    char c;
    cin >> c;

    for(int i=0; i<21; i++)
    {
        if(strs[i][0]==c){
            cnt++;
            avg += strs[i].length();
        }
    }

    cout << fixed;
    cout.precision(2);

    cout << cnt << " " << avg/cnt;
    return 0;
}