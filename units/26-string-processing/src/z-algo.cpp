#include <bits/stdc++.h>
using namespace std;

int match(string s, string pat)
{
    string S = pat + "$" + s;
    vector<int> Z(S.length());
    int l = -1, r = -1;

    for (int i = 1; i < S.length(); i++)
    {
        if (i > r) //Outside furthest Z-box
        {
            int len = 0;
            for (int j = i; j < S.length() && S[j] == S[j-i]; j++)
            {
                len++;
            }
            Z[i] = len;
            if (len > 0)
            {
                l = i;
                r = i + len - 1;
            }
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
                int len = 0;
                for (int j = r + 1; j < S.length() && S[j] == S[j - i]; j++)
                {
                    len++;
                }
                Z[i] = inside + len;
                l = i;
                r = i + len - 1;
            }
        }
    }
    for (int i = 1; i < S.length(); i++)
    {
        if (Z[i] == pat.length())
            return i - pat.length() - 1; //Don't forget to subtract the sentinel
    }
    return -1;
}

int main()
{
    cout << match("abcdef", "aa") << endl;
    cout << match("abcdef", "ef") << endl;
    cout << match("abcdef", "ab") << endl;
    cout << match("abcdef", "abcdef") << endl;
    cout << match("ab", "abcdef") << endl;
    cout << match("aaaaaaaa", "aaa") << endl;
    cout << match("I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN", "SEVENTY SEVEN") << endl;
}
