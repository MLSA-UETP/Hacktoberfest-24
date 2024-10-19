#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int rain_water(vector<int> a) {
    stack<int> st;
    int ans = 0;
    int n = a.size();
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] < a[i]) {
            int cur = st.top();
            st.pop();
            if (st.empty()) {
                break;
            }
            int len = i - st.top() - 1;
            int height = min(a[st.top()], a[i]) - a[cur];
            ans += height * len;
        }
        st.push(i);
    }
    return ans; 
}

int main() {
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << rain_water(a) << endl; 
    
    return 0;
}
