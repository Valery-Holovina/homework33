//
//  main.cpp
//  homework33
//
//  Created by Valery on 12.06.2025.
//

//#include <iostream>
//#include "WebBrowser.h"
//#include "MyStack.h"
//using namespace std;
//
//int main(int argc, const char * argv[]) {
//    WebBrowser browser;
//
//       browser.visit("google.com");
//       browser.visit("github.com");
//       browser.visit("stackoverflow.com");
//
//       browser.back(); 
//       browser.back();
//       browser.forward();
//
//       browser.visit("openai.com");
//
//       browser.show();
//    return 0;
//}

#include <iostream>
#include <stack>
#include <string>
using namespace std;


int toInt(const string& s) {
    int result = 0;
    int i = 0;
    bool negative = false;

    if (s[i] == '-') {
        negative = true;
        i++;
    }

    for (; i < (int)s.size(); i++) {
        result = result * 10 + (s[i] - '0');
    }

    return negative ? -result : result;
}


int calculateRPN(const string& expr) {
    stack<int> s;
    int n = expr.size();
    int i = 0;

    while (i < n) {
        while (i < n && expr[i] == ' ') i++;
        if (i >= n) break;

        string token = "";

       
        if (isdigit(expr[i]) || expr[i] == '-') {
            token += expr[i++];
            while (i < n && isdigit(expr[i])) {
                token += expr[i++];
            }
            s.push(toInt(token));
        } else {
            
            if (s.size() < 2) {
                cout << "Помилка: недостатньо операндів для операції." << endl;
                return 0;
            }
            char op = expr[i++];
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            int result;

            if (op == '+') result = a + b;
            else if (op == '-') result = a - b;
            else if (op == '*') result = a * b;
            else if (op == '/') {
                if (b == 0) {
                    cout << "Помилка: ділення на нуль." << endl;
                    return 0;
                }
                result = a / b;
            } else {
                cout << "Невідомий оператор: " << op << endl;
                return 0;
            }
            s.push(result);
        }
    }

    if (s.size() != 1) {
        cout << "Помилка: некоректний вираз." << endl;
        return 0;
    }

    return s.top();
}

int main() {
    string expr = "8 2 5 * + 1 3 2 * + 4 + +"; //29
    cout << "Результат: " << calculateRPN(expr) << endl;
    return 0;
}


