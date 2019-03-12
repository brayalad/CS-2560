//
// Created by BRYAN on 3/8/2019.
//

#ifndef PARKINGTICKETSIMULATOR_PARKEDCAR_H
#define PARKINGTICKETSIMULATOR_PARKEDCAR_H

#include <string>


using namespace std;

class ParkedCar {

private:
    string make;
    string model;
    string color;
    string licenceNumber;
    int minParked;

public:
    explicit ParkedCar(string = "", string = "", string = "", string = "", int = 0 );

    void setMake(string make);
    void setModel(string model);
    void setColor(string color);
    void setLicenceNumber(string licenceNumber);
    void setMinParked(int minParked);

    string getMake();
    string getModel();
    string getColor();
    string getLicenceNumber();
    int getMinParked();

    string getParkedCar();

};


#endif //PARKINGTICKETSIMULATOR_PARKEDCAR_H
