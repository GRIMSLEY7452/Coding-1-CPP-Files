#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

int RollDamage(int sides = 6)
{
    return rand() % sides + 1;
}

int RollBlock(int sides = 6)
{
    return rand() % sides + 1;
}

int GoldDrop()
{
    return rand() % 100 + 1;
}

bool AskYesNo(string question)
{
    cout << question;
    string response = "";
    getline (cin, response);

    if (response == "Yes" || response == "yes" || response == "y")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Adventure()
{
    int playerHealth = 20;
    int playerGold = 0;
    int playerTurns = 0;
    
    do
    {
        int playerBlock = RollBlock();
        int enemyDamage = RollDamage();
        playerTurns++;
        
        cout << "\n";
        cout << "You are walking down a dark forest path.\n";
        cout << "Suddenly, you are attacked by an evil orc.\n";

        if (playerBlock >= enemyDamage)
        {
            
            cout << "\n";
            cout << "You manage to block the orc's attack, but you take 1 damage.\n";
            playerHealth--;
            
            if (playerHealth <= 0)
            {
                cout << "You die and drop " << playerGold << " gold pieces on the ground.\n";
                break;
            }
            else
            {
                cout << "As you flee, you find some gold on the ground.\n";
                cout << "\n";
                playerGold += GoldDrop();
            }
        }
        else
        {
            
            cout << "\n";
            cout << "You fail to block the orc's attack.\n";
            playerHealth -= enemyDamage;
            
            if (playerHealth <= 0)
            {
                cout << "You die and drop " << playerGold << " gold pieces on the ground.\n";
                break;
            }
            else
            {
                cout << "You take " << enemyDamage << " points of damage.\n";
                cout << "In your haste to escape, you do not find any gold.\n";
                cout << "\n";

            }
        }

        if (AskYesNo("Would you like to continue?\n") == true)
        {
            cout << "\n";
            cout << "Very well.\n";
        }
        else
        {
            if (playerHealth >= 5)
            {
                cout << "\n";
                cout << "You decide to leave the forest.\n";
                cout << "You survived " << playerTurns << " turns.\n";
                cout << "You managed to find " << playerGold << " gold pieces.";
                break;
            }
            else
            {
                cout << "\n";
                cout << "You decide to leave the forest.\n";
                cout << "Your health is pretty low, so you should go see a doctor.\n";
                cout << "You survived " << playerTurns << " turns.\n";
                cout << "You managed to find " << playerGold << " gold pieces.";
                break;
            }
        }
    } 
    while(true);
}

int main() 
{
    srand(time(0));
    
    cout << "Greetings, Professor Falken.\n";

    if (AskYesNo("Shall we play a game?\n") == true)
    {
        if (AskYesNo("Would you like to play Adventure Game?\n") == true)
        {
            Adventure();
        }
        else
        {
            cout << "Alright. How about a nice game of chess?";
        }
    }
    else
    {
        cout << "Goodbye, Professor Falken.";
    }
}