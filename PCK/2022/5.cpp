#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    vector<long long int> a(n);
    vector<int> s(n);

    long long int tarinai_max = -1;
    long long int tarinai_min = 9000000000;
    long long int tyoudo_max = -1;
    long long int tyoudo_min = 9000000000;
    long long int yudesugi_max = -1;
    long long int yudesugi_min = 9000000000;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> s[i];

        if (s[i] == 0) 
        {
            tarinai_max = max(tarinai_max, a[i]);
            tarinai_min = min(tarinai_min, a[i]);
        }

        else if (s[i] == 1) 
        {
            tyoudo_max = max(tyoudo_max, a[i]);
            tyoudo_min = min(tyoudo_min, a[i]);
        }

        else if (s[i] == 2) 
        {
            yudesugi_max = max(yudesugi_max, a[i]);
            yudesugi_min = min(yudesugi_min, a[i]);
        }
    }

    int m;
    cin >> m;
    vector<int> b(m);

    for (int i = 0; i < m; i++)
    {   
        cin >> b[i];
        if (b[i] <= tarinai_max) cout << 0 << endl;
        else if (tyoudo_min <= b[i] && b[i] <= tyoudo_max) cout << 1 << endl;
        else if (yudesugi_min <= b[i]) cout << 2 << endl;
        else if (tarinai_max < b[i] && b[i] < tyoudo_min) cout << -1 << endl;
        else if (tyoudo_max < b[i] && b[i] < yudesugi_min) cout << -1 << endl;
    }
}
