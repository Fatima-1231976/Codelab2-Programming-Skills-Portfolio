#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    vector<string> jokes;
    string line;

    ifstream file("randomJokes.txt");

    while (getline(file, line))
    {
        jokes.push_back(line);
    }

    file.close();

    srand(time(0));

    string input;

    do
    {
        cout << "\nType: Alexa, tell me a joke\n";
        getline(cin, input);

        if (input == "Alexa, tell me a joke")
        {
            int randomIndex = rand() % jokes.size();
            string joke = jokes[randomIndex];

            int pos = joke.find('?');

            string setup = joke.substr(0, pos + 1);
            string punchline = joke.substr(pos + 1);

            cout << "\n" << setup << endl;

            cout << "\nPress Enter for the punchline...";
            cin.get();

            cout << punchline << endl;
        }

        cout << "\nAnother joke? (y/n): ";
        getline(cin, input);

    } while (input == "y" || input == "Y");

    return 0;
}