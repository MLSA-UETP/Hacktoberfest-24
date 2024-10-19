#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    deque<int> d;
    vector<int> ans;
    int k = 3;  // Window size

    // Process the first k elements (first window)
    for (int i = 0; i < k; i++) {
        while (!d.empty() && a[d.back()] < a[i]) {
            d.pop_back();
        }
        d.push_back(i);
    }
    ans.push_back(a[d.front()]);

    // Process the remaining elements
    for (int i = k; i < n; i++) {
        // Remove elements not within the window
        if (d.front() == i - k) {
            d.pop_front();
        }
        // Remove elements that are smaller than the current element
        while (!d.empty() && a[d.back()] < a[i]) {
            d.pop_back();
        }
        d.push_back(i);

        // The element at the front of the deque is the maximum for this window
        ans.push_back(a[d.front()]);
    }

    // Print the results
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
