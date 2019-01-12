//
//  Source.cpp
//
//  Created by Оля Пастущак on 27.10.2017.
//  Reviewed by Олег-Андрій Жук on 29.10.2017.
//  Copyright © 2017 Оля Пастущак. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


// Тут можна передавати як аргумент назву файлу. Таким чином вхідний файл може бути не тільки "data.txt".
//DONE
void input(const string& fileName, vector <string>& words, int& n)
{
	ifstream file(fileName, ios_base::in);
	if (!file.is_open())
	{
		throw exception("can not open file with data");
	}

	// Тут можна зробити простіше на кшталт:
	// if (!(file >> number))
	// {
	//    throw invalid_argument("bad number in file");
	// }
	// DONE
	if (!(file >> n))
	{
		throw invalid_argument("bad number in file");
	}

	istream_iterator<string> vectRead(file);
	copy(vectRead, istream_iterator<string>(), back_inserter(words));

	file.close();
}

void printNumberOfWords(vector <string> words, ofstream& file)
{
	file << "Number of words: ";
	file << words.size() << endl;
}

// Тут можна char foundSymbol внести в параметр функції. Це зробить її більш універсальною.
// DONE
void printCountGivenLetters(vector<string> words, ofstream& file, const char& foundSymbol)
{
	string lastWord = words.back();

	int countOfSymbol;
	countOfSymbol = count(lastWord.begin(), lastWord.end(), foundSymbol);

	file << countOfSymbol << endl;
}

//UnaryPredicate
bool isNotStartingWithB(string word)
{
	return word.front() != 'b';
}

//UnaryPredicate
bool isLastSymbNotEqFirst(string word)
{
	return word.back() != word.front();
}

// Друкує слова, для яких функція-предикат повертає значення false. (В даному випадку продемонстровано 2 функції-предикати вище).
void printSpecialWords(vector<string> words, ofstream& file, bool(*pred)(string))
{
	int countSpecialWords;
	countSpecialWords = words.size() - count_if(words.begin(), words.end(), pred);

	vector<string>::iterator iterToEnd = words.end();
	iterToEnd = remove_if(words.begin(), iterToEnd, pred);

	ostream_iterator<string> vectWrite(file, " ");
	copy(words.begin(), iterToEnd, vectWrite);

	file << "\nCount of these words: " << countSpecialWords << endl;
}

bool checkIfRightNumber(vector <string> words, int number)
{
	int sumSymbols = 0;
	// Можна писати auto iter = words.begin(); ... замість оголошення vector <string>::iterator iter;
	// DONE
	for (auto iter = words.begin(); iter != words.end(); iter++)
	{
		sumSymbols += (*iter).length();
	}
	return sumSymbols == number;
}

int main()
{
	try
	{
		int n;
		vector <string> words;
		input("data.txt", words, n);

		if (!checkIfRightNumber(words, n))
		{
			throw invalid_argument("bad data in file");
		}
		ofstream fileAnswers("answers.txt", ios_base::out);
		if (!fileAnswers.good())
		{
			throw exception("something wrong with answers file");
		}

		printNumberOfWords(words, fileAnswers);

		fileAnswers << "Number of letters a in last word: ";
		printCountGivenLetters(words, fileAnswers, 'a');

		fileAnswers << "Words starting with b: ";
		printSpecialWords(words, fileAnswers, isNotStartingWithB);

		fileAnswers << "Words with last symbol equal to first: ";
		printSpecialWords(words, fileAnswers, isLastSymbNotEqFirst);
		fileAnswers.close();
	}
	catch (invalid_argument& ex)
	{
		cout << ex.what() << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}

	system("PAUSE");
	return 0;
}
