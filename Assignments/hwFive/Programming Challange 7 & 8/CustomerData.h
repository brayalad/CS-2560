/**
 * CustomerData.h
 * Header for the CustomerData class. It holds declares various member variables, as
 * well as functions that can be used by this class.
 */

#ifndef DATA_CUSTOMERDATA_H
#define DATA_CUSTOMERDATA_H

/**
 * PersonData header file
 */
#include "PersonData.h"

/**
 * CustomerData class is a subclass of the PersonData class. It also acts as
 * the base class for the PreferredCustomer class
 */
class CustomerData : public PersonData{

private:
    /**
     * int that holds customers unique identification number
     */
    int customerNumber;
    /**
     * bool that holds whether or not customer is part of mailing list
     */
    bool mailingList;

public:
    /**
     * Constructor for class. Can be used on its own or by one of its subclasses
     * @param lastName last name of the person
     * @param firstName first name of the person
     * @param address address of the person
     * @param city city where the person lives
     * @param state state where the person lives
     * @param zip zip code of where the person lives
     * @param phoneNumber phone number of where the person lives
     * @param mailingList whether or not person is part of mailing list
     */
    CustomerData(std::string lastName, std::string firstName, std::string address, std::string city, std::string state, int zip, long long phoneNumber, bool mailingList);

    /**
     * Setter function for mailingList
     * @param mailingList
     */
    void setMailingList(bool mailingList);

    /**
     * Getter function for mailingList
     * @return mailingList
     */
    bool getMailingList() const;
    /**
     * Getter function for customerNumber
     * @return customerNumber
     */
    int getCustomerNumber() const;

};


#endif //DATA_CUSTOMERDATA_H
