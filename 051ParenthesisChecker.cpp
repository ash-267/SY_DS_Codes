/*Parenthesis Checker:
* Write a program using a  stack  for push, pop, peek, and isEmpty operations. 
* Write isBalanced() Function that Iterates through the input expression, Pushes opening brackets onto the stack. 
* For closing brackets, it checks the top of the stack for a matching opening bracket. 
* Ensures that all opening brackets are matched by the end of the traversal. 
* Main Function: Accepts a string expression from the user. 
* Uses isBalanced() to determine if the parentheses in the expression are balanced. 
*/

#include <iostream>

#define STACKSIZE 3

using namespace std;

class Parenthesis_Checker {
	char stack[STACKSIZE];
	string expression;
	int top;
public:
	
	Parenthesis_Checker () {
		top = -1;
	}
		
	void input();
	bool isEmpty();
	bool isFull();
	void push(char a);
	char pop();
	char peek();
	void display();
	void isBalanced();
};

void Parenthesis_Checker::input() {
	cout << "Enter an expression: ";
	cin >> expression;
}

bool Parenthesis_Checker::isEmpty() {
	if (top == -1) {
		return true;
	} else {
		return false;
	}
}

bool Parenthesis_Checker::isFull() {
	if (top == STACKSIZE-1) {
		return true;
	} else {
		return false;
	}
}

void Parenthesis_Checker::push (char a) {
	if (isFull()) {
		cout << "Stack is full" << endl;
	} else {
		top++;
		stack[top] = a;
	}
}

char Parenthesis_Checker::pop () {
	if (isEmpty()) {
		cout << "Stack is empty" << endl;
		return '\0';
	} else {
		char temp = stack[top];
		top--;
		return temp;
	}
}

void Parenthesis_Checker::display () {
	if (isEmpty()) {
		cout << "Stack is empty" << endl;
	} else {
		for (int i=top; i>=0; i--) {
			if (i == top) {
				cout << "Element at top: " << stack[i] << endl;
			} else {
				cout << "Element at " << i+1 << ": " << stack[i] << endl;
			}
		}
	}
}

char Parenthesis_Checker::peek() {
	char c = stack[top];
	return c;
}

void Parenthesis_Checker::isBalanced() {
	for (int i=0; expression[i] != '\0'; i++) {
		if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
			char b = expression[i];
			push(b);
		} else if ((expression[i] == ')' && peek() == '(') || (expression[i] == ']' && peek() == '[') || (expression[i] == '}' && peek() == '{')) {
			pop();
		}
	}
	if (!isEmpty()) {
		cout << "Parenthesis input is incorrect, check the expression!" << endl;
	} else {
		cout << "Parenthesis input is correct, stack is balanced" << endl;
	}
}

int main () {
	Parenthesis_Checker exp;
	exp.input();
	exp.isBalanced();
	
	return 0;
}
