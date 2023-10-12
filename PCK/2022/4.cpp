#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    vector<int> c(n);
    int group_sum = n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        group_sum -= c[i];
    }

    if (group_sum == 0) group_sum++;

    cout << group_sum << endl;
    
}