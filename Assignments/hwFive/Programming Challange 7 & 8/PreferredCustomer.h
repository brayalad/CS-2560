/**
 * PreferredCustomer.h
 * Header for the PreferredCustomer class. It holds declares various member variables, as
 * well as functions that can be used by this class.
 */

#ifndef DATA_PREFERREDCUSTOMER_H
#define DATA_PREFERREDCUSTOMER_H

/**
 * CustomerData header file
 */
#include "CustomerData.h"

/**
 * PreferredCustomer class is a subclass of the CustomerData class, which itself is a
 * subclass of the PersonData class
 */
class PreferredCustomer : public CustomerData{

private:
    /**
     * Running total of amount of money object has spent
     */
    double purchasesAmount;
    /**
     * The value of the discount determined by the purchasesAmount variable
     */
    double discountLevel;

public:
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
    PreferredCustomer(std::string lastName, std::string firstName, std::string address, std::string city, std::string state, int zip, long long phoneNumber, bool mailingList);

    /**
     * Inrements the purchasesAmount member variable
     * @param purchase value to increment by
     */
    void increasePurchasesAmount(double purchase);

    /**
     * Getter function for discountLevel
     * @return discountLevel
     */
    double getDiscountLevel();
    /**
     * Getter function for purchasesAmount
     * @return purchasesAmmount
     */
    double getPurchasesAmount() const;

};


#endif //DATA_PREFERREDCUSTOMER_H
