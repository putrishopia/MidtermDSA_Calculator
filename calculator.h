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
    // operator for trigonometric functions
	double trigonometry(char character, double value)
	{
       	double sinus = sin(value);
	    double cosin = cos(value);
	    double tangent = tan(value);
		switch(character) {
    	    case 's': return sinus; break;
            case 'c': return cosin; break;
            case 't': return tangent; break;
		}
	}
	// operator for extended functions
	double extended(char character, double value)
	{
	    double x = sqrt(value);
	    double y = log10(value);
	    double z = log(value);
	    switch(character) {
	        case 'x': return x; break;
	        case 'y': return y; break;
	        case 'z': return z; break;
	    }
	}
    // whole evaluation process combined
	double eval()
	{
		double finalAnswer;
		for (size_t i = 0; i < infix.length(); i++)
		{
			if (isOperand(infix[i]) == true)
			{
				double currentNumber = 0;
				while (i < infix.length() && ( isOperand(infix[i]) || infix[i] == '.'))
				{
          			if (infix[i] == '.')
					{
            			int counter = 0;
            			int dec = 0;
            			i++;
            			for(; i < infix.length(); i++)
						{
              				if (isOperand(infix[i]))
							{
                				dec = 10 * dec + (int)(infix[i] - '0');
                				counter++;
              				}
              				else break;
            			}
            			double calculatedDec= (double)dec / (double)(pow(10, counter));
            			// cout << currentNumber << endl;
            			// cout << fixed << setprecision(5) << calculatedDec << endl;
            			currentNumber += calculatedDec;

      	    		}
        	  		else
					{
						if (infix[i]!='p')
						{
							currentNumber = 10 * currentNumber + (double)(infix[i] - '0');
						}
						if (infix[i]=='p'&&currentNumber==0)
						{
							currentNumber=M_PI;
						}
						else if (infix[i]=='p'&&currentNumber!=0)
						{
							currentNumber=currentNumber*M_PI;
						}
						++i;
          			}
				}
				operands.push(currentNumber);
				--i;
			}

						else if(isTrigonometry(infix[i])) {
			    if (infix[i] == 's' || infix[i] == 'c' || infix[i] == 't') {
			        operators.push(infix[i]);
			    }
				char opTrig = operators.pop();
				double val = 0;
					while ( isOperand(infix[i + 1]) == true)
					  	        {
					  	            if (infix[i+1] != 'p')
					  	            {
					  	            val =  10 * val + (double)(infix[i + 1] - '0');
					  	            }
					  	            i++;
					  	            if (infix[i+1]=='p'&& val !=0)
						                {
							                val=val*M_PI;
						                }
					  	            }
				double hasilTrig = trigonometry(opTrig, val);
				operands.push(hasilTrig);
			}

			else if(isExtended(infix[i])) {
			    if(infix[i] == 'x' || infix[i] == 'y' || infix[i] == 'z') {
			        operators.push(infix[i]);
			    }
			    char opEx = operators.pop();
			    double angka = 0;
				 while ( isOperand(infix[i + 1]) == true)
					{
					 if (infix[i+1] != 'p')
					     {
					  	angka =  10 * angka + (double)(infix[i + 1] - '0');
					  	i++;
					     }
					  if (infix[i+1]=='p'&& angka !=0)
						                {
							                angka = angka*M_PI;
						                }
					  	            }
			    double hasilEx = extended(opEx, angka);
			    operands.push(hasilEx);
			}

			else if (infix[i] == '(')
				operators.push(infix[i]);

			else if (infix[i] == ')')
			{
				while (operators.top() != '(')
				{
					double valueOne = operands.pop();
					double valueTwo = operands.pop();
					char op = operators.pop();
					operands.push(operate(valueTwo,valueOne,op));
				}
				operators.pop();
			}
			
