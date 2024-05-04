#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

enum ItemType
{
    weapon, tool, consumable
};

enum ElementalType
{
    basic = 0, fire = 1, ice = 2, candy = 3, slime = 4
};

class Item
{
public:
    ItemType type = weapon;
    int damage = 0;
    string name = "";
    ElementalType element = basic;
    int remainingUses = 0;
    int healingAmount = 0;

    Item()
    {
        
    }

    Item(string n, ItemType t)
    {
        name = n;
        type = t;

        if (type == weapon)
        {
            damage = rand() % 5 + 3;
            element = (ElementalType)(rand() % 4);
            remainingUses = 9999;
            healingAmount = 0;
        }
        else if (type == tool)
        {
            remainingUses = rand() % 5 + 1;
            damage = 1;
            element = basic;
            healingAmount = 0;
        }
        else
        {
            healingAmount = rand() % 5 + 3;
            damage = -healingAmount;
            element = basic;
            remainingUses = 1;
        }
    }

    void Inspect()
    {
        cout << name << " has damage of " << damage << ", it's element is " << elementToString(element) << "\n";
        cout << "It can be used " << remainingUses << " more times and heals for " << healingAmount << ".\n";
        cout << "It is of the item type " << typeToString(type) << ".\n\n";
    }

    string typeToString(ItemType type) 
    {
        switch(type) 
        {
            case weapon: 
                return "weapon"; 
                break;
            case tool: 
                return "tool"; 
                break;
            case consumable: 
                return "consumable";
                break;
            default: 
                return "unknown";
                break;
        }
    }

    string elementToString(ElementalType element) 
    {
        switch(element) 
        {
            case basic:
                return "basic";
                break;
            case fire:
                return "fire";
                break;
            case ice:
                return "ice";
                break;
            case candy:
                return "candy";
                break;
            case slime:
                return "slime";
                break;
            default:
                return "unknown";
                break;
        }
    }
};

class Enemy 
{
public:
    Item heldWeapon;
    int health;

    Enemy(Item w, int givenHealth)
    {
        heldWeapon = w;
        health = givenHealth;
    }

    int attack() 
    {
        return heldWeapon.damage;
    }
};

class Player 
{
public:
    Item heldWeapon;
    Item heldConsumable;
    int health;

    Player(Item w, Item c, int givenHealth)
    {
        heldWeapon = w;
        heldConsumable = c;
        health = givenHealth;
    }

    int attack() 
    {
        return heldWeapon.damage;
    }
};

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

int main() 
{
    srand(time(0));

    vector<string> weaponNames = 
    {
        "the Sword of Night and Flame",
        "the Blasphemous Blade",
        "the Dark Moon Greatsword",
        "the Starscourge Greatsword",
        "Morgott's Cursed Sword",
        "the Hand of Malenia",
        "Eleonora's Poleblade",
        "Marika's Hammer",
        "the Serpent-Hunter",
        "Mohgwyn's Sacred Spear"
    };

    random_shuffle(weaponNames.begin(), weaponNames.end());

    vector<Item> weapons;

    for(int i = 0; i < weaponNames.size(); i++)
    {
        weapons.push_back(Item(weaponNames[i], weapon));
    }

    Enemy orc(weapons[rand() % 10], 10);
    Player player(Item("Straight Sword", weapon), Item("Health Potion", consumable), 20);

    cout << "You are beset by an evil orc.\n";

    do
    {
        if (player.health < 8)
        {
            if (player.heldConsumable.remainingUses > 0)
            {
                if (AskYesNo("Do you wish to heal yourself?\n") == true)
                {
                    int healing = player.heldConsumable.healingAmount;
                    player.heldConsumable.remainingUses--;
                    player.health += healing;
                    cout << "You heal " << healing << " points of health.\n";
                }
                else
                {
                    cout << "You choose not to heal yourself.\n";

                    if (AskYesNo("Do you choose to attack?\n") == true)
                    {
                        cout << "You and the orc charge at each other.\n";
                        player.health -= orc.attack();
                        orc.health -= player.attack();

                        if (player.health <= 0)
                        {
                            cout << "The orc kills you.";
                            break;
                        }
                        else
                        {
                            if (orc.health <= 0)
                            {
                                cout << "You manage to kill the orc.\n";
                                cout << "You find " << orc.heldWeapon.name << " on the corpse.";
                                break;
                            }
                            else
                            {
                                cout << "You slash at each other.\n";
                                cout << "The orc prepares to attack again.\n";
                            }
                        }
                    }
                    else
                    {
                        cout << "You run away from the monster.";
                        break;
                    }
                }
            }
            else
            {
                cout << "You have no more health potions.\n";

                if (AskYesNo("Do you choose to attack?\n") == true)
                {
                    cout << "You and the orc charge at each other.\n";
                    player.health -= orc.attack();
                    orc.health -= player.attack();

                    if (player.health <= 0)
                    {
                        cout << "The orc kills you.";
                        break;
                    }
                    else
                    {
                        if (orc.health <= 0)
                        {
                            cout << "You manage to kill the orc.\n";
                            cout << "You find " << orc.heldWeapon.name << " on the corpse.";
                            break;
                        }
                        else
                        {
                            cout << "You slash at each other.\n";
                            cout << "The orc prepares to attack again.\n";
                        }
                    }
                }
                else
                {
                    cout << "You run away from the monster.";
                    break;
                }
            }
        }
        else
        {
            if (AskYesNo("Do you choose to attack?\n") == true)
            {
                cout << "You and the orc charge at each other.\n";
                player.health -= orc.attack();
                orc.health -= player.attack();

                if (player.health <= 0)
                {
                    cout << "The orc kills you.";
                    break;
                }
                else
                {
                    if (orc.health <= 0)
                    {
                        cout << "You manage to kill the orc.\n";
                        cout << "You find " << orc.heldWeapon.name << " on the corpse.";
                        break;
                    }
                    else
                    {
                        cout << "You slash at each other.\n";
                        cout << "The orc prepares to attack again.\n";
                    }
                }
            }
            else
            {
                cout << "You run away from the monster.";
                break;
            }
        }
    }
    while(true);
}