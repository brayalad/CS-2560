/**
 * CustomerData.cpp
 * Implementaion file for the CustomerData class. Declares the implentations of the member functions
 * and member variables.
 */

/**
 * CustomerData header file
 */
#include "CustomerData.h"
/**
 * Random number generator libary used to generate unique number for customer
 */
#include <random>

using namespace std;

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
CustomerData::CustomerData(string lastName, string firstName, string address, string city, string state, int zip, long long phoneNumber, bool mailingList)
    : PersonData(move(lastName), move(firstName), move(address), move(city), move(state), zip, phoneNumber){

    setMailingList(mailingList);

   random_device rand;
   default_random_engine randomEngine{rand()};
   uniform_int_distribution<int> generatedNumber{1,99999999};

   customerNumber = generatedNumber(randomEngine);

}

/**
* Setter function for mailingList
* @param mailingList
*/
void CustomerData::setMailingList(bool mailingList) {
    this->mailingList = mailingList;
}

/**
* Getter function for mailingList
* @return mailingList
*/
int CustomerData::getCustomerNumber() const {
    return customerNumber;
}

/**
* Getter function for customerNumber
* @return customerNumber
*/
bool CustomerData::getMailingList() const {
    return mailingList;
}
