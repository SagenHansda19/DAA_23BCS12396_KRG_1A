#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int>& arr) {
        // code here
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            arr[i]--;
        }
        for (int i = 0; i < n; i++) {
            arr[arr[i] % n] += n;
        }
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] / n;
        }
        return arr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<int> arr;
    int x;
    while (cin >> x) {
        arr.push_back(x);
        if (cin.get() == '\n') break;
    }
    vector<int> ans = sol.frequencyCount(arr);
    for (int i : ans) cout << i << ' ';
    return 0;
}
