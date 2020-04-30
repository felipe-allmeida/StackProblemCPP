#include "Machine.h"
#include "string"

Machine::Machine()
{
	std::cout << "Constructor Machine!\n";
}

void Machine::EnterCommand(string command)
{
	std::cout << "Machine::EnterCommand -> " << command << "\n";

	if (IsNumber(command))
	{
		_stack.push(stoi(command));
	}
	else
	{
		if (command == "PTR")
		{
			ShowStack(_stack);
		}
		else if (command == "DUP")
		{
			int top = _stack.top();
			_stack.push(top);
		}
		else if (command == "POP")
		{
			_stack.pop();
		}
		else if (command == "INV")
		{
			
		}
		else if (command == "+")
		{
			int a = _stack.top();
			_stack.pop();

			int b = _stack.top();
			_stack.pop();
			_stack.push(a + b);
		}
		else if (command == "-")
		{
			int a = _stack.top();
			_stack.pop();

			int b = _stack.top();
			_stack.pop();

			_stack.push(a - b);
		}
		else
		{
			std::cout << "Machine::EnterCommand::Error-> Invalid Command\n";
		}
	}
}

void Machine::ShowStack(stack<int> stack)
{
	cout << "[";
	while (!stack.empty())
	{
		cout << stack.top();
		stack.pop();

		if (!stack.empty())
		{
			cout << ", ";
		}
	}
	cout << "]\n";
}

bool Machine::IsNumber(const string& command)
{
	string::const_iterator iterator = command.begin();
	while (iterator != command.end() && isdigit(*iterator))
	{
		iterator++;
	}

	return !command.empty() && iterator == command.end();
}
