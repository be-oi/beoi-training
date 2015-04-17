#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,double> point;

int main()
{
    int T;
    cin >> T;
    for (int t=0; t<T; t++)
    {
        int n;
        cin >> n;
        vector<point> convex;
        
        for (int i=0; i<n; i++)
        {
            double coef;
            cin >> coef;
            double y = log(coef);
            int x = i;
            while (convex.size() >= 2)
            {
                point p1 = convex[convex.size()-1], p2 = convex[convex.size()-2];
                int x1 = p1.first, x2 = p2.first;
                double y1 = p1.second, y2 = p2.second;
                if ((y-y1)*(x-x2) >= (y-y2)*(x-x1))
                    convex.pop_back();
                else
                    break;
            }
            convex.push_back(point(x,y));
        }
        
        for (int i=0; i<convex.size(); i++)
        {
            if (i != 0)
                cout << ' ';
            cout << convex[i].first;
        }
        cout << endl;
    }
}
