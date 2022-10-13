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
						
			OnOff=3;
		}
		
		//to look at history
		else if(OnOff==2){
			int historyOperation=3;
			while (historyOperation!=0){
				cout<<"\nYour calculation history:\n";
				printHistory(head);
				cout<<"\nwhat do you want to do?\n"
					<<"1: to remove a history\n"
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
		
		//shut down
		else if(OnOff==0){
			cout<<"Thank you";
			return 0;
		}
	}
}
