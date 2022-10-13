#include <iostream>
#include "order.h"
#include "Calculator.h"
#include "history.h"

using namespace std;

int main ()
{
	cout<<"Scientific Calculator\n";
	Calculator c1;  //object of Calculator
	string form;    //reading formula in
	string insertToHistory; //to insert into history
	char var;       //reading variable
	double value;   //reading variable value
	float result;
	
	int OnOff=1;	//to activate loop and menu option. any random number but 0 could be used
	Node* head = NULL;
	
	while (OnOff!=0){
		cout<<"\nWhat would you want to do?\n";
		cout<<"1: to make calculation\n";
		cout<<"2: to see calculation history\n";
		cout<<"3: to see calculation instruction\n;
		cout<<"0: shut down\n";
		cin>>OnOff;
		
		//to do a calculation
		if (OnOff==1){
			cout<<"Please, enter your formula:";
			cin>>form;
		
			Calculator userExpression(form);
			if (userExpression.isLegal(form) == false)
    			continue;
    		else{
        	    double result = userExpression.eval();
        	    
        	    string calcResult=to_string(result);
				string equal="=";
				insertToHistory=form+equal+calcResult;        	    
    			cout << "\nResult: " <<  result << "\n\n";
    			push(&head, insertToHistory);
    		}
						
			
		
		//to look at history
		else if(OnOff==2){
			int historyOperation=3;
			while (historyOperation!=0){
				cout<<"\nYour calculation history:\n";
				printHistory(head);
				cout<<"\nwhat do you want to do?\n"
					<<"1: to remove the history\n"
					<<"0: to exit history\n";	
				cin>>historyOperation;
				//delete history
				if(historyOperation==1){
    				cout<<"\ninsert what to delete? (copy the equation to the command, no 0 at the front):"; //remove later
    				string inputDelete;
					cin>>inputDelete;	
					deleteHistory(&head, inputDelete);	//deleting
					historyOperation=3;
				}
				else if(historyOperation==0){
					break;
				}
			}
			
		}
		//to show the calculator instruction
        	else if(OnOff==3){
            		cout<<"Symbol in this calculator: \n";
            		cout <<"/: Division (/)\t\t\t"<<"s: Sin (in rad)\t\t"<<"\t\tx: square root"<<endl;
            		cout <<"*: Multiplication (*)\t\t"<<"c: Cos (in rad)\t\t"<<"\t\ty: log"<<endl;
            		cout <<"-: Subtraction (-)\t\t"<<"t: Tan (in rad)\t\t"<<"\t\tz: ln"<<endl;
            		cout <<"+: Addition (+)\t\t\t"<<"m: Inverse of Sin (in rad)\t\t"<<endl;
            		cout <<"^: Exponent (i^n))\t\t"<<"n: Inverse of Cos (in rad)\t\t"<<endl;
            		cout <<"\t\t\t\t"<<"o: Inverse of Tan (in rad)\t\t"<<endl;

            		cout <<"\nExample of using trigonometric function: \ns90 = sin 90 (in radian)\n\n";

        		}
		//shut down
		else if(OnOff==0){
			cout<<"Thank you";
			return 0;
		}
	}
}
