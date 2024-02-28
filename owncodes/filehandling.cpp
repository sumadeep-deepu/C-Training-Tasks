#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
string encryptText(string &line, char key)
{
	string encryptedText = line;
	for (char &c : encryptedText)
	{
		c = c ^ key;
	}
	return encryptedText;
}
int main()
{
	ifstream inputFile("input.txt");
	ofstream outputFile("output1.txt");

	if (!inputFile.is_open() || !outputFile.is_open())
	{
		cout << "failed to open the input or output file" << endl;
		return 1;
	}
	string line;
	char key = 'S';
	string encryptedText;
	while (getline(inputFile, line))
	{
		istringstream iss(line);
		string word;
		while (iss >> word)
		{
			encryptedText += encryptText(word, key);
		}
		encryptedText += '\n';
	}
	outputFile << encryptedText;
	cout << "encryption success please check" << endl;
	inputFile.close();
	outputFile.close();
	return 0;
}
