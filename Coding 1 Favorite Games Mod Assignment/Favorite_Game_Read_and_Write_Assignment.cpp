#include "includes.h"

void Edit(vector<string>& vector, int index, string newValue)
{
    if (index >= 0 && index < vector.size())
    {
        vector[index] = newValue;
        cout << "The game has been changed.\n";
    }
    else
    {
        cout << "That game doesn't exist.\n";
    }
}

int main() 
{
    vector<string> favGames;
    cout << "Hello user.\n";
    cout << "Welcome to the Favorite Games program.\n";

    ifstream nameFile ("favgames.txt");
    string line;
    if (nameFile.is_open())
    {
        while (getline(nameFile, line))
        {
            favGames.push_back(line);
        }
    }
    else
    {
        cout << "Could not read from nameFile.\n";
    }
    nameFile.close();

    while (true)
    {
        cout << "What would you like to do? (add/edit/show/clear/quit)\n";
        string response = "";
        getline(cin, response);

        if (response == "add")
        {
            cout << "What game would you like to add?\n";
            getline(cin, response);
            favGames.push_back(response);
        }
        else if (response == "edit")
        {
            int gameNumber;
            string newGame;
            
            cout << "Which game would you like to change?\n";
            cout << "Type the number of the game you would like to change.\n";

            for (int i = 0; i < favGames.size(); i++)
            {
                cout << i << ": " << favGames[i] << "\n";
            }

            string response = "";
            getline(cin, response);
            gameNumber = stoi(response);

            cout << "What would you like to change it to?\n";
            getline(cin, response);
            newGame = response;

            Edit(favGames, gameNumber, newGame);
        }
        else if (response == "show")
        {
            for (int i = 0; i < favGames.size(); i++)
            {
                cout << i << ": " << favGames[i] << "\n";
            }
        }
        else if (response == "clear")
        {
            cout << "The list has been cleared.\n";
            favGames.clear();
            ofstream myfile;
            myfile.open ("favgames.txt");
            myfile.close();
        }
        else if (response == "quit")
        {
            cout << "Thank you for your time.\n";

            ofstream myfile;
            myfile.open ("favgames.txt");
            myfile.close();
            
            for (int i = 0; i < favGames.size(); i++)
            {
                ofstream myfile;
                myfile.open ("favgames.txt", ios::app);
                myfile << favGames[i] << "\n";
                myfile.close();
            }
            
            break;
        }
    }
}