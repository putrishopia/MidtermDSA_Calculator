#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "order.h"

using std::cout; using std::cin;
using std::endl; using std::string;

class Calculator
{
private:
	string infix;
	order <double> operands;
	order <char> operators;

public:
	Calculator() { string infix = ""; }
	Calculator(string userExpr) { infix = userExpr; }
    // input validator
	bool isLegal(string infix)
	{
		bool legal = true;
		int parenthesisCount = 0;
		try
		{
			for (size_t i = 0; i < infix.length(); i++)
			{
				switch (infix[i])
				{
				case '(': parenthesisCount++; break;
				case ')': parenthesisCount--; break;
				default: break;
				}
			}
			if (parenthesisCount != 0)
			{
				legal = false;
				throw 0;
			}
		}
		catch (...)
		{
			cout<<"Error: Unmatched Parenthesis (Brackets)"<<endl<<endl;;
		}
		return legal;
	}
    // operand checker, ensuring that the input are numbers
	bool isOperand(char number)
	{
		if ((number >= '0' && number <= '9')||number=='p')
			return true;
		else
			return false;
	}
    // operator checker, ensuring that there are only mathematical operators
	bool isOperator(char op)
	{
		if (op == '+' || op == '-' || op == '*' || op == '/' || op == '(' || op == ')' ||op == '[' || op == ']' || op == '{' || op == '}' || op == '^'){
            return true;
        }
		else{
			return false;
        }
	}
