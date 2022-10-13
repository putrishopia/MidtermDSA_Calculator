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
// checking if spaces appear in user's input
	bool isSpace(char character)
	{
		if (character == ' ' || character == '\r' || character == '\n')
			return true;
		else
			return false;
	}
	// checking if there exists basic trigonometric functions
	bool isTrigonometry(char character)
	{
	    if (character == 's' || character == 'c' || character == 't')
	        return true;
	    else
	        return false;
	}
    // checking if there exists sqrt, log, or ln
	bool isExtended(char character)
	{
	    if(character == 'x' || character == 'y' || character == 'z')
	        return true;
        else
            return false;
	}
    // precedence checker
	int precedence(char character)
	{
		if (character == '^')
			return 4;
		else if (character == '*' || character == '/')
			return 3;
		else if (character == 's' || character == 'c' || character == 't' || character == 'x' || character == 'y' || character == 'z')
			return 2;
		else if (character == '+' || character == '-')
			return 1;
		else if (character == '(' || character == ')' || character == '[' || character == ']' || character == '{' || character == '}')
			return 0;
		else
			return -1;
	}
    // operator between two values method
	double operate(double valueOne, double valueTwo, char op)
	{


		switch (op)
		{
		case '+': return valueOne + valueTwo; break;
		case '-': return valueOne - valueTwo; break;
		case '*': return valueOne * valueTwo; break;
		case '/': return valueOne / valueTwo; break;
		case '^': return (double) pow(valueOne, valueTwo); break;
		}
	}
