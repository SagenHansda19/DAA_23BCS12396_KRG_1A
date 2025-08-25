#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    double myPow(double x, int nn) {
        long long n = nn;
        if (n == 0) return 1;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        double h = myPow(x, n / 2);
        if (n & 1) return x * h * h;
        return h * h;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    double x;
    int nn;
    cin >> x >> nn;
    cout << sol.myPow(x, nn);
    return 0;
}
