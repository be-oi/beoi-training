#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> val, length;
string s;

int main()
{
    cin >> s;
    int i=0;
    while(i < s.size())
    {
        val.push_back(s[i]-'0');
        int start=i;
        while((++i) < s.size() && s[i] == '0');
        length.push_back(i-start);
    }
    int sumlen=0;
    int firstdig=val[0];
    int maxi=0;
    for(int i=0; i<val.size(); i++)
    {
        if(sumlen < length[i] || (sumlen == length[i] && firstdig < val[i]))
            maxi = i;
        sumlen += length[i];
    }
    cout << val.size()-maxi << endl;
}
