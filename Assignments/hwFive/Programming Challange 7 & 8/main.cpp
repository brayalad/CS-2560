/**
 * hwFive Polymorphism Assignment
 *
 * This is a program for assignment 5 of CS 2560: C++ Programming.
 * The Assignment was to do problem #7 and #8 from chapter 15 of the book.
 * This program incorporates both problems #7 and #8 to make a complete program
 * that demonstrates how polymorphism and class inheritance are used C++.
 *
 *
 * Problem 7. PersonData and CustomerData classes
 * Design a class named PersonData with the following member variables:
 *  -lastName
 *  -firstName
 *  -address
 *  -city
 *  -state
 *  -zip
 *  -phone
 * Write the appropriate accessor and mutator functions for these member variables.
 * Next, design a class named CustomerData, which is derived from the PersonData
 * class. The CustomerData class should have the following member variables:
 *  -customerNumber
 *  -mailingList
 * The CustomerNumber variable will be used to hold a unique integer for each customer.
 * The mailingList variable should be a bool. It will be set to true if the customer
 * wishes to be on a mailing list, or false if the customer does not wish to be on a mail-
 * ing list. Write appropriate accessor and mutator functions for these member variables.
 * Demonstrate an object of the CustomerClass in a simple program.
 *
 *
 * Problem 8. PreferredCustomer Class
 * A retail store has a preferred customer plan where customers may earn discounts on all
 * their purchases. The amount of a customer's discount is determined by the amount of
 * the customer's cumulative purchases in the store.
 *  -When a preferred customer spends $500, he or she gets a 5% discount on all future
 *   purchases.
 *   -When a preferred customer spends $1,000, he or she gets a 6% discount on all future
 *   purchases.
 *   -When a preferred customer spends $1,500, he or she gets a 7% discount on all future
 *   purchases.
 *   -When a preferred customer spends $2,000 or more, he or she gets a 10% discount
 *   on all future purchases.
 * Design a class named PreferredCustomer which is derived from the CustomerData
 * class you created in Programming Challenge 7. The PreferredCustomer class should
 * have the following member variables:
 *  -purchasesAmount (a double)
 *  -discountLevel (a double)
 * The purchasesAmount variable holds the total of a customer's purchases to date. The
 * discountLevel variable should be set to the correct discount percentage, according to
 * the store's preffered customer plan. Write appropriate member fucntions for this class
 * and demonstrate it in a sinple program.
 * Input Validation: Do not accept negative values for any sales figures.
 *
 * This program allows the user to make either a regular customer object or a preferred
 * customer object. They are then presented with a menu that allows the user to buy
 * a pre-determined item from the store, purchase a custom item, change information in
 * the object, print out current object information, and can make a new account to replace,
 * the previous account. If the user makes a PreferredCustomer object, they are able to take
 * advantage of the discounts which are offered as part of the stores program.
 *
 * main.cpp
 *
 * Author: Bryan Ayala
 *
 *
 */

/**
 * CustomerData header file
 */
#include "CustomerData.h"
/**
 * PrefferedCustomer header file
 */
#include "PreferredCustomer.h"
/**
 * Used for input and output to console
 */
#include <iostream>
/**
 * Using strings
 */
#include <string>
/**
 * Used to make string object strings
 */
#include <sstream>
/**
 * used to hold a dynamic sized list
 */
#include <vector>

using namespace std;

/**
 * Items that are purchased by user
 */
struct Item;
/**
 * List that hods the pre-determined items
 */
static vector<Item> items;
/**
 * CustomerData object pointer
 */
static CustomerData *customer;
/**
 * PreferredCustomer object pointer
 */
static PreferredCustomer *preferredCustomer;

/**Forward declaration of program functions*/
/**
 * Intializes pre-determined Items
 */
void initializeItemsAvailable();
/**
 * Creates new customer object
 * @param pref if preferred customer or not
 */
void createCustomer(bool pref);
/**
 * PreferredCustomer object options
 */
void preferredCustomerMenu();
/**
 * CustomerData object options
 */
void customerMenu();
/**
 * Buy pre-determined Items
 * @return chosen pre-determined Item
 */
Item* buyItemFromStore();
/**
 * Buy custom made Item
 * @return custom Item
 */
Item* buyCustomItem();
/**
 * Change member variable values
 * @param currentCustomer Object who's values will be changed
 */
void changeAccountInfo(CustomerData *currentCustomer);
/**
 * Generate information outline on object
 * @param data object to generate data about
 * @return string outline of object
 */
string getCustomerInfo(CustomerData *data);
/**
 * Prints pre-determined Item list
 */
void printItems();
/**
 * Gets user input
 * @return user input string
 */
string getInput();

/**
 * Main function where the program is started. The user will be asked if they wish
 * to create a new object, if so they will be asked if they want to create a
 * regular customer object or a preferred customer object. The program will then
 * display the appropriate menu options for the created object to the user.
 * @param argc amount of arguments passed
 * @param argv array holding the values of the arguments
 * @return error code 0
 */
int main(int argc, char **argv) {

    cout << "\nCustomer and Preferred Customer Program\n"
            "-----------------------------------------" << endl;

    initializeItemsAvailable();

    string choice;
    while(choice!="no"){
        cout << "\nWould you like to make a new customer account? (yes/no)" << endl;
        choice = getInput();
        if(choice=="yes") {
            string accountType;
            while (accountType!="yes" && accountType!="no") {
                cout << "\nDo you want to become a preferred customer?(yes/no)\nEnter --help for more information."<< endl;
                accountType = getInput();
                if(accountType=="yes"){
                    preferredCustomerMenu();
                    break;
                }
                else if(accountType=="no"){
                    customerMenu();
                    break;
                }
                else if(accountType=="--help"){
                    cout << "\nCustomers part of the preferred customer plan may earn discounts on all of their purchases.\n"
                            "The amount of the discount is based on the cumulative purchases made at the store\n"
                            "   *Spend $500 to receive a 5% discount on all future purchases.\n"
                            "   *Spend $1,000 to receive a 6% discount on all future purchases.\n"
                            "   *Spend $1,500 to receive a 7% discount on all future purchases.\n"
                            "   *Spend $2,000 or more to receive a 10% discount on all future purchases." << endl;
                }
                else{
                    cout << "Invalid Input.\nPlease Try Again." << endl;
                }
            }
        }
        else if(choice=="no"){
            cout << "\nThank you for using this program!\n" << endl;
        }
        else{
            cout << "\nInvalid Input.\nPlease Try Again." << endl;
        }
    }

    return 0;
}

/**
 * Definition of the Item structure. This data type holds a string for
 * its type of Item. It also holds a double for the Item's price. Structure
 * also has a constructor to intialize both variables.
 */
struct Item{
    string type;
    double price;
    Item(string t, double p){
        type=move(t);
        price=p;
    }
};

/**
 * Initializes and adds the pre-determined items to the list representing the store.
 * Items can be added or removed by the progammer by modifying this function.
 */
void initializeItemsAvailable(){
    items.emplace_back("Hat", 75.00);
    items.emplace_back("Shirt", 100.00);
    items.emplace_back("Belt", 50.00);
    items.emplace_back("Pants", 125.00);
    items.emplace_back("Shoes", 200.00);
}

/**
 * This function will dynamically allocate memory to create and store either a
 * CustomerData object or PreferredCustomer object, depending on the user's choice.
 * The user will be asked to enter values for the member variables of the object.
 * Once correct inputs are made, the program will create an object stored in the heap.
 * @param pref whether object is PreferredCustomer or not
 */
void createCustomer(bool pref){
    cout << "\nPlease Input Customer Information: " << endl;

    cout << "   Enter Last Name: ";
    string lastName = getInput();

    cout << "   Enter First Name: ";
    string firstName = getInput();

    cout << "   Enter Address: ";
    string address = getInput();

    cout << "   Enter City: ";
    string city = getInput();

    cout << "   Enter State: ";
    string state = getInput();

    int zip = 0;
    while(zip>99999 || zip<10000) {
        cout << "   Enter Zip Code: ";
        try {
            zip = stoi(getInput());
        }
        catch (exception& e){
            zip = 0;
            cout << "\n\nZip must be an integer." << endl;
        }
        if(zip>99999 || zip<10000)
            cout << "Zip code must have 5 digits and begin with a 1.\nPlease try again.\n" << endl;
    }

    long long phoneNumber = 0;
    while(phoneNumber>9999999999 || phoneNumber<2000000000){
        cout << "   Enter 10-Digit Phone Number: ";
        try {
            phoneNumber = stoll(getInput());
        }
        catch (exception& e){
            phoneNumber = 0;
            cout << "\n\nPhone number must be an integer." << endl;
        }
        if(phoneNumber>9999999999 || phoneNumber<2000000000)
            cout << "Phone number must have 10 digits and can not begin with a 0 or 1.\nPlease try again.\n" << endl;
    }

    bool mailingList = true;
    string mailChoice;
    while(mailChoice!="yes" && mailChoice!="no") {
        cout << "\nWould you like to join our mailing list? (yes/no)" << endl;
        mailChoice = getInput();
        if(mailChoice=="yes" || mailChoice=="no")
            mailingList = (mailChoice=="yes");
        else
            cout << "\nInvalid Input.\nPlease try again." << endl;
    }

    if(pref) {
        preferredCustomer = new PreferredCustomer(lastName, firstName, address, city, state, zip, phoneNumber, mailingList);
        cout << getCustomerInfo(preferredCustomer);
    }
    else{
        customer = new CustomerData(lastName, firstName, address, city, state, zip, phoneNumber, mailingList);
        cout << getCustomerInfo(customer);
    }

}

/**
 * Menu options for the PrefferedCustomer object. User is presented with a menu that allows them to buy
 * a pre-determined item from the store, purchase a custom item, change information in
 * the object, print out current object information, and can make a new account to replace,
 * the previous account, and when buying an item, they are able to take
 * advantage of the discounts which are offered as part of the stores program.
 */
void preferredCustomerMenu(){

    createCustomer(true);

    string choice;
    while(true) {
        cout << "\nChoose an option from the preferred customer menu:\n"
                "   1. Make a purchase from the store\n"
                "   2. Make a custom purchase\n"
                "   3. Change account info\n"
                "   4. See current account info\n"
                "   5. Make a new account\n"
                "Enter choice: ";
        choice = getInput();
        if (choice == "1") {
            Item *purchased = buyItemFromStore();
            double amountSpent = purchased->price - (purchased->price * preferredCustomer->getDiscountLevel());
            cout << "\nPurchased " << purchased->type << " for $" << amountSpent << " with an applied discount of "
                 << (preferredCustomer->getDiscountLevel())*100 << "%." << endl;
            preferredCustomer->increasePurchasesAmount(amountSpent);
        } else if (choice == "2") {
            Item *customItem = buyCustomItem();
            double amountSpent = customItem->price - (customItem->price * preferredCustomer->getDiscountLevel());
            cout << "\nPurchased " << customItem->type << " for $" << amountSpent << " with an applied discount of "
                 << (preferredCustomer->getDiscountLevel())*100 << "%." << endl;
            preferredCustomer->increasePurchasesAmount(amountSpent);
            delete (customItem);
        } else if (choice == "3") {
            changeAccountInfo(preferredCustomer);
        } else if (choice == "4") {
            cout << getCustomerInfo(preferredCustomer)
                 << "   Amount Spent: $" << preferredCustomer->getPurchasesAmount() << "\n"
                 << "   Account receives a " << (preferredCustomer->getDiscountLevel() * (double) 100)
                 << "% discount on all future purchases" << endl;
        } else if (choice == "5") {
            delete(preferredCustomer);
            break;
        }
        else{
            cout << "\n\nInvalid Input.\nPlease Try Again." << endl;
        }
    }
}

/**
 * Menu options for the CustomerData object. User is presented with a menu that allows them to buy
 * a pre-determined item from the store, purchase a custom item, change information in
 * the object, print out current object information, and can make a new account to replace,
 * the previous account.
 */
void customerMenu(){

    createCustomer(false);

    string choice;
    while(choice!="5") {
        cout << "\nChoose an option from the customer menu:\n"
                "   1. Make a purchase from the store\n"
                "   2. Make a custom purchase\n"
                "   3. Change account info\n"
                "   4. See current account info\n"
                "   5. Make a new account\n"
                "Enter choice: ";
        choice = getInput();
        if (choice == "1") {
            Item *purchased = buyItemFromStore();
            cout << "\nPurchased " << purchased->type << " for $" << purchased->price << endl;
        } else if (choice == "2") {
            Item *customItem = buyCustomItem();
            cout << "\nPurchased " << customItem->type << " for $" << customItem->price << endl;
            delete (customItem);
        } else if (choice == "3") {
            changeAccountInfo(customer);
        } else if (choice == "4") {
            cout << getCustomerInfo(customer) << endl;
        } else if (choice == "5") {
            delete(customer);
            break;
        }
        else{
            cout << "\n\nInvalid Input.\nPlease Try Again." << endl;
        }
    }
}

/**
 * Function allows user to buy a pre-determined item.
 * The address of the item chosen is returned to the
 * calling function.
 * @return Item Pre-determined item chosen by user
 */
Item* buyItemFromStore(){
    int choice = -1;
    while(choice<1 || choice>(int)items.size()) {
        printItems();
        cout << "Enter which item to buy: ";
        try {
            choice = stoi(getInput());
        }
        catch(exception& e){
            choice = -1;
            cout << "\n\nInput must be an Integer" << endl;
        }
        if(choice == -1)
            cout << "Invalid Input.\nPlease try again." << endl;
    }

    return &items[choice-1];
}

/**
 * Function allows user to buy a custom Item. User enters
 * the type of Item, as well the price that it cost. Once
 * entered, the function will return a new dynamically allocated
 * Item back to the callback function.
 * @return Custom Item created by user
 */
Item* buyCustomItem(){
    cout << "\nEnter type of item: ";
    string type = getInput();

    double price = -1.1;
    while(price<0) {
        cout << "Enter price of item: $";
        try {
            price = stod(getInput());
        }
        catch (exception& e){
            price = -1.1;
            cout << "\n\nPrice must be a number." << endl;
        }
        if(price<0)
            cout << "Price can not be negative.\nPlease try again." << endl;
    }

    return new Item(type, price);
}

/**
 * Function allows user to change member variables of whichever object
 * is passed as a parameter. Both CustomerData and PreferredCustomer
 * objects are accepted by this function.
 * @param currentCustomer Object that is currently being used
 */
void changeAccountInfo(CustomerData *currentCustomer){

    string choice;
    while(choice!="9") {
        cout << "\nWhat would you like to change?\n"
                "   1. Last Name\n"
                "   2. First Name\n"
                "   3. Address\n"
                "   4. City\n"
                "   5. State\n"
                "   6. Zip Code\n"
                "   7. Phone\n"
                "   8. Mailing List\n"
                "   9. Go Back\n"
                "Enter Choice: ";
        choice = getInput();
        if (choice == "1") {
            cout << "Enter new last name: ";
            currentCustomer->setLastName(getInput());
            cout << "\nLast name changed to: " << currentCustomer->getLastName() << endl;
        } else if (choice == "2") {
            cout << "Enter new first name: ";
            currentCustomer->setFirstName(getInput());
            cout << "\nFirst name changed to: " << currentCustomer->getFirstName() << endl;
        } else if (choice == "3") {
            cout << "Enter new address: ";
            currentCustomer->setAddress(getInput());
            cout << "\nAddress changed to: " << currentCustomer->getAddress() << endl;
        } else if (choice == "4") {
            cout << "Enter new city: ";
            currentCustomer->setCity(getInput());
            cout << "\nCity changed to: " << currentCustomer->getCity() << endl;
        } else if (choice == "5") {
            cout << "Enter new state: ";
            currentCustomer->setState(getInput());
            cout << "\nState changed to: " << currentCustomer->getState() << endl;
        } else if (choice == "6") {
            int newZip = 0;
            while(newZip>99999 || newZip<10000) {
                cout << "Enter new zip code: ";
                try {
                    newZip = stoi(getInput());
                }
                catch (exception& e){
                    newZip = 0;
                    cout << "\n\nZip code must be an integer." << endl;
                }
                if(newZip>99999 || newZip<10000)
                    cout << "Zip code must have 5 digits and begin with a 1.\n" << endl;
            }
            currentCustomer->setZip(newZip);
            cout << "\nZip code changed to: " << currentCustomer->getZip() << endl;
        } else if (choice == "7") {
            long long newPhoneNumber = 0;
            while(newPhoneNumber>9999999999 || newPhoneNumber<2000000000){
                cout << "Enter new phone number: ";
                try {
                    newPhoneNumber = stoll(getInput());
                }
                catch (exception& e){
                    newPhoneNumber = 0;
                    cout << "\n\nPhone number must be an Integer." << endl;
                }
                if(newPhoneNumber>9999999999 || newPhoneNumber<2000000000)
                    cout << "Phone number must have 10 digits and can not begin with a 0 or 1.\nPlease try again.\n" << endl;
            }
            currentCustomer->setPhone(newPhoneNumber);
            cout << "\nPhone changed to: " << currentCustomer->getPhone() << endl;
        } else if (choice == "8") {
            if (currentCustomer->getMailingList()) {
                string mailChoice;
                cout << "You are currently on the mailing list. Would you like to be removed? (yes/no)" << endl;
                mailChoice = getInput();
                if (mailChoice == "yes") {
                    currentCustomer->setMailingList(false);
                    cout << "\nYou have been removed from the mailing list" << endl;
                }
            } else {
                string mailChoice;
                cout << "You are currently not on the mailing list. Would you like to be added? (yes/no)" << endl;
                mailChoice = getInput();
                if (mailChoice == "yes") {
                    currentCustomer->setMailingList(true);
                    cout << "\nYou have been added to the mailing list" << endl;
                }
            }
        } else if (choice == "9") {
            break;
        } else {
            cout << "\n\nInvalid Input.\nPlease Try Again." << endl;
        }
    }
}

/**
 * Function creates and returns a string outlining the information
 * that the object which is passed as a parameter holds.
 * @param data Object currently being used
 * @return string outline of the information encapsulated in the object
 */
string getCustomerInfo(CustomerData *data){

    ostringstream customerInfo;

    customerInfo << "\nCustomer Info:\n-----------------------------------------------------------------------\n"
                 << "   Name: " << data->getFirstName() << " " << data->getLastName() << "\n"
                 << "   Address: " << data->getAddress() << " " << data->getCity() << ", " << data->getState() << " " << data->getZip() << "\n"
                 << "   Phone Number: " << data->getPhone() << "\n"
                 << "   Customer ID:  " << data->getCustomerNumber() << endl;
    if(data->getMailingList())
        customerInfo << "   Part Of Our Mailing List" << endl;
    else
        customerInfo << "   Not Part Of Our Mailing List" << endl;

    return customerInfo.str();
}

/**
 * Function prints out the list that stores all pre-determined Items
 */
void printItems(){
    cout << "\nItems Available for purchase:" << endl;
    for(unsigned int i=0; i<items.size(); ++i)
        cout << "   " << (i+1) << ". " << items[i].type << ": $" << items[i].price << endl;
}

/**
 * Function returns the users input as a string.
 * @return user input
 */
string getInput(){
    string input;
    getline(cin,input);
    return input;
}
