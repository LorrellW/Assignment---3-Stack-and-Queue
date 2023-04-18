//Lorrell Winfield 
//Assignment 3 - Binary Tree (stack)
//4 APR 2023
//ExpressionManager.cpp

#include "ExpressionManager.h"
#include <sstream>
#include <typeinfo>
#include <iomanip>
#include <ostream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


//functions
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';  //Character comparasion
}

int precedence(char op) {     //Character comparasion
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    default:
        return -1;
    }
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;

    for (char c : infix) {    
        if (isOperator(c)) {                                             //If the character is an operator
            while (!s.empty() && precedence(s.top()) >= precedence(c)) { //While there are operators in the stack with higher or equal precedence
                postfix += s.top();                                      //Pop the operator from the stack and append it to the postfix notation
                s.pop();
            }
            s.push(c);                                                   //Push onto the stack
        }
        else if (c == '(') {  //If the character is an opening parenthesis
           
            s.push(c);        //Push the opening parenthesis onto the stack
        }
        else if (c == ')') {  //If the character is a closing parenthesis
          
            while (!s.empty() && s.top() != '(') {  //While there are operators in the stack that haven't been enclosed by the opening parenthesis
              
                postfix += s.top();                 //Pop the operator from the stack and append it to the postfix notation
                s.pop();
            }
            s.pop();                                //Pop the opening parenthesis from the stack
        }
  
        else if (c >= '0' && c <= '9') {  //If the character is an operand
          
            postfix += c;               //Append the operand to the postfix notation
        }
    }
 
    while (!s.empty()) {     //While there are still operators in the stack
        postfix += s.top();  //Pop the operator from the stack and append it to the postfix notation
        s.pop();
    }
    return postfix;          //Return the postfix notation
}

bool isBalanced(string expression) {
    stack<char> s;

    for (char c : expression) {
       
        if (c == '(' || c == '{' || c == '[') {     //If the character is an opening parenthesis
            s.push(c);                              //Push the opening parenthesis onto the stack
        }
        else if (c == ')' || c == '}' || c == ']') { //If the character is a closing parenthesis
            if (s.empty()) {                        //If there are no opening parentheses in the stack, return false
                return false;
            }
            char top = s.top();                     //Pop the top opening parenthesis from the stack
            s.pop();
                                                    //If the current closing parenthesis does not match the top opening parenthesis, return false
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();  //If there are still opening parentheses in the stack, return false
}

void call() {     //Print menu to screen, get infix from user & perfom checks, display postfix
    
    string infix;
    cout << "==========================" << endl; //Print menu  & designs
    cout << "Enter an infix expression:" << endl;
    cout << "==========================" << endl;
    cout << "----> ";
    getline(cin, infix);
    cout << endl;

    if (!isBalanced(infix)) {
        cout << "Invalid expression - unbalanced parentheses." << endl;
    }
    else {
        string postfix = infixToPostfix(infix);
        cout << "===================" << endl;
        cout << "Postfix expression:" << endl;
        cout << "===================" << endl;
        cout << "----> ";
        cout << postfix << endl;
    }
}

