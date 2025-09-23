#include<bits/stdc++.h>
using namespace std;
#define ll long long

void lps_const(string p, vector<int> &lps) {
    int pre = 0;
    int suff = 1;
    lps[0] = 0;
    while(suff < p.size()) {
        if(p[pre] == p[suff]) {
            lps[suff] = pre + 1;
            pre++;
            suff++;
        }
        else {
            if(pre == 0) suff++;
            else {
                pre = lps[pre - 1];
            }
        }

    }
}
int index(string s, string pat, vector<int> &lps) {
    int first = 0;
    int second = 0;
    while(first < s.size() && second < pat.size()) {
        if(s[first] == pat[second]) {
            first++;
            second++;
        }
        else {
            if(second == 0) first++;
            else {
                second = lps[second - 1];
            }
        }
    }
    if(second == pat.size()) return first - pat.size();
    else return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    string pat;
    cin >> pat;
    int n = s.size();
    int m = pat.size();
    vector<int> lps(m);
    lps_const(pat, lps);
    cout << index(s, pat, lps);

    return 0;
}
