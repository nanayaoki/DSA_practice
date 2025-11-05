#include <iostream>
#include <stack>
using namespace std;

int minReversals(string exp) {
    int len = exp.length();
    
    // If length is odd → cannot be balanced
    if (len % 2 != 0)
        return -1;

    stack<char> st;

    // Remove balanced pairs
    for (int i = 0; i < len; i++) {
        if (exp[i] == '{')
            st.push('{');
        else { // exp[i] == '}'
            if (!st.empty() && st.top() == '{')
                st.pop(); // balanced pair
            else
                st.push('}');
        }
    }

    // Count remaining unmatched brackets
    int m = 0, n = 0;

    while (!st.empty()) {
        if (st.top() == '{')
            m++;
        else
            n++;
        st.pop();
    }

    // Formula
    int reversals = (m + 1) / 2 + (n + 1) / 2;
    return reversals;
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;

    int result = minReversals(exp);
    cout << "Minimum reversals needed = " << result;

    return 0;
}
