//
//  WebBrowser.h
//  homework33
//
//  Created by Valery on 12.06.2025.
//

#ifndef WebBrowser_h
#define WebBrowser_h

#include <iostream>
#include <string>
#include "MyStack.h"
using namespace std;



class WebBrowser {
    myStack::Stack<string> backPage;
    myStack::Stack<string> forwardPage;
    string currentPage;
public:
    WebBrowser() : currentPage("Home") {}

    void visit(const string& url) {
        backPage.push_back(currentPage);
        currentPage = url;
      
        while (!forwardPage.isEmpty()) {
            forwardPage.pop_back();
        }
        cout << "Visited: " << currentPage << endl;
    }

    string back() {
        if (backPage.isEmpty()) {
            cout << "No pages to go back to." << endl;
            return currentPage;
        }
        forwardPage.push_back(currentPage);
        currentPage = backPage.top();
        backPage.pop_back();
        cout << "Went back to: " << currentPage << endl;
        return currentPage;
    }

    string forward() {
        if (forwardPage.isEmpty()) {
            cout << "No pages to go forward to." << endl;
            return currentPage;
        }
        backPage.push_back(currentPage);
        currentPage = forwardPage.top();
        forwardPage.pop_back();
        cout << "Went forward to: " << currentPage << endl;
        return currentPage;
    }

    void show() const {
        cout << "\n------ Browser State -----\n";
        cout << "Back history: ";
        backPage.showStack();
        cout << "Current page: " << currentPage << endl;
        cout << "Forward history: ";
        forwardPage.showStack();
        cout << "=====================\n";
    }
};

#endif /* WebBrowser_h */
