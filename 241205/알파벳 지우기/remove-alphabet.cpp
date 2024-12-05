#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string a, b, aa="", bb="";
    cin >> a >> b;

    for(int i=0; i<a.length(); i++)
    {
        if(a[i]>='A' && a[i]<='z')
            continue;
        else
            aa += a[i];
    }

    for(int i=0; i<b.length(); i++)
    {
        if(b[i]>='A' && b[i]<='z')
            continue;
        else
            bb += b[i];
    }

    cout << stoi(aa) + stoi(bb);
    return 0;
}