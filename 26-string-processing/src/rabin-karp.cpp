#include <bits/stdc++.h>
using namespace std;

const int B = 17;
const int H = 12632251;

int hash_pattern(string pat, int start, int end)
{
    int h = 0;
    for (int i = start; i <= end; i++)
    {
        h = ((h * B) % H + pat[i]) % H;
    }
    return h;
}

bool check(string s, string pat, int start)
{
    for (int i = 0; i < pat.length(); i++)
    {
        if (s[start + i] != pat[i])
            return false;
    }
    return true;
}

int modpow(int exp) { //This can be done in O(log N)
  int result = 1;
  for (int i = 0; i < exp; i++)
  {
      result = (result * B) % H;
  }
  return result;
}

int match(string s, string pat)
{
    if (pat.length() > s.length()) return -1;
    int k = pat.length();
    int Hp = hash_pattern(pat, 0, k - 1);
    int Hs = hash_pattern(s, 0, k - 1);
    int Bk = modpow(k-1);
    for (int i = 0; i <= s.length() - k; i++)
    {
        if (Hs == Hp && check(s, pat, i))
        {
            return i;
        }
        Hs = ((B * (Hs - (s[i] * Bk) % H)) % H + s[i+k]) % H;
        if (Hs < 0) Hs += H;
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
    cout << match("i do not like seventy sev but seventy seventy seven", "seventy seven") << endl;
}
