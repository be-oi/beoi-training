#include <iostream>

#define MAXW 10005

using namespace std;

int height[MAXW];

int main()
{
    int l, h, r;
    while (cin >> l >> h >> r)
    {
        for (int i=l; i<r; i++)
        {
            height[i] = max(height[i], h);
        }
    }
    int cur = 0;
    bool first = true;
    for (int i=0; i<MAXW; i++)
    {
        if (height[i] != cur)
        {
            if (!first)
                cout << ' ';
            cur = height[i];
            cout << i << ' ' << cur;
            first = false;
        }
    }
    cout << endl;
}
