#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string postfixToInfix(string postfix) {
    stack<string> st;

    for (int i = 0; i < postfix.length(); i++) {
        if (isOperator(postfix[i])) {
            string operand2 = st.top();
            st.pop();
            string operand1 = st.top();
            st.pop();
            string result = "(" + operand1 + postfix[i] + operand2 + ")";
            st.push(result);
        }
        else {
            string operand(1, postfix[i]);
            st.push(operand);
        }
    }

    return st.top();
}

int main() {
    string postfixExpression;
    cout << "Enter postfix expression: ";
    cin >> postfixExpression;

    string infixExpression = postfixToInfix(postfixExpression);
    cout << endl;
    cout << "Infix expression: " << infixExpression << endl;

    return 0;
}
