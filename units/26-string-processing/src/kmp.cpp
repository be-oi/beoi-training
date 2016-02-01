#include <bits/stdc++.h>
using namespace std;

vector<int> precompute(string pat)
{
    vector<int> L(pat.length() + 1);
    L[0] = -1; L[1] = 0;
    for (int i = 2; i <= pat.length(); i++)
    {
        int j = L[i-1];
        while (j >= 0 && pat[j] != pat[i-1])
            j = L[j];
        L[i] = j + 1;
    }
    return L;
}

int match(string s, string pat)
{
    vector<int> L = precompute(pat);
    int j = 0;  //The current index for L
    for (int i = 0; i < s.length(); i++)
    {
        while (j >= 0 && s[i] != pat[j])
            j = L[j];
        j++;
        if (j == pat.length())
            //Found a match, reconstruct the beginning of the substring
            return i + 1 - j;
    }
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
    cout << match("i do not like seventy sev but seventy seventy seven", "seventy seven") << endl;
}
