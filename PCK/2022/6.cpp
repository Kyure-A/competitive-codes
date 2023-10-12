// wa

#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    long long int t;
    cin >> t;
    vector<long long int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    long long int answer = 0;
    int missing = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            long long int split_time = a[i] - t;
            if (split_time > 0) 
            {
                answer++;
                missing = 0;
            }
            else 
            {
                missing++;
            }
        }

        if (i > 0)
        {
            long long int split_time = a[i] - a[i - 1];
            if (split_time >= t)
            {
                answer++;
                missing = 0;
            }
            else
            {
                missing++;
                a[i] += t - split_time ;
            }
        }

        if (missing == 2) break;
    }

    cout << answer << endl;
    
}