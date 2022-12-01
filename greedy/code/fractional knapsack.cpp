#include<bits/stdc++.h>
using  namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i, a, b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
#define sz 100002

bool compare(pair<int,int> a, pair<int,int> b) {
    double v1 = (double) a.ff / a.ss;
    double v2 = (double) b.ff / b.ss;

    return v1 > v2;
}

/*

    Built in function
    1. __builtin_popcount(x): count total 1's in X
       __builtin_popcountl(x) , __builtin_popcountll(x)

    2. __builtin_parity(x) : checks odd parity of X


    3. __builtin_clz(x) : count leading zero of X in binary format
       __builtin_clzl(x) , __builtin_clzll(x)

    4. __builtin_ctz(x) : count trailing zero of x in binary format
       __builtin_ctzl(x)  , __builtin_ctzll(x)

*/

int main() {

    vector<pair<int,int>> vp;
    int n, w, ans = 0, i, a, b;
    scanf("%d %d", &n, &w);

    for(i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        vp.push_back(make_pair(a,b));
    }

    sort(vp.begin(), vp.end(), compare);

    /*for(i = 0; i < n; i++) {
        printf("%d %d\n", vp[i].first, vp[i].second);
    } */

    for(i = 0; i < n; i++) {
        a = vp[i].ff; // value
        b = vp[i].ss; // weight

        if(w) {
            if(b <= w) {
                ans += a;
                w -= b;
            }
            else {
                ans += (w*(a/b));
                w = 0;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}

/*
5 20
10 10
12 6
20 5
30 5
9 3

*/
