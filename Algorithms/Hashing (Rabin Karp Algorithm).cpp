#include<bits/stdc++.h>
using namespace std;
#define ll long long

int mod = 1e9 + 7;
int base = 10;
vector<int> power;
void pow_calc(string s) {
    int n = s.size();
    vector<int> temp(n + 1);
    temp[0] = 1;
    for(int i = 1; i <= n; i++) {
        temp[i] = temp[i - 1] * base;
    }
    power = temp;
}
void prefix_hash(string s, vector<int> &ph) {
    ph[0] = s[0] - '0';
    for(int i = 1; i < s.size(); i++) {
        ph[i] = ph[i - 1] * base + s[i] - '0';
    }
}
int hash_calc(int l, int r, vector<int> &ph) {
    if(l == 0) return ph[r];
    return ph[r] - ph[l - 1] * power[r - l + 1];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string s;
    cin >> s;
    pow_calc(s);
    string pat;
    cin >> pat;
    int y = stoi(pat);
    int n = s.size();
    int m = pat.size();
    vector<int> ph(n);
    prefix_hash(s, ph);
    // r (i + m - 1) cannot be out of the boundary, <= n - 1;
    for(int i = 0; i + m - 1 < n; i++) {
        int x = hash_calc(i, i + m - 1, ph);
        if(x == y) {
            cout << pat << " " << "found at " << i << '\n'; 
        }
    }


	return 0;
}
