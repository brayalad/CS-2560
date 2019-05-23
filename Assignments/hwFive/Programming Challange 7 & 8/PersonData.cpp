
/**
 * PersonData.cpp
 * Implementaion file for the PersonData class. Declares the implentations of the member functions
 * and member variables.
 */

/**
 * Person Data header file
 */
#include "PersonData.h"


/**
 * Default Constructor
 */
PersonData::PersonData() = default;

/**
* Constructor which can only be used by a class derived from this class
* @param lastName last name of the person
* @param firstName first name of the person
* @param address address of the person
* @param city city where the person lives
* @param state state where the person lives
* @param zip zip code of where the person lives
* @param phoneNumber phone number of where the person lives
*/
PersonData::PersonData(std::string lastName, std::string firstName, std::string address, std::string city, std::string state, int zip, long long phoneNumber) {

    setLastName(std::move(lastName));
    setFirstName(std::move(firstName));
    setAddress(std::move(address));
    setCity(std::move(city));
    setState(std::move(state));
    setZip(zip);
    setPhone(phoneNumber);

}

/**
* Setter function for lastName
* @param lastName last name of the person
*/
void PersonData::setLastName(std::string lastName) {
    this->lastName = std::move(lastName);
}

/**
* Setter function for firstName
* @param firstName first name of the person
*/
void PersonData::setFirstName(std::string firstName) {
    this->firstName = std::move(firstName);
}

/**
* Setter function for address
* @param address address of the person
*/
void PersonData::setAddress(std::string address) {
    this->address = std::move(address);
}

/**
* Setter function for city
* @param city city where the person lives
*/
void PersonData::setCity(std::string city) {
    this->city = std::move(city);
}

/**
* Setter function for state
* @param state state where person lives
*/
void PersonData::setState(std::string state) {
    this->state = std::move(state);
}

/**
* Setter function for zip
* @param zip zip code of where the person lives
*/
void PersonData::setZip(int zip) {
    this->zip = zip;
}

/**
* Setter function for phoneNumber
* @param phoneNumber  phone number of the person
*/
void PersonData::setPhone(long long phoneNumber) {

    std::string numStr = std::to_string(phoneNumber);
    phone="(";
    for(unsigned int i=0;i<numStr.length();++i){
        phone+=numStr.at(i);
        if(i==2)
            phone+=")-";
        if(i==5 && numStr.length()==10)
            phone+="-";
    }
}

/**
* Getter function for lastName
* @return lastName
*/
const std::string &PersonData::getLastName() const {
    return lastName;
}

/**
* Getter function for firstName
* @return firstName
*/
const std::string &PersonData::getFirstName() const {
    return firstName;
}

/**
* Getter function for address
* @return address
*/
const std::string &PersonData::getAddress() const {
    return address;
}

/**
* Getter function for city
* @return city
*/
const std::string &PersonData::getCity() const {
    return city;
}

/**
* Getter function for state
* @return state
*/
const std::string &PersonData::getState() const {
    return state;
}

/**
* Getter function for zip
* @return Getter function for
*/
int PersonData::getZip() const {
    return zip;
}

/**
* Getter function for phone
* @return phone
*/
const std::string &PersonData::getPhone() const {
    return phone;
}


