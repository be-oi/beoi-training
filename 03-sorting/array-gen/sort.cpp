#include <bits/stdc++.h>
#define int long long
#define P(x) {if (debug) cout << x << endl;}
#define H(x) P(#x << ": " << (x))
#define FR(i,a,b) for (int i=(a); i<(b); i++)
#define F(i,n) FR(i,0,n)
#define D(i,n) for (int i=(n); i-->0;)
#define S(s) (int)(s).size()
#define ALL(v) v.begin(), v.end()
#define MI(a,v) a = min(a,v)
#define MA(a,v) a = max(a,v)
#define V vector
#define pb push_back
#define mt make_tuple
using namespace std;
template<class T> ostream& operator<<(ostream& os, V<T> v) {
    F(i,S(v)) os<<(i?" ":"")<<v[i]; return os;}
const bool debug = 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    V<int> a(n);
    F(i,n) cin >> a[i];
    sort(ALL(a));
    F(i,n) cout<<a[i]<<"\n";
}
