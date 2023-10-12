#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int x[3];
    int y[3];
    // 0 = goo, 1 = choki, 2 = par

    for (int i = 0; i < 3; i++)
    {
       cin >> x[i] >> y[i];
    }
    
    int win_count = 0;
    int lose_count = 0;
    int aiko_count = 0;

    for (int i = 0; i < 3; i++)
    {
        if (x[i] == y[i])
        {
            aiko_count++;
        }
        
        else if (x[i] == 0 && y[i] == 1)
        {
            win_count++;
        }

        else if (x[i] == 0 && y[i] == 2)
        {
            lose_count++;
        }

        else if (x[i] == 1 && y[i] == 0)
        {
            lose_count++;
        }

        else if (x[i] == 1 && y[i] == 2)
        {
            win_count++;
        }

        else if (x[i] == 2 && y[i] == 0)
        {
            win_count++;
        }

        else if (x[i] == 2 && y[i] == 1)
        {
            lose_count++;
        }
    }

    if (lose_count > win_count) cout << 1 << endl;
    else if (win_count > lose_count) cout << 0 << endl;
    else if (win_count == lose_count) cout << -1 << endl;
}