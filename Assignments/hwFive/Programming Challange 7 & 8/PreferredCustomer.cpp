/**
 * PreferredCustomer.cpp
 * Implementaion file for the PreferredCustomer class. Declares the implentations of the member functions
 * and member variables.
 */

/**
 * PreferredCustomer header file
 */
#include "PreferredCustomer.h"


/**
* Constructor for class. Can only be used on its own.
* @param lastName last name of the person
* @param firstName first name of the person
* @param address address of the person
* @param city city where the person lives
* @param state state where the person lives
* @param zip zip code of where the person lives
* @param phoneNumber phone number of where the person lives
* @param mailingList whether or not person is part of mailing list
*/
PreferredCustomer::PreferredCustomer(std::string lastName, std::string firstName, std::string address, std::string city, std::string state, int zip, long long phoneNumber, bool mailingList)
: CustomerData(std::move(lastName), std::move(firstName), std::move(address), std::move(city), std::move(state), zip, phoneNumber, mailingList) {
    purchasesAmount = 0.0;
    discountLevel = 0.0;
}

/**
* Inrements the purchasesAmount member variable
* @param purchase value to increment by
*/
void PreferredCustomer::increasePurchasesAmount(double purchase) {
    purchasesAmount += purchase;
}

/**
* Getter function for discountLevel
* @return discountLevel
*/
double PreferredCustomer::getDiscountLevel() {

    if(purchasesAmount<500)
        discountLevel = 0.00;
    else if(purchasesAmount>=500 && purchasesAmount<1000)
        discountLevel = 0.05;
    else if(purchasesAmount>=1000 && purchasesAmount<1500)
        discountLevel = 0.06;
    else if(purchasesAmount>=1500 && purchasesAmount<2000)
        discountLevel = 0.07;
    else if(purchasesAmount>2000)
        discountLevel = 0.10;


    return discountLevel;
}

/**
* Getter function for purchasesAmount
* @return purchasesAmmount
*/
double PreferredCustomer::getPurchasesAmount() const {
    return purchasesAmount;
}
