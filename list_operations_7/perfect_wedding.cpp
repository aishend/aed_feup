#include <iostream>
#include <stack>
#include <list> 
#include <string>
using namespace std;
// (), [] or {}



struct Pair {
    char type; // ( '(', '[', '{' )
    int openIndex;
    int closeIndex;
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int main() {
    string expression;
    getline(cin, expression);

    stack<pair<char, int>> st; //stores brackets and its position+
    bool badlyMatched = false;
    bool hasBrackets = false;
    list<Pair> matchedPairs; //stores matched pairs

    for (int i = 0; i < expression.length(); i++) {
        char currentChar = expression[i]; 

        //opening brackets - push to stack 
        if (currentChar == '(' || currentChar == '[' || currentChar == '{') {
            st.push({currentChar, i});
            hasBrackets = true;
        }
        //closing brackets - check for matching opening bracket
        else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
            hasBrackets = true;

            if (st.empty()) {
                badlyMatched = true; //no opening bracket for this closing bracket
                break;
            }

            char openChar = st.top().first;
            int openIndex = st.top().second;


            if (!isMatchingPair(openChar, currentChar)) {
                badlyMatched = true; //mismatched pair
                break;
            }

            //matched pair

            Pair p; 
            p.type = openChar;
            p.openIndex = openIndex;
            p.closeIndex = i;
            matchedPairs.push_back(p);
            st.pop();
        }
    }

    //if stack is not empty, there are unmatched opening brackets
    if (!hasBrackets) {
        cout << "no brides and grooms to marry" << endl;
    } 
    else if (badlyMatched || !st.empty()) {
        cout << "badly matched pairs" << endl;
    } 
    else {
        for (const auto& pair : matchedPairs) {
            string pairStr;
            if (pair.type == '(') pairStr = "()";
            else if (pair.type == '[') pairStr = "[]";
            else pairStr = "{}";
            cout << pairStr << " " << pair.openIndex << " " << pair.closeIndex << endl;
        }
        return 0; 
    }
    
}