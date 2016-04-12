# RPNCalculator

GOAL/PROBLEM SPECIFICATION

This program is meant to operate as a simple Reverse Polish Notation calculator that uses a simple stack. A client program was written that makes use of the stack operations in order to perform the various operations. The program will take standard input from the user (operands, operators, commands) and perform the commands based on the order of the input. The results are stored inside the stack and there are commands that will display these result(s). This program makes use of the stack class, which maintains and modifies the stack used as the calculator's information holder. Some of the operations that this class contains that can modify the stack are the isEmpty(), isFull(), makeEmpty(), top(), pop(), push(), and topAndPop(), which are all very helpful. It also has private attributes, which are topOfStack and theArray vector. This prevents other programs from messing with these very important variables and causing an unnecessary issue with the stack being implemented.

BASIC ALGORITHM FOR RUNNING
  1. Takes user input
  2. Parses the information from the input
  3. Performs the operations
  4. Repeat

For the input, a simple cin statement in main will be used inside an infinte while loop so that the program will end when end of file is reached on standard input. Within this loop, there is also a call to parse the entered string to seperate the information. As the information is parsed, the appropriate methods and functions are called to carry out information as it is received. The methods in the program are described below:

    methodP(): Checks to see if the stack is empty. If it is not, then the value at the top of the stack 
    is taken and printed out to the screen. No changes are made in the stack, and a new line is printed 
    after this function call.

    methodN(): Checks to see if the stack is empty. If it is not, then the value at the top of stack is 
    removed and printed to the screen. A new line is not added after this function call.

    methodF(): Makes a copy of the stack and checks to see if that copy is empty. If it is not, then a 
    loop goes through each entry of the copy and removes and prints each value. The original is left unaltered.

    methodC(): Regardless of whether the stack is empty already or not, a call to the function makeEmpty() in 
    stack.cpp is made to delete all entries.

    methodD(): A duplicate of the current top value of the stack is made and pushed back onto the stack.

    methodR(): The top two values of the stack are taken, reversed, and placed back into the stack.

    addition(): The top two values in the stack are taken, summed, and the sum is placed back into the stack.

    subtraction(): The top two values of the stack are taken, and the first one popped is subtracted from the 
    second one popped. The difference is added back onto the stack.

    division(): The top two values of the stack are taken, and the second one popped is divided by the first 
    one popped. The quotient is added back ontothe stack. A divide by zero exception is added.

    multiplication(): The top two values of the stack are taken, the values are multiplied, and the product 
    is then pushed onto the stack.

    modulo(): The top two values of the stack are taken and the modulo operation is performed: second%first. 
    The remainder is then pushed back onto the stack. A divide by zero exception is also included.

    methodT(): All of the values in the stack are removed and summed. The result is then pushed onto the stack.

    methodM(): All of the values in the stack are removed and multiplied together. The product is then pushed 
    onto the stack.

    parseString(): The string is parsed through, separating digits, operators, negative symbol, and character 
    commands. Whenever an operator, command, or negative symbol is encountered, the current value in string 
    "number" is  converted to an integer and pushed to the stack (if it is not empty). The appropriate function 
    calls are made for each entry. If there is an invalid entry, then a "not valid entry" exception is called.

Th parseString() method takes in the string given as input by the user. It first creates an empty string to hold numbers from the input line (named "number") and initializes it to be empty. Then a "for" loop is used to go through every character within the string. There are three sections to the checking portion of the loop for each character. The sections are meant to check wether it is a lowercase letter, an operator (each defined as an ASCII code),  or a digit. Within each section, a check is made to see if the "number" string is empty. If it isn't and the new character entered is defined to be a lowercase letter or operator, then the number string must be pushed as an operand onto the stack. After the number check, a switch-case statement is used by the lowercase letter portion to determine which letter was entered. If the entry does not match any of the commands, an error message is given that notifies the user; however, the program does not pause and continues through the rest of the input string. If the character wasn't a lowercase letter, then it is checked to see if it is any of the possible operators by converting the character into an ASCII code and comparing it with the ASCII codes for the various operators. If it is not an operator, then it is checked to see if it is a digit. If it is, is appended to the "number" string. If it is not a number, then the character is not a valid input. That is the basis of the parsing function.
