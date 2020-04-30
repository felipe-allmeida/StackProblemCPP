#pragma once
#include <iostream>
#include <stack>


using namespace std;

class Machine
{
public:
	Machine();

	void EnterCommand(string command);
private:
	stack<int> _stack;
	void ShowStack(stack<int> stack);
	bool IsNumber(const string& s);
	
};

