#include <cstdlib>
#include <cctype>
#include <iostream>
#include <cstring>
#include "stack.h"
using namespace std;


Stack<int> dc(20);


/*--------------------------------------------
methodP()
Pre:
Nothing is printed to the screen.

Post:
Checks to see if the stack is empty. If it is
not, then the value at the top of the stack
is taken and printed out to the screen.
No changes are made in the stack, and a new
line is printed after this function call.
*/
void methodP()
{
	if(!(dc.isEmpty()))
		cout << dc.top() << endl;
}

/*--------------------------------------------
methodN()
Pre:
Nothing is printed to the screen, and the stack
is unaltered.

Post:
Checks to see if the stack is empty. If it is
not, then the value at the top of stack is removed
and printed to the screen. A new line is not added
after this function call.
*/
void methodN()
{
	if(!(dc.isEmpty()))
		cout << dc.topAndPop() << " ";
}

/*--------------------------------------------
methodF()
Pre:
Nothing is printed to the screen.

Post:
Makes a copy of the stack and checks to see
if that copy is empty. If it is not, then a
loop goes through each entry of the copy and
removes and prints each value. The original
is left unaltered.
*/
void methodF()
{
	Stack<int> copy = dc;
	while (!(copy.isEmpty()))
		cout << copy.topAndPop() << endl;
}

/*--------------------------------------------
methodC()
Pre:
Nothing is printed to the screen.

Post:
Regardless of whether the stack is empty already
or not, a call to the function makeEmpty() in 
stack.cpp is made to delete all entries.
*/
void methodC()
{
	dc.makeEmpty();
}

/*--------------------------------------------
methodD()
Pre:
The stack is unaltered and nothing is printed.

Post:
A duplicate of the current top value of the stack
is made and pushed back onto the stack.
*/
void methodD()
{
	if (!(dc.isEmpty()))
		dc.push(dc.top());
}

/*--------------------------------------------
methodR()
Pre:
The stack is unaltered and nothing is printed.

Post:
The top two values of the stack are taken, 
reversed, and placed back into the stack.
*/
void methodR()
{
	int top = dc.topAndPop();
	int next = dc.topAndPop();
	dc.push(top);
	dc.push(next);
}

/*--------------------------------------------
Pre:
The stack is unaltered and nothing is printed.

Post:
The top two values in the stack are taken,
summed, and the sum is placed back into the stack.
*/
void addition ()
{
	int first = dc.topAndPop();
	int second = dc.topAndPop();
	int sum = first + second;
	dc.push(sum);
}

/*--------------------------------------------
Pre:
The stack is unaltered and nothing is printed.

Post:
The top two values of the stack are taken, and 
the first one popped is subtracted from the 
second one popped. The difference is added
back onto the stack.
*/
void subtraction ()
{
	int first = dc.topAndPop();
	int second = dc.topAndPop();
	int difference = second - first;
	dc.push(difference);
}

/*--------------------------------------------
Pre:
The stack is unaltered and nothing is printed.

Post:
The top two values of the stack are taken, and 
the second one popped is divided by the first 
one popped. The quotient is added back onto 
the stack. A divide by zero exception is added.
*/
void division ()
{
		int first = dc.topAndPop();
		int second = dc.topAndPop();
		if (first == 0)
			cout << "Exception-- CANNOT DIVIDE BY ZERO" << endl;
		else
		{
		int quotient = second/first;
		dc.push(quotient);
		}
}

/*--------------------------------------------
Pre:
The stack is unaltered and nothing is printed.

Post:
The top two values of the stack are taken, the
values are multiplied, and the product is then
pushed onto the stack.
*/
void multiplication ()
{
	int first = dc.topAndPop();
	int second = dc.topAndPop();
	int product = first*second;
	dc.push(product);
}

/*--------------------------------------------
Pre:
The stack is unaltered and nothing is printed.

Post:
The top two values of the stack are taken and
the modulo operation is performed:
second%first
The remainder is then pushed back onto the
stack. A divide by zero exception is also
included.
*/
void modulo ()
{
	int first = dc.topAndPop();
	int second = dc.topAndPop();
	if (first == 0)
		cout << "Exception-- CANNOT DIVIDE BY ZERO" << endl;
	else
	{
		int result = second%first;
		dc.push(result);
	}
}

/*--------------------------------------------
Pre:
The stack is unaltered and nothing is printed.

Post:
All of the values in the stack are removed and
summed. The result is then pushed onto the stack.
*/
void methodT ()
{
	int sum = dc.topAndPop();
	while (!(dc.isEmpty()))
	{
		int next = dc.topAndPop();
		sum += next;
	}
	dc.push(sum);
}

/*--------------------------------------------
Pre:
The stack is unaltered and nothing is printed.

Post:
All of the values in the stack are removed and
multiplied together. The product is then
pushed onto the stack.
*/
void methodM ()
{
	int product = dc.topAndPop();
	while (!(dc.isEmpty()))
	{
		int next = dc.topAndPop();
		product = product*next;
	}
	dc.push(product);
}


/*--------------------------------------------
Pre:
A string from the user input is sent in.

Post:
The string is parsed through, separating 
digits, operators, negative symbol, and 
character commands. Whenever an operator,
command, or negative symbol is encountered,
the current value in string "number" is 
converted to an integer and pushed to the
stack (if it is not empty). The appropriate
function calls are made for each entry. If
there is an invalid entry, then a "not valid
entry" exception is called.
*/
void parseString(string input)
{
	string number = "";
	for (int i = 0; i < input.length(); i++)
	{
		char check = input.at(i);
		//Enters this branch if it is a lowercase letter.
		if (islower(check))
		{
			if (number != "")
			{
				int pushValue = atoi(number.c_str());
				dc.push(pushValue);
				number = "";
			}		
			switch (check)
			{
			case 'p' :
			{
				methodP();
				break;
			}

			case 'n' :
			{ 
				methodN();
				break;
			}

			case 'f' :
			{ 
				methodF();
				break;
			}

			case 'c' :
			{
				methodC();
				break;
			}

			case 'd' :
			{
				methodD();
				break;
			}

			case 'r' :
			{
				methodR();
				break;
			}

			case 'm' :
			{
				methodM();
				break;
			}

			case 't' :
			{
				methodT();
				break;
			}
			//This called when the letter entered does not match a command.
			default :
			cout << "Exception-- INVALID EXPRESSION, PLEASE RE-ENTER" << endl;
			}
		}

		//Checks to see if the ASCII value is equal to 43 (+).
		else if(int(check) == 43)
		{
			if (number != "")
			{
				int pushValue = atoi(number.c_str());
				dc.push(pushValue);
			}		
			addition();	
			number = "";
		}

		//Checks to see if the ASCII value is equal to 45 (-).
		else if(int(check) == 45)
		{
			if (number != "")
			{
				int pushValue = atoi(number.c_str());
				dc.push(pushValue);
			}
			subtraction();
			number = "";
		}

		//Checks to see if the ASCII value is equal to 42 (*).
		else if(int(check) == 42)
		{
			if (number != "")
			{
				int pushValue = atoi(number.c_str());
				dc.push(pushValue);
			}
			multiplication();
			number = "";
		}

		//Checks to see if the ASCII value is equal to 47 (/).
		else if(int(check) == 47)
		{
			if (number != "")
			{
				int pushValue = atoi(number.c_str());
				dc.push(pushValue);
			}
			division();
			number = "";
		}

		//Checks to see if the ASCII value is equal to 37 (%).
		else if(int(check) == 37)
		{
			if (number != "")
			{
				int pushValue = atoi(number.c_str());
				dc.push(pushValue);
			}
			modulo();
			number = "";
		}

		//Checks to see if the ASCII value is equal to 95 (_).
		else if (int(check) == 95)
		{
			if (number != "")
			{
				int pushValue = atoi(number.c_str());
				dc.push(pushValue);
			}
			number = "-";
		}

		//Checks to see if the entry is a digit.
		//If it is, it is appended to the number string.
		else if(isdigit(check))
			{
				number += check;
			}

		else if (isblank(check))
		{}

	}

	//This is to cover the possibility that the last thing
	//entered into the string is an number.
	if (number != "")
			{
				int pushValue = atoi(number.c_str());
				dc.push(pushValue);
			}

}


//Main is simply a while that takes user input,
//makes a call to parse the string, and continues this 
//until the end of file is reached on standard input.
int main()
{

	while(1)
	{
		string input;
		cin >> input;
		parseString(input);
	}


}


