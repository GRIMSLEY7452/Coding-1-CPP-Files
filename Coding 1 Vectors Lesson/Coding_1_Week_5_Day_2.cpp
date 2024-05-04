#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    srand(time(0));
    
    cout << "What would you like to do?\n";
    cout << "Press 1 to run the Inventory Program.\n";
    cout << "Press 2 to run the Iterator Program.\n";
    cout << "Press 3 to run the Algorithm Program.\n";
    int select = 0;
    cin >> select;

    if (select == 1)
    {
        cout << "Let's create an inventory!\n";
        // A vector is an array that you can change the size of.
        // Create a vector of string variables named inventory. Default size is 0.
        vector<string> inventory;

        inventory.push_back("Wrench"); // [0]
        inventory.push_back("Revolver"); // [1]
        inventory.push_back("EVE Hypo"); // [2]
        inventory.push_back("First Aid Kit"); // [3]

        cout << "There are " << inventory.size() << " items in our inventory.\n";

        // First, create an integer that is equal to 0.
        // Then, as long as that integer is less than the size of the vector, keep looping.
        // Each time we loop, add 1 to the integer.
        // Each loop, inside the code block, send a new string to the console.
        for (int i = 0; i < inventory.size(); i++)
        {
            cout << inventory[i] << "\n";
        }

        // Let's exchange one of our items, and then drop the last item in the vector.
        cout << "We lost the revolver but found a shotgun.\n";
        inventory[1] = "Shotgun";

        cout << "We fought a Splicer and got hurt, so we used our first aid kit.\n";
        inventory.pop_back();

        for (int i = 0; i < inventory.size(); i++)
        {
            cout << inventory[i] << "\n";
        }
    }
    else if (select == 2)
    {
        cout << "Iterators suck!\n";

        // Collection initializer
        vector<string> enemies {"Dr. Steinman", "Sander Cohen", "Andrew Ryan", "Frank Fontaine"};
        cout << "There are " << enemies.size() << " enemies in our vector.\n";

        /*
            index of...
            0 = Dr.Steinman        <-- .begin()
            1 = Sander Cohen
            2 = Andrew Ryan
            3 = Frank Fontaine     <-- .end()
        */

        // Dereference with *
        cout << "The first enemy in our vector is " << *enemies.begin() << ".\n";
        cout << "The last enemy in our vector is " << *(enemies.end() - 1) << ".\n";

        // Using a constant iterator in a for loop.
        // Iterators point at other variables in a vector.
        // Constant means read-only.
        for (vector<string>::const_iterator iter = enemies.begin(); iter != enemies.end(); ++iter)
        {
            cout << *iter << "\n";
        }
    }
    else if (select == 3)
    {
        cout << "Let's mess with algorithms.\n";
        cout << "The numbers:\n";

        // Make a vector of integers.
        // Then use a for loop and add scores.push_back() to add 10 random numbers between 1 and 100.
        vector<int> scores;

        for (int i = 0; i < 10; i++)
        {
            scores.push_back(rand() % 100 + 1);
            cout << scores[i] << "\n";
        }

        // sort (scores.begin(), scores.end());
        // reverse (scores.begin(), scores.end());
        // random_shuffle (scores.begin() scores.end());

        // While loop, find a number, erase it, then show the list, then loop.
        int input = 0;

        while (input!= -1 && scores.size() > 0)
        {
            cout << "The numbers:\n";

            for (int i = 0; i < scores.size(); i++)
            {
                cout << scores[i] << "\n";
            }

            // Ask the player what number to erase.
            cout << "What number should we remove?\n";
            cin >> input;

            // Try to find that number.
            vector<int> 
        }
    }
    else
    {
        cout << select << " wasn't one of the options.\n";
    }

    return 0;
}