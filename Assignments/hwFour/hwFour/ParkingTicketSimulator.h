#ifndef HWFOUR_PARKINGTICKETSIMULATOR_H
#define HWFOUR_PARKINGTICKETSIMULATOR_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"

using namespace std;

const static int parkingTimeLimit = 60;
const static int amountOfMeters = 20;
static bool initiailized = false;
static ParkingMeter meters[amountOfMeters];
static PoliceOfficer officer;


static string getInput();
void seeAllMeters();
void makePoliceOfficer();
ParkedCar getParkedCar(int minParked);
ParkingTicket writeParkingTicket(int meterNumber);
void patrolMeters();
int parkingTicketSimulator();

#endif