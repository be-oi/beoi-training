#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int n,x;

int main()
{
    cin >> n;
    int g=0;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        g = gcd(x,g);
    }
    cout << g*n << endl;
}
