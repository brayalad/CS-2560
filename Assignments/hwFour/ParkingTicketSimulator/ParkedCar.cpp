//
// Created by BRYAN on 3/8/2019.
//
#include <string>
#include <sstream>
#include "ParkedCar.h"

using namespace std;

ParkedCar::ParkedCar(string make, string model, string color, string licenceNumber, int minParked) {
    this->make = make;
    this->model = model;
    this->color = color;
    this ->licenceNumber = licenceNumber;
    this->minParked = minParked;
}

void ParkedCar::setMake(string make) {
    this->make = make;
}

void ParkedCar::setModel(string model) {
    this->model = model;
}

void ParkedCar::setColor(string color) {
    this->color = color;
}

void ParkedCar::setLicenceNumber(string licenceNumber) {
    this->licenceNumber = licenceNumber;
}

void ParkedCar::setMinParked(int minParked) {
    this->minParked = minParked;
}

string ParkedCar::getMake() {
    return make;
}

string ParkedCar::getModel() {
    return model;
}

string ParkedCar::getColor() {
    return color;
}

string ParkedCar::getLicenceNumber() {
    return licenceNumber;
}

int ParkedCar::getMinParked() {
    return minParked;
}

string ParkedCar::getParkedCar() {
    ostringstream car;
    car << "Car Information:\n   "
           "Make: " << make + "\n   "
           "Model: " << model << "\n   "
           "Color: " << color << "\n   "
           "Licence Number: " << licenceNumber << endl;
    return car.str();
}