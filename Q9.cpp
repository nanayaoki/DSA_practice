#include <bits/stdc++.h>
using namespace std;

// Function to check operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') 
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to apply an operator on two numbers
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b == 0 ? 0 : a / b; // avoid divide by zero
    }
    return 0;
}

// Main evaluation function
int evaluate(string exp) {
    stack<int> values;     // to store numbers
    stack<char> ops;       // to store operators

    for (int i = 0; i < exp.length(); i++) {

        // Skip spaces
        if (exp[i] == ' ')
            continue;

        // If current char is '('
        else if (exp[i] == '(')
            ops.push(exp[i]);

        // If current char is a digit → extract full number
        else if (isdigit(exp[i])) {
            int val = 0;
            while (i < exp.length() && isdigit(exp[i])) {
                val = (val * 10) + (exp[i] - '0');
                i++;
            }
            values.push(val);
            i--; // adjust because loop will increase i
        }

        // If current char is ')'
        else if (exp[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(val1, val2, op));
            }
            ops.pop(); // remove '('
        }

        // If operator + - * /
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(exp[i])) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(val1, val2, op));
            }
            ops.push(exp[i]);
        }
    }

    // Apply remaining operators to remaining values
    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperation(val1, val2, op));
    }

    return values.top(); // final result
}

int main() {
    string expression;
    cout << "Enter infix expression: ";
    getline(cin, expression);

    cout << "Result = " << evaluate(expression) << endl;
    return 0;
}
