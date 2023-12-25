// Day1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS 1

using namespace std;

int IsNumber(char InputChar)
{
    int AsciiValue = 0;
    AsciiValue = int(InputChar);
    //cout << AsciiValue << " ";
    if (AsciiValue > 47 and AsciiValue < 58)
    {
        return AsciiValue - 48;
    }
    else
    {
        return -1;
    }
    return -1;
}

int Value(string line)
{
    const int ALenght = line.length();

    char* Aline = new char[ALenght + 1];
    int answer = 0;
    int pass = 0;
    int number [2];
  


    strncpy(Aline, line.c_str(), ALenght+1);
    for (int i = 0; i < ALenght; i++)
    {
        int value = IsNumber(Aline[i]);
        if (value != -1)
        {
            if (pass == 0)
            {
                number[pass] = value;
                number[pass + 1] = value;
                pass = 1;
            }
            else
          
            {
                number[pass] = value;
            }
        } 
    }

    return (number[0]*10+number[1]);
}

int readfile(string IFile)
{
    string line;
    ifstream file(IFile);
    int Answer = 0;
    int value;
    if (file.is_open()) {
        while (getline(file, line)) 
        {
            value = Value(line);
            if (value != -1)
            {
                Answer = Answer + value;
                cout << value << " " << Answer << endl;

            }
            
        }
        file.close();
    }
    return 0;
}

; 
int main() 
{
    readfile("example.txt");

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
