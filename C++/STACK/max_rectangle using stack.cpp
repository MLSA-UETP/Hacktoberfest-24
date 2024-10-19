#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int max_rectangle(vector<int> a) {
    stack<int> st;
    int ans = 0;
    int n = a.size();
    int i = 0;

    while (i < n) {
        if (st.empty() || a[st.top()] <= a[i]) {
            st.push(i++);
        } else {
            int t = st.top();
            st.pop();
            int h = a[t];
            int len = st.empty() ? i : i - st.top() - 1;
            ans = max(ans, h * len);
        }
    }

    while (!st.empty()) {
        int t = st.top();
        st.pop();
        int h = a[t];
        int len = st.empty() ? i : i - st.top() - 1;
        ans = max(ans, h * len);
    }

    return ans;
}

int main() {
    vector<int> a = {2, 3, 6, 7, 1};
    cout << "Maximum rectangular area: " << max_rectangle(a) << endl;
    return 0;
}
