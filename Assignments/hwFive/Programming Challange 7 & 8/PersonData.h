/**
 * PersonData.h
 * Header for the PersonData class. This class acts as a base class which other
 * classes can be derived from. It holds declares various member variables, as
 * well as functions that can be used by this class.
 */
#ifndef DATA_PERSONDATA_H
#define DATA_PERSONDATA_H

#include <string>

/**
 * This class acts as a base class which other
 * classes can be derived from. It holds declares
 * various member variables, as well as functions
 * that can be used by this class.
 */
class PersonData {

private:
    /**
     * string that holds the objects lastName member variable
     */
    std::string lastName;
    /**
     * string that holds the objects firstName member variable
     */
    std::string firstName;
    /**
     * string that holds the objects address member variable
     */
    std::string address;
    /**
     * string that holds the objects city member variable
     */
    std::string city;
    /**
     * string that holds the objects state member variable
     */
    std::string state;
    /**
     * int that holds the objects zip member variable
     */
    int zip;
    /**
     * string that holds the objects phone member variable
     */
    std::string phone;

    /**
     * Default constructor
     */
    PersonData();

protected:
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
    PersonData(std::string lastName, std::string firstName, std::string address, std::string city, std::string state, int zip, long long phoneNumber);

public:
    /**
     * Setter function for lastName
     * @param lastName last name of the person
     */
    void setLastName(std::string lastName);
    /**
     * Setter function for firstName
     * @param firstName first name of the person
     */
    void setFirstName(std::string firstName);
    /**
     * Setter function for address
     * @param address address of the person
     */
    void setAddress(std::string address);
    /**
     * Setter function for city
     * @param city city where the person lives
     */
    void setCity(std::string city);
    /**
     * Setter function for state
     * @param state state where person lives
     */
    void setState(std::string state);
    /**
     * Setter function for zip
     * @param zip zip code of where the person lives
     */
    void setZip(int zip);
    /**
     * Setter function for phoneNumber
     * @param phoneNumber  phone number of the person
     */
    void setPhone(long long phoneNumber);

    /**
     * Getter function for lastName
     * @return lastName
     */
    const std::string& getLastName() const;
    /**
     * Getter function for firstName
     * @return firstName
     */
    const std::string& getFirstName() const;
    /**
     * Getter function for address
     * @return address
     */
    const std::string& getAddress() const;
    /**
     * Getter function for city
     * @return city
     */
    const std::string& getCity() const;
    /**
     * Getter function for state
     * @return state
     */
    const std::string& getState() const;
    /**
     * Getter function for zip
     * @return Getter function for
     */
    int getZip() const;
    /**
     * Getter function for phone
     * @return phone
     */
    const std::string& getPhone() const;


};


#endif //DATA_PERSONDATA_H
