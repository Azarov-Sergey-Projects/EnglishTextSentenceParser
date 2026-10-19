// English textParser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

enum TokenType
{
    TOKEN_WORD,
    TOKEN_NUMBER,
	TOKEN_PUNCTUATION,
	TOKEN_ASTERISK
};


struct CToken
{
    std::string m_tokenText;
    TokenType m_tokenType;
    int position;
};


std::string FindSubstr(const std::string& strIn, size_t iPos)
{

}


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
    int iPosStart = 0;
    int iPosEnd = 0;
    int iCount = 1;

    while (strInput[iPosStart] != '\0')
    {
        if (strInput[iPosStart] == ' ' || strInput[iPosStart] == '\t')
        {
			tokens.push_back(CToken{strInput.substr(iPosEnd, iPosStart - iPosEnd), TOKEN_WORD, iCount});
            iCount++;
            iPosEnd = iPosStart + 1;
        }
		if (strInput[iPosStart + 1] == '\0')
		{
			tokens.push_back(CToken{strInput.substr(iPosEnd, iPosStart - iPosEnd + 1), TOKEN_WORD, iCount});
		}
        iPosStart++;
    }
    /*for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i].m_tokenText.find('\'') != std::string::npos)
        {

        }
    }*/
    for (int i = 0; i < tokens.size(); i++)
    {
        std::cout << "Token: " << tokens[i].m_tokenText << " Type: " << tokens[i].m_tokenType << " Position: " << tokens[i].position << std::endl;
    }
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
