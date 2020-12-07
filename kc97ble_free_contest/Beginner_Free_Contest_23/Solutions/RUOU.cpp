#include <bits/stdc++.h>

using namespace std;

const string ruou[] = {"ABSINTH", "TEQUILA", "VODKA", "WHISKEY", "WINE", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE"};

int convert2num(string st) {
    int x = 0;
    for (char c : st) {
        if ('0' <= c && c <= '9') {
            x = x * 10 + c - '0';
        } else return -1;
    }
    return x;
}
int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        string st;
        cin >> st;
        int num = convert2num(st);
        if (num == -1) {
            for (string x : ruou) {
                if (st == x) {
                    ++cnt;
                }
            }
        } else {
            if (num < 18) ++cnt;
        }
    }
    cout << cnt;
}