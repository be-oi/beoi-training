#include <bits/stdc++.h>
using namespace std;

int match(const string& s, const string& pat)
{
    string S = pat + "$" + s;
    int n = S.length();
    vector<int> Z(n);
    int l = -1, r = -1;

    for (int i = 1; i < n; i++)
    {
        if (i > r) //Outside furthest Z-box
        {
            int j;
            for (j = i; j < n && S[j] == S[j-i]; j++);
            Z[i] = j - i;
            l = i;
            r = j - 1;
        }
        else
        {
            int inside = r - i + 1;
            int corresponding = i - l;
            if (Z[corresponding] < inside)
            {
                Z[i] = Z[corresponding];
            }
            else //Need to grow beyond r
            {
                int j;
                for (j = r + 1; j < n && S[j] == S[j - i]; j++);
                Z[i] = j - i;
                l = i;
                r = j - 1;
            }
        }
    }

    for (int i = 1; i < n; i++)
        if (Z[i] == pat.length())
            return i - pat.length() - 1; //Don't forget to subtract the sentinel
    return -1;
}

int main()
{
    cout << match("ab", "c") << endl;
    cout << match("abcdef", "aa") << endl;
    cout << match("abcdef", "ef") << endl;
    cout << match("abcdef", "ab") << endl;
    cout << match("abcdef", "abcdef") << endl;
    cout << match("ab", "abcdef") << endl;
    cout << match("aaaaaaaa", "aaa") << endl;
    cout << match("I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN", "SEVENTY SEVEN") << endl;
}
