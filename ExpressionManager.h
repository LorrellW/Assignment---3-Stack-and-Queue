//Lorrell Winfield 
//Assignment 3 - Binary Tree (stack)
//4 APR 2023
//ExpressionManager.h

#pragma once
#include <sstream>
#include <typeinfo>
#include <iomanip>
#include <ostream>
#include <iostream>
#include <stack>

using namespace std;

//functions
bool isOperator(char c);
int precedence(char op);
string infixToPostfix(string infix);
bool isBalanced(string expression);
void call();

