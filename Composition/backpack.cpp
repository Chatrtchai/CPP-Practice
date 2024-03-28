#include <iostream>
using namespace std;

/* Sub Class */

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

    void ChangeItemName(string name) {
        item_name = name;
    }

    void ChangeItemType(string type_name)
    {
        item_type = type_name;
    }

    void ChangeItemCount(int number) {
        item_count = number;
    }

};

/* Super Class */ 

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

    /* Destructor */

    ~Backpack()
    {
        for (int i = 0; i < current_position; ++i)
        {
            delete items[i];
        }

    }

    // Member function

    void AddItem(Item *item) {

        items[current_position] = item;

        string noun;

        string i_name = items[current_position]->GetItemName();
        int i_count = items[current_position]->GetItemCount();

        // if amount of item isn't more than max_capacity
        if (current_capacity + i_count <= max_capacity) {

            current_capacity += i_count;

            if (i_count >= 2) {

                noun = "items ";

            } else {

                noun = "item ";

            }

            cout << "+ Add " << "(" << i_count << ") " << noun << i_name << " successful!. (" << current_capacity << "/" << max_capacity << ")" << endl;

            current_position++;

        // else
        } else {
            cout << "** Failed to Added " << " (" << i_count << ")" << i_name << " ! **" << endl;

            delete items[current_position];
        }

        PrintList();

    }

    void RemoveItem(int index) {

        index -= 1;

        // User doesn't input out of range of index 
        if (index >= 0 && index <= current_position) {

            int n = 0;
            string i_name = items[index]->GetItemName();
            string i_type = items[index]->GetItemType();
            int i_count = items[index]->GetItemCount();

            if (i_count >= 2) {

                while (n <= 0) {

                    cout << "[" << i_name << "]" << " : " << i_type << endl;
                    cout << "(unit) : ";
                    cin >> n;

                }
                
                // Remove from array
                if (i_count - n == 0) {

                    current_capacity -= n;

                    cout << "- Remove " << i_name << " successful!. (" << current_capacity << "/" << max_capacity << ")" << endl;

                    delete items[index];

                    // Change index
                    for (int i = index; i < current_position; i++) {
                        
                        items[i] = items[i+1];

                    }

                    current_position -= 1;

                // Already in array
                } else if (i_count - n > 0) {

                    current_capacity -= n;

                    cout << "- Remove " << "(" << n << ") " << "items " << i_name << " successful!. (" << current_capacity << "/" << max_capacity << ")" << endl;

                    items[index]->ChangeItemCount(i_count - n);

                } else {

                    cout << "** Failed to Remove " << "(" << n << ") " << i_name << " ! **" << endl;

                }

            // Remove from array
            } else {

                current_capacity -= 1;

                cout << "- Remove " << i_name << " successful!. (" << current_capacity << "/" << max_capacity << ")" << endl;

                delete items[index];

                // Change index
                for (int i = index; i < current_position; i++) {

                    items[i] = items[i + 1];
                    
                }

                current_position -= 1;

            }

        } else {

            cout << "** Not Found Index **" << endl;

        }

        PrintList();

    }

    void PrintList() {

        cout << "================ Backpack " << current_capacity << "/" << max_capacity << " =================" << endl;
        cout << "Index         Name                     " << endl;
        cout << "================================================" << endl;

        for (int i = 0; i < current_position; i++)
        {
            cout << i + 1 << "         " << items[i]->GetItemName() << " (" << items[i]->GetItemCount() << ")" << endl;
            cout << "  " << "        > " << items[i]->GetItemType() << endl;
            if (i < current_position - 1) {
                cout << endl;
            }
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

    // Remove 1 Equitment in NormalBackpack
    NormalBackpack->RemoveItem(1);

    // Remove 1 Equitment in NormalBackpack
    NormalBackpack->RemoveItem(3);

}