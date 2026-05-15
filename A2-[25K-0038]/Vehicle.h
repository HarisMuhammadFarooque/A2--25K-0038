#pragma once
#include <string>
#include <iostream>
using namespace std;

class Vehicle{
protected:
    string VehicleID;
    string brand;
    string model;
    float mileage;
    int year;
    float price;

public:
    Vehicle() : VehicleID(""), brand(""), model(""), year(0), price(0.0), mileage(0.0) {}

    Vehicle(string id, string b, string m, int y, float p, float mi) :
    VehicleID(id), brand(b), model(m), year(y), price(p), mileage(mi){}

    virtual void updatePrice(float newPrice) = 0;
    virtual void getDetails() const = 0;
    virtual void updateMileage(float newMileage) = 0;
        
};