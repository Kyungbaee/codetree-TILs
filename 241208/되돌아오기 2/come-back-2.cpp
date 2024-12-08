#include <iostream>
#include <string>
using namespace std;

int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};

int main() {
    // 여기에 코드를 작성해주세요.
    int x=0,y=0,dir=0;
    string s;
    cin >> s;

    for(int i=0; i<s.length(); i++)
    {
        char c = s[i];

        if(c=='F')
            x += dx[dir], y += dy[dir];
        if(c=='L')
            dir = (dir+3)%4;
        if(c=='R')
            dir = (dir+5)%4;
        
        if(x==0 && y==0)
        { 
            cout << i+1;
            break;
        }
    }
    if(x!=0 || y!=0) cout << -1;

    return 0;
}