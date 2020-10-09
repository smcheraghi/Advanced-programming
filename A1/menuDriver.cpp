#include <iostream>
#include "Text.h"
#include "Menu.h"

void demoText();	// demonstrates Text objects
void demoMenu();	// demonstrates Menu objects

using namespace std;

int main()
{
    demoText();
    demoMenu();
    return 0;
}

void demoText()
{
    Text t1;									// defalt constructor
    Text t2("quick brown fox");					// conversion constructor
    Text t3{ t2 };								// copy constructor
    cout << "tl: " << t1 << endl;				// operator<< overload
    cout << "t2: " << t2 << endl;
    cout << "t3: " << t3 << endl;

    t1.append("The ");							// append a given C-string to t1's C-string
    cout << "t1: " << t1 << endl;
    t1.append(t2);								// append t2's C-string to t1's C-string
    cout << "t1: " << t1 << endl;

    t2 = Text(" jumps over ");					// assignment operator overload
    cout << "t2: " << t2 << endl;

    t3.assign("a lazy dog");					// assign a given C-string to t3's C-string
    cout << "t3: " << t3 << endl;

    t1.append(t2);								// assign t2's C-string to t1's C-string
    cout << "t1: " << t1 << endl;
    t1.append(t3);								// append t3's C-string to t1's C-string
    cout << "t1: " << t1 << endl;
    return;
}

void demoMenu() {
    try
    {
        // 1. Create an empty menu
        Menu menu;

        // 2. Print the menu
        cout << menu << endl;                                  

        // 3. Display the menu and read user's input
        int choice = menu.read_option_number();                
        cout << "You entered: " << choice << endl;

        // 4. Add an option to the menu
        menu.push_back("Pepsi");                               
        cout << menu << endl;

        // 5. Add more option to the menu
        menu.push_back("Apple juice");                        
        menu.push_back("Root beer");
        choice = menu.read_option_number();
        cout << "You entered: " << choice << endl;

        // 6. Set the top and bottom message
        menu.set_top_message("Choose your thirst crusher");    
        menu.set_bottom_message("Enter a drink number");
        cout << menu << endl;

        // 7. Remove the last option and insert a new option at index 2
        menu.pop_back();                                     
        menu.insert(2, "Iced tea with lemon");
        choice = menu.read_option_number();
        cout << "You entered: " << choice << endl;

        // 8. Remove an option by option number
        menu.pop_back();                                  
        menu.remove(1);
        cout << menu << endl;

        // 9. Remove the option number
        menu.pop_back();                                    
        cout << menu << endl;

        // 10. Final examples
        menu.clear_bottom_message();
        menu.set_top_message("Who Says You Can't Buy Happiness?\n"
            "Just Consider Our Seriously Delicious Ice Cream Flavors"); 
        menu.set_bottom_message("Enter the number of your Happiness! "); 
        menu.push_back("Bacon ice cream!");
        menu.push_back("Strawberry ice cream");
        menu.push_back("Vanilla ice cream");
        menu.push_back("Chocolate chip cookie dough ice cream"); 
        choice = menu.read_option_number();
        cout << "You entered: " << choice << endl;
    }
    catch (const std::out_of_range& oor)
    {
        std::cerr << "Out of Range error for function <get>: " << oor.what() << '\n';
    }

}



