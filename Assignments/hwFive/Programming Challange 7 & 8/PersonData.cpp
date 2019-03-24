
/**
 * PersonData.cpp
 * Implementaion file for the PersonData class. Declares the implentations of the member functions
 * and member variables.
 */

/**
 * Person Data header file
 */
#include "PersonData.h"

using namespace std;

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
PersonData::PersonData(string lastName, string firstName, string address, string city, string state, int zip, long long phoneNumber) {

    setLastName(move(lastName));
    setFirstName(move(firstName));
    setAddress(move(address));
    setCity(move(city));
    setState(move(state));
    setZip(zip);
    setPhone(phoneNumber);

}

/**
* Setter function for lastName
* @param lastName last name of the person
*/
void PersonData::setLastName(string lastName) {
    this->lastName = move(lastName);
}

/**
* Setter function for firstName
* @param firstName first name of the person
*/
void PersonData::setFirstName(string firstName) {
    this->firstName = move(firstName);
}

/**
* Setter function for address
* @param address address of the person
*/
void PersonData::setAddress(string address) {
    this->address = move(address);
}

/**
* Setter function for city
* @param city city where the person lives
*/
void PersonData::setCity(string city) {
    this->city = move(city);
}

/**
* Setter function for state
* @param state state where person lives
*/
void PersonData::setState(string state) {
    this->state = move(state);
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

    string numStr = to_string(phoneNumber);
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
const string &PersonData::getLastName() const {
    return lastName;
}

/**
* Getter function for firstName
* @return firstName
*/
const string &PersonData::getFirstName() const {
    return firstName;
}

/**
* Getter function for address
* @return address
*/
const string &PersonData::getAddress() const {
    return address;
}

/**
* Getter function for city
* @return city
*/
const string &PersonData::getCity() const {
    return city;
}

/**
* Getter function for state
* @return state
*/
const string &PersonData::getState() const {
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
const string &PersonData::getPhone() const {
    return phone;
}


