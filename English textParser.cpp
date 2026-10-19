// English textParser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

enum TokenType
{
    TOKEN_WORD,
    TOKEN_NUMBER,
	TOKEN_PUNCTUATION,
	TOKEN_ASTERISK
};

bool IsWord(const std::string& str)
{
	if (str.empty())
	{
		return false;
	}
	for (char c : str)
	{
		if (c == ' ' || c == '\t' || c == '\0')
		{
			return false;
		}
	}
	return true;
}

struct CToken
{
    std::string m_tokenText;
    TokenType m_tokenType;
    int position;
};

int main(int argc, char* argv[])
{
    if (argc > 2)
    {
        std::cout << "Way too much parms" << std::endl;
        return 1;
    }
    if (argc < 2)
    {
        std::cout << "No parms specified, exiting" << std::endl;
        return -1;
    }

	std::vector<CToken> tokens;
    std::string strInput = argv[1];
    size_t iPosStart = 0;
    size_t iPosEnd = 0;
    int iCount = 1;

	if (strInput.find_first_not_of(" \t \n") == std::string::npos)
	{
		std::cout << "Input string is empty or contains only whitespace, exiting" << std::endl;
		return -1;
	}
	else
	{
		iPosStart = strInput.find_first_not_of(" \t \n");
	}
	while (iPosStart < strInput.length())
	{
		iPosEnd = strInput.find_first_of(" \t \n", iPosStart);
		if (iPosEnd == std::string::npos)
		{
			iPosEnd = strInput.length();
		}
		std::string tokenText = strInput.substr(iPosStart, iPosEnd - iPosStart);
		TokenType tokenType;
		if (IsWord(tokenText))
		{
			tokenType = TOKEN_WORD;
		}
		else if (tokenText == "*")
		{
			tokenType = TOKEN_ASTERISK;
		}
		else if (std::all_of(tokenText.begin(), tokenText.end(), ::isdigit))
		{
			tokenType = TOKEN_NUMBER;
		}
		else
		{
			tokenType = TOKEN_PUNCTUATION;
		}
		CToken token{ tokenText, tokenType, iCount };
		tokens.push_back(token);
		iCount++;
		size_t next = strInput.find_first_not_of(" \t \n", iPosEnd);
		if (next == std::string::npos)
		{
			break;
		}
		iPosStart = next;
	}
	for (const auto& token : tokens)
	{
		std::cout << "Token: " << token.m_tokenText << ", Type: " << token.m_tokenType << ", Position: " << token.position << std::endl;
	}
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
