#pragma once
#include <iostream>
#include <User.h>
#include <Vehicle.h>  
#include <IReviewable.h>
#include <string>
using namespace std;

class Message{
    const int messageID;
    string senderName;
    string recieverName;
    string content;
    string time;
    bool isRead;

public:    

    Message() : messageID(0), senderName(""), recieverName(""), content(""), time(""), isRead(false) {}

    Message(int id, string sn, string rn, string c, string t, bool i) : messageID(id), senderName(sn), 
    recieverName(rn), content(c), time(t), isRead(i){}

    void sendMessage(string message){
        if(message.empty()){
            cout << "Message is Empty!" << endl;
            return;
        }
        isRead = false;
        content = message;
        cout << "Message Sent!" << endl;
    }

    void marksAsRead(){
        if(content.empty()){
            cout << "Message is Empty!" << endl;
            return;
        }
        isRead = true;
        cout << "Marked As read!" << endl;
    }

    void displayMessage() const{
        if(content.empty()){
            cout << "Message is Empty!" << endl;
            return;
        }
        cout <<"-------------------------------------" << endl;
        cout <<"---------- Message Details ----------" << endl;
        cout << "Message ID: " << messageID << endl;
        cout << "Sender Name: " << senderName << endl;
        cout << "Reciver Name: " << recieverName<< endl;
        cout << "Time Stamp: " << time << endl;
        cout << "Message: " << content << endl;
    }

    void deleteMessage(){
        senderName = "";
        recieverName = "";
        content = "";
        time = "";
        isRead = false;
        cout << "Message Deleted!" << endl;
    }
};

class Engine{
    string engineID;
    string fuelType;
    string type;
    int horsepower;
    float displacement;

public:
    Engine() : engineID(""), fuelType(""), type(""), horsepower(0), displacement(0.0) {}

    Engine(string id, string ft, string t, int hp, float d) : engineID(id), fuelType(ft), type(t), horsepower(hp), displacement(d){} 
    
    void isHighPerformance(){
        if(horsepower > 300){
            cout << "This is a high performance engine!" << endl;
        } else {
            cout << "This is not a high performance engine!" << endl;
        }
    }

    void calculateEfficiency(){
        float efficiency = horsepower / displacement;
        cout << "Engine Efficiency: " << efficiency << " HP/L" << endl;
    }

    void updateEngineDetails(int hp, float d){
        horsepower = hp;
        displacement = d;
        cout << "Engine Details Updated!" << endl;
    }

    void getDetails() const{
        cout <<"-------------------------------------" << endl;
        cout <<"---------- Engine Details ----------" << endl;
        cout << "Engine ID: " << engineID << endl;
        cout << "Engine Type: " << type << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Horsepower: " << horsepower << endl;
        cout << "Displacement: " << displacement << endl;
    }
};

class Car : public Vehicle{
    Engine engine;

public:    

    Car() : Vehicle(), engine() {}

    friend bool operator==(const Car &c1, const Car &c2);
    friend void comparePrices(const Car &c1, const Car &c2);

    Car(string id, string b, string m, int y, float p, float mi, Engine e) :
    Vehicle(id, b, m, y, p, mi), engine(e){}

    Car(const Car &other) : Vehicle(other), engine(other.engine) {}

    void updateMileage(float newMileage) override{
        if(newMileage < 0){
            cout << "Mileage cannot be negative!" << endl;
            return;
        }
        mileage = newMileage;
        cout << "Mileage Updated!" << endl;
    }

    void updatePrice(float newPrice) override{
        if(newPrice < 0){
            cout << "Price cannot be negative!" << endl;
            return;
        }
        price = newPrice;
        cout << "Price Updated!" << endl;
    }

    bool isAvailable(){
        return price > 0;
    }

    string getBrand() const { return brand; }
    string getModel() const { return model; }
    float getPrice() const { return price; }
    float getMileage() const { return mileage; }
    int getYear() const { return year; }
    
    void getDetails() const override{
        cout <<"-------------------------------------" << endl;
        cout <<"---------- Car Details ----------" << endl;
        cout << "Car ID: " << VehicleID << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model<< endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
        cout << "Mileage: " << mileage << endl;
        engine.getDetails();
    }
};

class Bike : public Vehicle{
    string type;
    int gearCount;
    Engine engine;

public:
    Bike() : Vehicle(), type(""), gearCount(0), engine() {}

    friend bool operator==(const Bike &b1, const Bike &b2);
    friend void comparePrices(const Bike &b1, const Bike &b2);

    Bike(string id, string b, string m, int y, float p, float mi, string t, int gc, Engine e) :
    Vehicle(id, b, m, y, p, mi), type(t), gearCount(gc), engine(e){}

    Bike(const Bike &other) : Vehicle(other), type(other.type), gearCount(other.gearCount), engine(other.engine) {}

    void updateMileage(float newMileage) override{
        if(newMileage < 0){
            cout << "Mileage cannot be negative!" << endl;
            return;
        }
        mileage = newMileage;
        cout << "Mileage Updated!" << endl;
    }

    void updatePrice(float newPrice) override{
        if(newPrice < 0){
            cout << "Price cannot be negative!" << endl;
            return;
        }
        price = newPrice;
        cout << "Price Updated!" << endl;
    }

    bool isAvailable(){
        return price > 0;
    }

    string getBrand() const { return brand; }
    string getModel() const { return model; }
    float getPrice() const { return price; }
    float getMileage() const { return mileage; }
    int getYear() const { return year; }
    string getType() const { return type; }
    int getGearCount() const { return gearCount; }

    void getDetails() const override{
        cout <<"-------------------------------------" << endl;
        cout <<"---------- Bike Details ----------" << endl;
        cout << "Bike ID: " << VehicleID << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model<< endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
        cout << "Mileage: " << mileage << endl;
        cout << "Type: " << type << endl;
        cout << "Gear Count: " << gearCount << endl;
        engine.getDetails();
    }
};

class Seller;

// -------------------------------------------------------
// Listing now supports both Car and Bike via vehicleType
// -------------------------------------------------------
enum VehicleType { VEHICLE_CAR, VEHICLE_BIKE };

class Listing{
    int listingID;
    int views;
    float price;
    string datePosted;
    string condition;
    bool isActive;
    VehicleType vehicleType;  // tracks which vehicle is stored
    Car car;
    Bike bike;

public:
    // Default constructor — defaults to CAR type
    Listing() : listingID(0), views(0), price(0.0), datePosted(""), condition(""), 
                 isActive(false), vehicleType(VEHICLE_CAR), car(), bike() {}

    // Constructor for Car listing
    Listing(int id, float p, string dp, string c, bool ia, Car car) : 
    listingID(id), views(0), price(p), datePosted(dp), condition(c), 
    isActive(ia), vehicleType(VEHICLE_CAR), car(car), bike() {}

    // Constructor for Bike listing
    Listing(int id, float p, string dp, string c, bool ia, Bike bike) : 
    listingID(id), views(0), price(p), datePosted(dp), condition(c), 
    isActive(ia), vehicleType(VEHICLE_BIKE), car(), bike(bike) {}

    void getListingDetails() const{
        cout <<"-------------------------------------" << endl;
        cout <<"---------- Listing Details ----------" << endl;
        cout << "Listing ID: " << listingID << endl;
        cout << "Price: " << price << endl;
        cout << "Date Posted: " << datePosted << endl;
        cout << "Condition: " << condition << endl;
        cout << "Active: " << (isActive ? "Yes" : "No") << endl;
        cout << "Vehicle Type: " << (vehicleType == VEHICLE_CAR ? "Car" : "Bike") << endl;
        if(vehicleType == VEHICLE_CAR)
            car.getDetails();
        else
            bike.getDetails();
    }

    void activateListing(){
        isActive = true;
        cout << "Listing Activated!" << endl;
    }

    void deactivateListing(){
        isActive = false;
        cout << "Listing Deactivated!" << endl;
    }

    void incrementViews(){
        views++;
        cout << "Listing Viewed!" << endl;
    }

    int getListingID() const { return listingID; }
    VehicleType getVehicleType() const { return vehicleType; }

    friend void transferListing(Seller &fromSeller, Seller &toSeller, int listingIndex);
};

class Search{
    string filterBrand;
    string filterModel;
    string filterYear;
    float mileage, price;

public:    

    Search() : filterBrand(""), filterModel(""), filterYear(""), mileage(0), price(0) {}

    void setDetails(string fb, string fm, string fy, float m, float p){
        filterBrand = fb;
        filterModel = fm;
        filterYear = fy;
        mileage = m;
        price = p;
    }

    // --- Car search methods ---

    void searchByBrand(Car cars[], int size, string brand){
        bool found = false;
        for (int i = 0; i < size; i++){
            if(cars[i].getBrand() == brand){
                cars[i].getDetails();
                found = true;
            }
        }
        if(!found){ cout << "No car with this brand!" << endl; }
    }

    void searchByModel(Car cars[], int size, string model){
        bool found = false;
        for (int i = 0; i < size; i++){
            if(cars[i].getModel() == model){
                cars[i].getDetails();
                found = true;
            }
        }
        if(!found){ cout << "No car with this model!" << endl; }
    }

    void searchByPrice(Car cars[], int size, float price){
        bool found = false;
        for (int i = 0; i < size; i++){
            if(cars[i].getPrice() == price){
                cars[i].getDetails();
                found = true;
            }
        }
        if(!found){ cout << "No car with this price!" << endl; }
    }

    void searchByMileage(Car cars[], int size, float mileage){
        bool found = false;
        for (int i = 0; i < size; i++){
            if(cars[i].getMileage() == mileage){
                cars[i].getDetails();
                found = true;
            }
        }
        if(!found){ cout << "No car with this mileage!" << endl; }
    }

    void searchByYear(Car cars[], int size, int year){
        bool found = false;
        for (int i = 0; i < size; i++){
            if(cars[i].getYear() == year){
                cars[i].getDetails();
                found = true;
            }
        }
        if(!found){ cout << "No car with this year!" << endl; }
    }

    // --- Bike search methods ---

    void searchByBrand(Bike bikes[], int size, string brand){
        bool found = false;
        for (int i = 0; i < size; i++){
            if(bikes[i].getBrand() == brand){
                bikes[i].getDetails();
                found = true;
            }
        }
        if(!found){ cout << "No bike with this brand!" << endl; }
    }

    void searchByModel(Bike bikes[], int size, string model){
        bool found = false;
        for (int i = 0; i < size; i++){
            if(bikes[i].getModel() == model){
                bikes[i].getDetails();
                found = true;
            }
        }
        if(!found){ cout << "No bike with this model!" << endl; }
    }

    void searchByPrice(Bike bikes[], int size, float price){
        bool found = false;
        for (int i = 0; i < size; i++){
            if(bikes[i].getPrice() == price){
                bikes[i].getDetails();
                found = true;
            }
        }
        if(!found){ cout << "No bike with this price!" << endl; }
    }

    void searchByMileage(Bike bikes[], int size, float mileage){
        bool found = false;
        for (int i = 0; i < size; i++){
            if(bikes[i].getMileage() == mileage){
                bikes[i].getDetails();
                found = true;
            }
        }
        if(!found){ cout << "No bike with this mileage!" << endl; }
    }

    void searchByYear(Bike bikes[], int size, int year){
        bool found = false;
        for (int i = 0; i < size; i++){
            if(bikes[i].getYear() == year){
                bikes[i].getDetails();
                found = true;
            }
        }
        if(!found){ cout << "No bike with this year!" << endl; }
    }

    void searchByType(Bike bikes[], int size, string type){
        bool found = false;
        for (int i = 0; i < size; i++){
            if(bikes[i].getType() == type){
                bikes[i].getDetails();
                found = true;
            }
        }
        if(!found){ cout << "No bike with this type!" << endl; }
    }
};

class Admin : public User, public IReviewable {
    string adminLevel;
    float reviews[10];
    string comments[10];
    int reviewCount;

public:
    Admin() : User(), adminLevel(""), reviewCount(0) {}

    Admin(string id, string n, string e, string p, string a, string lvl)
        : User(id, n, e, p, a), adminLevel(lvl), reviewCount(0) {}

    void banUser(string userID) {
        cout << "User " << userID << " has been banned!" << endl;
    }

    void removelisting(int listingID) {
        cout << "Listing " << listingID << " has been removed!" << endl;
    }

    void addReview(float rating, string comment) override {
        if (reviewCount < 10) {
            reviews[reviewCount] = rating;
            comments[reviewCount] = comment;
            reviewCount++;
            cout << "Review Added!" << endl;
        } else {
            cout << "Review limit reached!" << endl;
        }
    }

    void displayReviews() const override {
        for (int i = 0; i < reviewCount; i++) {
            cout << "Rating: " << reviews[i] << " | Comment: " << comments[i] << endl;
        }
    }

    float getAverageRating() const override {
        if (reviewCount == 0) return 0.0;
        float sum = 0;
        for (int i = 0; i < reviewCount; i++) sum += reviews[i];
        return sum / reviewCount;
    }

    void displayDetails() override {
        cout << "Admin ID: " << userID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << adminLevel << endl;
    }
};

class Buyer : public User{
    Listing* savedlistings[10];

public:   
    Buyer() : User(){
        for(int i = 0; i < 10; i++) savedlistings[i] = nullptr;
    }

    Buyer(string id, string n, string e, string p, string a) : User(id, n, e, p, a){
        for(int i = 0; i < 10; i++) savedlistings[i] = nullptr;
    }

    void updateContactInfo(string newEmail, string newPhoneNumber, string newAddress){
        email = newEmail;
        phoneNumber = newPhoneNumber;
        address = newAddress;
        cout << "Contact Information Updated!" << endl;
    }

    void saveListing(Listing listing){
        for (int i = 0; i < 10; i++){
            if(savedlistings[i] == nullptr){
                savedlistings[i] = new Listing(listing);
                cout << "Listing Saved!" << endl;
                return;
            }
        }
        cout << "Saved Listings Full!" << endl;
    }

    void displaySavedListings(){
        cout <<"-------------------------------------" << endl;
        cout <<"---------- Saved Listings ----------" << endl;
        bool any = false;
        for (int i = 0; i < 10; i++){
            if(savedlistings[i] != nullptr && savedlistings[i]->getListingID() != 0){
                savedlistings[i]->getListingDetails();
                any = true;
            }
        }
        if(!any) cout << "No saved listings!" << endl;
    }

    void sendMessageToSeller(string sellerName, string messageContent){
        Message message(1, name, sellerName, messageContent, "2024-06-01 12:00", false);
        message.sendMessage(messageContent);
    }

    // Search cars by brand
    void searchCar(Car cars[], int size, string brand){
        Search search;
        search.searchByBrand(cars, size, brand);
    }

    // Search bikes by brand
    void searchBike(Bike bikes[], int size, string brand){
        Search search;
        search.searchByBrand(bikes, size, brand);
    }

    void displayDetails() override{
        cout <<"-------------------------------------" << endl;
        cout <<"---------- Buyer Profile ----------" << endl;
        cout << "Buyer ID: " << userID << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Address: " << address << endl;
    }

    ~Buyer(){
        for(int i = 0; i < 10; i++){
            if(savedlistings[i] != nullptr){
                delete savedlistings[i];
            }
        }
    }
};

class Seller : public User{
    float rating;
    Listing* activeListings[10];

public:
    Seller() : rating(0), User() {
        for(int i = 0; i < 10; i++) activeListings[i] = nullptr;
    }

    friend void transferListing(Seller &fromSeller, Seller &toSeller, int listingIndex);

    Seller(string id, string n, string e, float r, string p, string a) :
     rating(r), User(id, n, e, p, a){
        for(int i = 0; i < 10; i++) activeListings[i] = nullptr;
    }

    void hasPositiveRating(){
        if(rating > 3){
            cout << "This seller has a positive rating!" << endl;
        } else {
            cout << "This seller does not have a positive rating(below 3.0)!" << endl;
        }
    }

    void addListing(Listing listing){
        for (int i = 0; i < 10; i++){
            if(activeListings[i] == nullptr){
                activeListings[i] = new Listing(listing);
                cout << "Listing Added!" << endl;
                return;
            }
        }
        cout << "Active Listings Full!" << endl;
    }

    void removeListing(int count){
        activeListings[count] = nullptr;
    }

    void displayDetails() override{
        cout <<"-------------------------------------" << endl;
        cout <<"---------- Seller Profile ----------" << endl;
        cout << "Seller ID: " << userID << endl;
        cout << "Name: " << name << endl;
        cout << "Rating: " << rating << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Address: " << address << endl;
        cout <<"-------------------------------------" << endl;
        cout <<"---------- Active Listings ----------" << endl;
        bool any = false;
        for (int i = 0; i < 10; i++){
            if(activeListings[i] != nullptr && activeListings[i]->getListingID() != 0){
                activeListings[i]->getListingDetails();
                any = true;
            }
        }
        if(!any) cout << "No active listings!" << endl;
    }

    ~Seller(){
        for(int i = 0; i < 10; i++){
            if(activeListings[i] != nullptr){
                delete activeListings[i];
            }
        }
    }
};

class Review{
    const int reviewID;
    string reviewerName;
    float rating;
    string comment;
    string date;

public:
    Review() : reviewID(0), reviewerName(""), rating(0.0), comment(""), date(""){}

    Review(int id, string rn, float r, string c, string d) :
    reviewID(id), reviewerName(rn), rating(r), comment(c), date(d){}

    void displayReview() const{
        cout <<"-------------------------------------" << endl;
        cout <<"---------- Review Details ----------" << endl;
        cout << "Review ID: " << reviewID << endl;
        cout << "Reviewer Name: " << reviewerName << endl;
        cout << "Rating: " << rating << endl;
        cout << "Comment: " << comment << endl;
        cout << "Date: " << date << endl;
    }

    void updateReview(float newRating, string newComment){
        rating = newRating;
        comment = newComment;
        cout << "Review Updated!" << endl;
    }

    void isPositive(){
        if(rating > 3){
            cout << "This is a positive review!" << endl;
        } else {
            cout << "This is not a positive review!" << endl;
        }
    }

    Review operator+(const Review &other){
        float avgRating = (rating + other.rating) / 2;
        Review temp;
        temp.rating = avgRating;
        return temp;
    }
};

class Payment{
    const int paymentID;
    float amount;
    string date;
    string method;
    bool isSuccessful;
    bool isRefunded;

public:
    Payment() : paymentID(0), amount(0.0), date(""), method(""), isSuccessful(false), isRefunded(false) {}

    Payment(int id, float a, string d, string m, bool s) :
    paymentID(id), amount(a), date(d), method(m), isSuccessful(s), isRefunded(false){}

    void processPayment(float amount){
        if(amount <= 0){
            cout << "Invalid Payment Amount!" << endl;
            return;
        }
        isSuccessful = true;
        this->amount = amount;
        cout << "Payment Processed!" << endl;
    }

    void displayPaymentDetails() const{
        cout <<"-------------------------------------" << endl;
        cout <<"---------- Payment Details ----------" << endl;
        cout << "Payment ID: " << paymentID << endl;
        cout << "Amount: " << amount << endl;
        cout << "Date: " << date << endl;
        cout << "Method: " << method << endl;
        cout << "Successful: " << (isSuccessful ? "Yes" : "No") << endl;
    }

    void refundPayment(){
        if(!isSuccessful){
            cout << "Payment not successful, cannot refund!" << endl;
            return;
        }
        isRefunded = true;
        amount = 0.0;
        cout << "Payment Refunded!" << endl;
    }
};

class Marketplace{
    const string name;
    static int totalUsers;
    static int totalListings;
    string location;
    float commissionRate;

public:
    Marketplace() : name(""), location(""), commissionRate(0.0) {}  

    Marketplace(string n, string l, float cr) : name(n), location(l), commissionRate(cr) {}

    void displayMarketplaceInfo() const{
        cout <<"-------------------------------------" << endl;
        cout <<"---------- Marketplace Info ----------" << endl;
        cout << "Name: " << name << endl;
        cout << "Location: " << location << endl;
        cout << "Commission Rate: " << commissionRate << "%" << endl;
        cout << "Total Users: " << totalUsers << endl;
        cout << "Total Listings: " << totalListings << endl;
    }

    void registerUser(){
        totalUsers++;
        cout << "User Registered! Total Users: " << totalUsers << endl;
    }

    static int getTotalUsers(){
        return totalUsers;
    }

    static int getTotalListings(){
        return totalListings;
    }

    void addListing(){
        Marketplace::totalListings++;
        cout << "Listing Added! Total Listings: " << totalListings << endl;
    }

    void removeListing(){
        if(totalListings > 0){
            totalListings--;
            cout << "Listing Removed! Total Listings: " << totalListings << endl;
        } else {
            cout << "No listings to remove!" << endl;
        }
    }
};

int Marketplace::totalUsers = 0;
int Marketplace::totalListings = 0;

bool operator==(const Car &c1, const Car &c2){
    return c1.brand == c2.brand && c1.model == c2.model && c1.year == c2.year;
}

bool operator==(const Bike &b1, const Bike &b2){
    return b1.brand == b2.brand && b1.model == b2.model && b1.year == b2.year;
}

void comparePrices(const Car &c1, const Car &c2){
    if(c1.price > c2.price)
        cout << c1.getBrand() << " " << c1.getModel() << " is more expensive than " << c2.getBrand() << " " << c2.getModel() << endl;
    else if(c1.price < c2.price)
        cout << c2.getBrand() << " " << c2.getModel() << " is more expensive than " << c1.getBrand() << " " << c1.getModel() << endl;
    else
        cout << "Both cars have the same price!" << endl;
}

void comparePrices(const Bike &b1, const Bike &b2){ // function overloading and operator overloading   
    if(b1.price > b2.price)
        cout << b1.getBrand() << " " << b1.getModel() << " is more expensive than " << b2.getBrand() << " " << b2.getModel() << endl;
    else if(b1.price < b2.price)
        cout << b2.getBrand() << " " << b2.getModel() << " is more expensive than " << b1.getBrand() << " " << b1.getModel() << endl;
    else
        cout << "Both bikes have the same price!" << endl;
}

void transferListing(Seller &fromSeller, Seller &toSeller, int listingIndex){
    if(listingIndex < 0 || listingIndex >= 10){
        cout << "Invalid listing index!" << endl;
        return;
    }
    if(fromSeller.activeListings[listingIndex] == nullptr){
        cout << "No listing at this index to transfer!" << endl;
        return;
    }
    toSeller.addListing(*fromSeller.activeListings[listingIndex]);
    fromSeller.removeListing(listingIndex);
    cout << "Listing Transferred!" << endl;
}