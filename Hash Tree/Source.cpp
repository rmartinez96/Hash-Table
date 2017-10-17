// Raul Martinez
// raul.martinez01@utrgv.edu

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "chainingTable.h"

using namespace std;

void clean(string &x) {
	
	int a; 0;
	int len = x.length();

	for (int i = 0; i < len; i++)
	{
		if ((x[i] > 64) && (x[i] < 91))
		{
			transform(x.begin(), x.end(), x.begin(), tolower);
		}
		else if ((x[i] > 96) && (x[i] < 123))
		{

		}
		else
		{
			x[i] = 32;
		}
	}
}

int main()
{
	ifstream infile;
	chainingTable time;
	chainingTable raven;
    string word;

    infile.open("dictionary.txt");
    
    if (infile.is_open()) {
		while (infile >> word) {
			time.insert(word);
        }
    }
    infile.close();

	cout << "Average Search Cost: " << time.averageSearchCost() << endl;

	while (true) {
		cout << "Check: ";
		cin >> word;
		if (time.contains(word))
		{
			cout << "Inside the hash tree." << endl;
		}
		else if (word == "0")
		{
			break;
		}
		else
		{
			cout << "Not in the hash tree." << endl;
		}
	}

	cout << endl;

	ofstream outFile ("test.txt");


	infile.open("raven.txt");

	if (infile.is_open()) {
		while (infile >> word)
		{
			clean(word);
			outFile << word << endl;
		}
	}
	infile.close();
	outFile.close();

	infile.open("test.txt");
	ofstream outFile1("test1.txt");

	outFile1 << "Words not included in dictionary.txt:" << endl << endl;

	if (infile.is_open()) {
		while (infile >> word)
		{
			if (!time.contains(word))
				outFile1 << word << endl;
		}
	}

	infile.close();

	cout << endl;

	system("pause");
	return 0;
}