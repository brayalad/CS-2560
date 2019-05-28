//
// Created by BRYAN on 3/8/2019.
//
#include <string>
#include <sstream>
#include "ParkedCar.h"

ParkedCar::ParkedCar(std::string make, std::string model, std::string color, std::string licenceNumber, int minParked) {
    this->make = make;
    this->model = model;
    this->color = color;
    this ->licenceNumber = licenceNumber;
    this->minParked = minParked;
}

void ParkedCar::setMake(std::string make) {
    this->make = make;
}

void ParkedCar::setModel(std::string model) {
    this->model = model;
}

void ParkedCar::setColor(std::string color) {
    this->color = color;
}

void ParkedCar::setLicenceNumber(std::string licenceNumber) {
    this->licenceNumber = licenceNumber;
}

void ParkedCar::setMinParked(int minParked) {
    this->minParked = minParked;
}

const std::string& ParkedCar::getMake() const{
    return make;
}

const std::string& ParkedCar::getModel() const{
    return model;
}

const std::string& ParkedCar::getColor() const{
    return color;
}

const std::string& ParkedCar::getLicenceNumber() const{
    return licenceNumber;
}

int ParkedCar::getMinParked() const{
    return minParked;
}

std::string ParkedCar::getParkedCar() {
    std::ostringstream car;
    car << "Car Information:\n   "
           "Make: " << make + "\n   "
           "Model: " << model << "\n   "
           "Color: " << color << "\n   "
           "Licence Number: " << licenceNumber << std::endl;
    return car.str();
}