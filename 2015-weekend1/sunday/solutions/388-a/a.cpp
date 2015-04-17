#include<iostream>
#include<algorithm>

using namespace std;

int n;
int x[10000];

bool possible(int k)
{
    for(int i=0; i<n; i++)
        if(x[i] < i/k)
            return false;
    return true;
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> x[i];
    sort(x,x+n);
    //for(int i=1; i<=n; i++) cout << possible(i) << endl;
    int a=0, b=n; // Searching for the largest that doesn't work
    while(a+1 < b)
    {
        int middle = (a+b)/2;
        //cout << "Testing " << middle << endl;
        if(possible(middle))
            b = middle;
        else
            a = middle;
    }
    cout << b << endl;
}
