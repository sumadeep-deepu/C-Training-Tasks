#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;
string toLowerCase(string &str)
{
	string result = str;
	transform(result.begin(), result.end(), result.begin(), ::tolower);
	return result;
}
int main()
{
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");

	if (!inputFile.is_open() || !outputFile.is_open())
	{
		cout << "failed to open input or output file plese check" << endl;
	}
	map<string, int> wordFreq;
	string line;
	while (getline(inputFile, line))
	{
		istringstream iss(line);
		string word;
		while (iss >> word)
		{
			word = toLowerCase(word);
			word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
			wordFreq[word]++;
		}
	}
	for (auto &pair : wordFreq)
	{
		outputFile << pair.first << " : " << pair.second << endl;
	}
	cout << "word with their frequencies are written in output file" << endl;
	inputFile.close();
	outputFile.close();
	return 0;
}
