//
// Created by BRYAN on 3/8/2019.
//

#ifndef PARKINGTICKETSIMULATOR_PARKEDCAR_H
#define PARKINGTICKETSIMULATOR_PARKEDCAR_H

#include <string>

class ParkedCar {

private:
    std::string make;
    std::string model;
    std::string color;
    std::string licenceNumber;
    int minParked;

public:
    explicit ParkedCar(std::string = "", std::string = "", std::string = "", std::string = "", int = 0 );

    void setMake(std::string make);
    void setModel(std::string model);
    void setColor(std::string color);
    void setLicenceNumber(std::string licenceNumber);
    void setMinParked(int minParked);

    const std::string& getMake() const;
    const std::string& getModel() const;
    const std::string& getColor() const ;
    const std::string& getLicenceNumber() const ;
    int getMinParked() const;

    std::string getParkedCar();

};


#endif //PARKINGTICKETSIMULATOR_PARKEDCAR_H
