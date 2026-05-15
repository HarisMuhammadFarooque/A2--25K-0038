//Object-Oriented Programming Assignment 02 - Main File
#include <iostream>
#include <string>
#include "A2Header.h"
using namespace std;

int main(){

    cout << "\n========================================" << endl;
    cout << "     Welcome to PakWheels Marketplace   " << endl;
    cout << "========================================\n" << endl;

    Marketplace marketplace("PakWheels", "Pakistan", 2.5);
    marketplace.displayMarketplaceInfo();

    Engine engine1("E001", "Gasoline", "V6", 300, 3.5);
    Engine engine2("E002", "Gasoline", "V4", 200, 2.0);
    Engine engine3("E003", "Gasoline", "V8", 450, 5.5);

    engine1.isHighPerformance();
    engine1.calculateEfficiency();

    Car car1("C001", "Toyota", "Corrolla",   2018, 15000, 30000, engine1);
    Car car2("C002", "Honda",  "Civic",   2019, 18000, 20000, engine2);
    Car car3("C003", "Suzuki",   "Cultus", 2020, 25000, 10000, engine3);

    Car car4(car1);
    car4.updatePrice(13000);
    cout << "\n--- Copy of Car1 with new price ---" << endl;
    car4.getDetails();

    Listing listing1(1, 15000, "2024-01-10", "Good",     true, car1);
    Listing listing2(2, 18000, "2024-02-15", "Excellent", true, car2);
    Listing listing3(3, 25000, "2024-03-20", "Like New",  true, car3);

    listing1.incrementViews();
    listing1.incrementViews();

    Seller seller1("S001", "Ahmed Khan", "ahmed@email.com", 4.5, "0300-1234567", "Lahore");
    Seller seller2("S002", "Sara Malik", "sara@email.com", 3.2, "0311-9876543", "Karachi");

    seller1.addListing(listing1);
    seller1.addListing(listing2);
    seller2.addListing(listing3);

    seller1.displayDetails();
    seller1.hasPositiveRating();

    marketplace.registerUser();
    marketplace.registerUser();
    marketplace.addListing();
    marketplace.addListing();
    marketplace.addListing();

    Buyer buyer1("B001", "Ali Raza",   "ali@email.com",  "0333-1111111", "Islamabad");
    Buyer buyer2("B002", "Zara Ahmed", "zara@email.com", "0322-2222222", "Lahore");

    marketplace.registerUser();
    marketplace.registerUser();

    buyer1.saveListing(listing1);
    buyer1.saveListing(listing2);
    buyer2.saveListing(listing3);

    buyer1.displaySavedListings();
    buyer1.updateContactInfo("ali.new@email.com", "0333-9999999", "Rawalpindi");

    cout << "\n--- Sending Message ---" << endl;
    buyer1.sendMessageToSeller("Ahmed Khan", "Is the Toyota Corrolla still available?");

    Car cars[] = {car1, car2, car3};
    int size = 3;
    Search search;

    cout << "\n--- Search by Brand: Toyota ---" << endl;
    search.searchByBrand(cars, size, "Toyota");

    cout << "\n--- Search by Year: 2019 ---" << endl;
    search.searchByYear(cars, size, 2019);

    cout << "\n--- Search by Price under $20000 ---" << endl;
    search.searchByPrice(cars, size, 20000);

    cout << "\n--- Buyer searching for Honda ---" << endl;
    buyer2.searchCar(cars, size, "Honda");

    Review review1(1, "Ali Raza",   4.5, "Great seller!", "2024-04-01");
    Review review2(2, "Zara Ahmed", 2.0, "Not as described.", "2024-04-05");

    review1.displayReview();
    review1.isPositive();
    review2.isPositive();
    review1.updateReview(5.0, "Excellent seller, highly recommended!");
    review1.displayReview();

    Payment payment1(1, 15000, "2024-05-01", "Bank Transfer", false);
    Payment payment2(2, 18000, "2024-05-10", "Cash", false);

    cout << "\n--- Processing Payments ---" << endl;
    payment1.processPayment(15000);
    payment1.displayPaymentDetails();
    payment2.processPayment(18000);
    payment2.refundPayment();
    payment2.displayPaymentDetails();

    cout << "\n--- Removing Listing ---" << endl;
    seller1.removeListing(1);
    marketplace.removeListing();

    cout << "\n--- Final Marketplace Info ---" << endl;
    marketplace.displayMarketplaceInfo();
    cout << "Total Users (static): "   << Marketplace::getTotalUsers()    << endl;
    cout << "Total Listings (static): "<< Marketplace::getTotalListings() << endl;

    cout << "\n========================================" << endl;
    cout << "   POLYMORPHISM DEMONSTRATION (Vehicles)" << endl;
    cout << "========================================\n" << endl;
    
    Vehicle* vehicles[3];
    vehicles[0] = &car1;
    vehicles[1] = &car2;
    vehicles[2] = &car3;
    
    cout << "--- Calling getDetails() polymorphically on Vehicle pointers ---" << endl;
    for(int i = 0; i < 3; i++){
        vehicles[i]->getDetails();
    }

    // OPERATOR OVERLOADING
    cout << "\n========================================" << endl;
    cout << "   OPERATOR OVERLOADING DEMONSTRATION   " << endl;
    cout << "========================================\n" << endl;

    // Car Equality Operator
    cout << "\n--- Car Equality Operator (==) ---" << endl;
    Car testCar1("C004", "Toyota", "Corrolla", 2018, 15000, 30000, engine1);
    Car testCar2("C005", "Toyota", "Corrolla", 2018, 20000, 25000, engine1);
    
    if(car1 == testCar1){
        cout << "car1 and testCar1 are the SAME (same brand, model, year)" << endl;
    } else {
        cout << "car1 and testCar1 are DIFFERENT" << endl;
    }

    if(car1 == car2){
        cout << "car1 and car2 are the SAME" << endl;
    } else {
        cout << "car1 and car2 are DIFFERENT (different brand/model/year)" << endl;
    }

    // Car Price Comparison Function
    cout << "\n--- Car Price Comparison (comparePrices) ---" << endl;
    comparePrices(car1, car2);
    comparePrices(car2, car3);
    comparePrices(car1, car1);

    // Bike Creation and Operators
    cout << "\n--- Bike Equality Operator (==) ---" << endl;
    Bike bike1("B001", "Honda", "CB200", 2020, 8000, 5000, "Sport", 5, engine2);
    Bike bike2("B002", "Honda", "CB200", 2020, 9000, 4000, "Sport", 5, engine2);
    Bike bike3("B003", "Yamaha", "YZF-R3", 2021, 10000, 2000, "Sport", 6, engine3);
    
    if(bike1 == bike2){
        cout << "bike1 and bike2 are the SAME (same brand, model, year)" << endl;
    } else {
        cout << "bike1 and bike2 are DIFFERENT" << endl;
    }

    if(bike1 == bike3){
        cout << "bike1 and bike3 are the SAME" << endl;
    } else {
        cout << "bike1 and bike3 are DIFFERENT (different brand/model/year)" << endl;
    }

    // Bike Price Comparison Function
    cout << "\n--- Bike Price Comparison (comparePrices) ---" << endl;
    comparePrices(bike1, bike3);
    comparePrices(bike2, bike1);

    // Review Addition Operator
    cout << "\n--- Review Addition Operator (+) ---" << endl;
    Review review3(3, "John Doe", 3.5, "Average service", "2024-04-10");
    Review review4 = review1 + review2;
    cout << "Average of review1 (4.5) and review2 (2.0): ";
    review4.displayReview();

    cout << "\n========================================" << endl;
    cout << "   FRIEND FUNCTION DEMONSTRATION        " << endl;
    cout << "========================================\n" << endl;

    cout << "\n--- Transfer Listing Between Sellers ---" << endl;
    cout << "Before Transfer:" << endl;
    cout << "Seller1 Listings:" << endl;
    seller1.displayDetails();
    cout << "\nSeller2 Listings:" << endl;
    seller2.displayDetails();

    cout << "\nTransferring listing 0 from seller1 to seller2..." << endl;
    transferListing(seller1, seller2, 0);

    cout << "\nAfter Transfer:" << endl;
    cout << "Seller1 Listings:" << endl;
    seller1.displayDetails();
    cout << "\nSeller2 Listings:" << endl;
    seller2.displayDetails();

    cout << "\n========================================" << endl;
    cout << "   ADMIN & ABSTRACTION DEMONSTRATION    " << endl;
    cout << "========================================\n" << endl;

    Admin admin1("A001", "Super Admin", "admin@pakwheels.com", "0300-0000000", "Karachi", "SuperAdmin");

    admin1.displayDetails();

    admin1.banUser("B001");
    admin1.removelisting(3);

    admin1.addReview(4.0, "Great admin response!");
    admin1.addReview(5.0, "Very professional!");
    admin1.displayReviews();
    cout << "Admin Average Rating: " << admin1.getAverageRating() << endl;

    // Polymorphism via User pointer (abstract class demo)
    cout << "\n--- User Polymorphism (Abstract Class) ---" << endl;
    User* users[3] = {&seller1, &buyer1, &admin1};

    for(int i = 0; i < 3; i++){
    users[i]->displayDetails();
    }

    cout << "\n========================================" << endl;
    cout << "         Program Completed!              " << endl;
    cout << "========================================\n" << endl;

    return 0;
}