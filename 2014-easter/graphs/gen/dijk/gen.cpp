#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
    int n=10000;
    int sum=0;
    cout << n << ' ' << n-1 << endl;
    for(int i=0; i<n-1; i++)
    {
        int w=rand()%1000+1;
        cout << i << ' ' << i+1 << ' ' << w << endl;
        sum += w;
    }
    cout << endl << sum << endl;
}
