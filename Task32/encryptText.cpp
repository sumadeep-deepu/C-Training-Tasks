#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string encryptText(const string &text, char key)
{
	string encryptedText = text;
	for (char &c : encryptedText)
	{
		c = c ^ key;
	}
	return encryptedText;
}

int main()
{
	ifstream inputFile("input.txt");
	ofstream outputFile("encryptedOutput.txt");

	if (!inputFile.is_open() || !outputFile.is_open())
	{
		cout << "Failed to open the input or output file" << endl;
		return 1;
	}

	char encryptionKey = 'S';
	string line;
	string encryptedContent;

	while (getline(inputFile, line))
	{
		istringstream iss(line);
		string word;
		while (iss >> word)
		{
			encryptedContent += encryptText(word, encryptionKey) + " ";
		}
		encryptedContent += '\n';
	}

	outputFile << encryptedContent;
	cout << "Encryption successful. Encrypted text written to encryptedOutput.txt" << endl;

	inputFile.close();
	outputFile.close();
	return 0;
}
