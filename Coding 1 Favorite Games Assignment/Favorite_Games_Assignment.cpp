#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> favGames;
    cout << "Hello user.\n";
    cout << "Welcome to the Favorite Games program.\n";

    while (true)
    {
        cout << "What would you like to do? (add/show/quit)\n";
        string response = "";
        getline(cin, response);

        if (response == "add")
        {
            cout << "What game would you like to add?\n";
            getline(cin, response);
            favGames.push_back(response);
        }
        else if (response == "show")
        {
            for (int i = 0; i < favGames.size(); i++)
            {
                cout << favGames[i] << "\n";
            }
        }
        else if (response == "quit")
        {
            cout << "Thank you for your time.\n";
            break;
        }
    }
}