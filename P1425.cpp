#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int hour = c - a, minute = d - b;
    if (minute < 0)
    {
        hour -= 1;
        minute += 60;
    }
    cout << hour << " " << minute << endl;
    return 0;
}