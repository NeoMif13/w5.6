

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    //
    ofstream outputFile("input.txt");
    if (!outputFile.is_open())
    {
        cout << "������ �������� ����� input.txt" << endl;
        return 1;
    }

    cout << "������� �����. ��� ���������� ����� ������� ������ ������." << endl;

    string line;
    while (getline(cin, line) && !line.empty())
    {
        outputFile << line << endl;
    }
    outputFile.close();
    //
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cout << "������ �������� ����� input.txt" << endl;
        return 1;
    }

    vector<string> words;
    string word;
    string fileLine;
    while (getline(inputFile, fileLine))
    {
        string word;
        for (char& c : fileLine)
        {
            if (isalpha(c))
            {
                word += c;
            }
            else
            {
                if (!word.empty())
                {
                    words.push_back(word);
                    word.clear();
                }
            }
        }
        if (!word.empty())
        {
            words.push_back(word);
        }
    }
    inputFile.close();

    vector<string> reversedWords;
    while (!words.empty())
    {
        reversedWords.push_back(words.back());
        words.pop_back();
    }

    ofstream outputFileReverse("output.txt");
    if (!outputFileReverse.is_open())
    {
        cout << "�� ������� ������� ���� output.txt" << endl;
        return 1;
    }

    for (const string& reversedWord : reversedWords)
    {
        outputFileReverse << reversedWord << " ";
    }
    outputFileReverse.close();

    cout << "����� ������� ������� � ���� output.txt" << endl;
    //
    ifstream outputRead("output.txt");
    if (!outputRead.is_open())
    {
        cout << "�� ������� ������� ���� output.txt ��� ������" << endl;
        return 1;
    }

    cout << "���������� ����� output.txt:" << endl;
    string outputLine;
    while (getline(outputRead, outputLine))
    {
        cout << outputLine << endl;
    }
    outputRead.close();

    return 0;
}
