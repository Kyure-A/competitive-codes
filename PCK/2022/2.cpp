#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int d[2];
    int m[2];
    cin >> d[0];
    cin >> m[0];
    cin >> d[1];
    cin >> m[1];
    double heinetu = d[1] + (m[1] * 0.1);
    double sokuteinetu = d[0] + (m[0] * 0.1);
    
    if (sokuteinetu >= 37.5) 
    {
        cout << 2 << endl;
    }
    else if (sokuteinetu >= heinetu && sokuteinetu < 37.5)
    {
        cout << 1 << endl;
    }

    else if (sokuteinetu < heinetu) 
    {
        cout << 0 << endl;
    }
}