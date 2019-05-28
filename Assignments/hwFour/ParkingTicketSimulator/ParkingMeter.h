//
// Created by BRYAN on 3/8/2019.
//

#ifndef PARKINGTICKETSIMULATOR_PARKINGMETER_H
#define PARKINGTICKETSIMULATOR_PARKINGMETER_H


class ParkingMeter {

private:
    int parkedTime;

public:
    ParkingMeter(int = 0);

    void setParkedTime(int parkedTime);

    void addTime(int addedTime);

    int getParkedTime() const;

};


#endif //PARKINGTICKETSIMULATOR_PARKINGMETER_H
