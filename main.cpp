/**
@filename  main.cpp
@Author  Daniel Targonski
@Assignment  STL - pallindrome
@Date  11/25/20  */

#include<iostream>
#include<queue>
#include<stack>
#include<string>

using namespace std;

/** Tests whether a given string is a palindrome
@pre  None.
@post  None
@param  a string.
@return  True if passed string is a palindrome and false if not.*/
bool isPalindrome(const string& str);

int main()
{
	string test;
	cout << "Input a palindrome:\n";
	getline(cin, test);
	cout << "\n\n";

	if (isPalindrome(test))
		cout << "\"" << test << "\" is a palindrome.\n";
	else
		cout << "\"" << test << "\" is not a palindrome.\n";

	return 0;
}

bool isPalindrome(const string& str)
{
	// Create an empty queue and an empty stack
	queue<char> aQ;
	stack<char> aS;
	// Add each char of the str to both the queue and the stack
	int length = str.length();
	int i{};
	for (i = 0; i < length; i++)
	{
		char nextChar = str[i];
		if (isalpha(nextChar))
		{
			if (isupper(nextChar))
				nextChar = tolower(nextChar);
			aQ.push(nextChar);
			aS.push(nextChar);
		}

	}
	// Compare the queue chars with the stack chars
	bool charsAreEqual = true;
	while (!aQ.empty() && charsAreEqual == true)
	{
		char queueFront = aQ.front();
		char stackTop = aS.top();
		if (queueFront == stackTop)
		{
			aQ.pop();
			aS.pop();
		}
		else
			return false;
	}
	return charsAreEqual;
}
