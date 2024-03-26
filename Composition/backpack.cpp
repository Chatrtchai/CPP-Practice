#include <iostream>
using namespace std;

class Item {
private:
    string item_name;
    string item_type;
    int item_count;
public:
    
    /* Consturctor */ 

    Item(string name) {
        item_name = name;
        item_type = "N/A";
        item_count = 1;
    }

    Item(string name, string type) {
        item_name = name;
        item_type = type;
        item_count = 1;
    }

    Item(string name, string type, int count)
    {
        item_name = name;
        item_type = type;
        item_count = count;
    }

    // Member function

    string GetItemName() {
        return item_name;
    }

    string GetItemType() {
        return item_type;
    }

    int GetItemCount() {
        return item_count;
    }

};

class Backpack {
private:
    int current_position;
    int current_capacity;
    int max_capacity;
    Item **items;
public:

    /* Constructor */

    Backpack() : current_position(0), current_capacity(0), max_capacity(10)
    {
        items = new Item*[10];
    }

    Backpack(int max) : current_position(0), current_capacity(0)
    {
        if ( max > 20) {
            max_capacity = 20;
        } else {
            max_capacity = max;
        }

        items = new Item*[max];

    }

    // Destructor
    ~Backpack()
    {
        for (int i = 0; i < current_position; ++i)
        {
            delete items[i];
        }

    }

    // Member function

    void AddItem(Item *item) {

        string noun;

        items[current_position] = item;

        if (current_capacity + items[current_position]->GetItemCount() <= max_capacity) {

            current_capacity += items[current_position]->GetItemCount();

            if (items[current_position]->GetItemCount() >= 2) {

                noun = "items ";

            } else {

                noun = "item ";

            }

            cout << "+ Add " << "(" << items[current_position]->GetItemCount() << ") " << noun << items[current_position]->GetItemName() << " successful!. (" << current_capacity << "/" << max_capacity << ")" << endl;

            current_position++;

        } else {
            cout << "** Failed to Added " << " (" << items[current_position]->GetItemCount() << ")" << items[current_position]->GetItemName() << " ! **" << endl;

            delete items[current_position];
        }
    }

    void PrintList() {

        cout << "================ Backpack " << current_capacity << "/" << max_capacity << " =================" << endl;
        cout << "Index         Name                     " << endl;
        cout << "================================================" << endl;

        for (int i = 0; i < current_position; i++)
        {
            cout << i + 1 << "         " << items[i]->GetItemName() << " (" << items[i]->GetItemCount() << ")" << endl;
            cout << "  " << "        > " << items[i]->GetItemType() << endl;
            cout << endl;
        }

        cout << "================================================" << endl;
        
    }

};

int main() {

    /* Create Item */ 

    // Clothing
    Item *Shirt = new Item("White shirt", "Clothing");
    Item *Pants = new Item("Jeans Pants", "Clothing");
    Item *Trousers = new Item("Trousers", "Clothing");

    // Equitment
    Item *SmartPhone = new Item("Samsung Galaxy A73", "Equitment");
    Item *Camera = new Item("Kodak Film Camera Ultra F9", "Equitment");

    // Food / Beverage
    Item *Food = new Item("Canned food", "Food", 3);
    Item *Water = new Item("Bottle water", "Beverage", 2);

    /* Create Backpack */
    Backpack *NormalBackpack = new Backpack();

    // Add 2 Equitment to NormalBackpack
    NormalBackpack->AddItem(SmartPhone);
    NormalBackpack->AddItem(Camera);

    // Add Food and Beverage to NormalBackpack
    NormalBackpack->AddItem(Food);
    NormalBackpack->AddItem(Water);

    // Add Clothing to NormalBackpack
    NormalBackpack->AddItem(Shirt);
    NormalBackpack->AddItem(Pants);
    NormalBackpack->AddItem(Trousers);

    // Print List in NormalBackPack
    NormalBackpack->PrintList();

}