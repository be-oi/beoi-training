#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> dig)
{
    for (int i=dig.size()-1; i>=0; i--)
    {
        printf("%d", dig[i]);
    }
    printf("\n");
}

vector<int> express(int n)
{
    vector<int> dig;
    while (n != 0)
    {
        dig.push_back(n%10);
        n /= 10;
    }
    return dig;
}

vector<int> multiply(vector<int> a, vector<int> b)
{
    vector<int> dig;
    int carry = 0;
    for (int i=0; i+2 <= a.size()+b.size() || carry > 0; i++)
    {
        int d = carry;
        int minj = max(0, i-(int)b.size()+1);
        int maxj = min(i, (int)a.size()-1);
        for (int j=minj; j<=maxj; j++)
        {
            d += a[j]*b[i-j];
        }
        dig.push_back(d%10);
        carry = d/10;
    }
    return dig;
}

vector<int> fact[1001];

int main()
{
    fact[0] = express(1);
    for (int i=1; i<=1000; i++)
    {
        fact[i] = multiply(fact[i-1], express(i));
    }
    int n;
    while (cin >> n)
    {
        printf("%d!\n", n);
        print(fact[n]);
    }
}
