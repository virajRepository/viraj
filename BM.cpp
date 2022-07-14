#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cctype>
#include<stdlib.h>

using namespace std;

vector<string> moduleLinesArray;
int numberOfMatching = 0;


void moduleRead()
{
    fstream myFile;
    int i = 0;
    myFile.open("modules.txt",ios::in); // read
    if(myFile.is_open())
    {
        string line;
        while(getline(myFile,line))
        {
            moduleLinesArray.push_back(line);
        }
        myFile.close();
    }
}


char swapCaseofChar(char text)
{
    if(islower(text))
        text = char(toupper(text));
    else
        text = char(tolower(text));

    return text;
}



int naiveAlgo(string text, string pattern)
{
    // text checking loop
    int i = 0;
    int j = 0;
    int charMatchingTime = 0;

    if(text.length() < pattern.length())
    {
        return numberOfMatching;
        exit(0);
    }
    

    for (i = 0; i < text.length(); i++)
    {
        // pattern checking loop

        for (j = 0; j < pattern.length(); j++)
        {
            if( pattern[j] == text[i] || pattern[j] == swapCaseofChar(text[i])  )
            {
                i++;
                charMatchingTime++;
            }

            else if( pattern[j] != text[i] || pattern[j] != swapCaseofChar(text[i]) )
            {
                charMatchingTime = 0;
                break;
            }
        }

        if(charMatchingTime == pattern.length() )
        {
            numberOfMatching++;
            cout << text <<endl;
            break;
        }
    }
}




int main(int argc, char const *argv[])
{
    cout<<endl;
    moduleRead();
    string searchString;
    // cout << "Enter a search string: ";
    // cin >> searchString;

    for( const auto &value: moduleLinesArray)
    {
        string text = value;
        naiveAlgo(text,"arcs4022");
    }
    
    cout << "Number of matches: " << numberOfMatching;


    cout << endl;
    return 0;
}
