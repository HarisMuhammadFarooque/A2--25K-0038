# A2-25K-0038 — PakWheels Car Marketplace
### OOP Assignment 02 | FAST-NUCES Karachi | Section BAI-2C

---

## 📁 Repository Structure

```
A2-25K-0038/
│
├── Assignment02.h       # Main header — all classes
├── User.h               # Abstract base class: User
├── Vehicle.h            # Abstract base class: Vehicle
├── IReviewable.h        # Abstract interface: IReviewable
├── main.cpp             # Driver program
└── README.md            # This file
```

---

## 📌 System Overview

This project implements a **car and bike marketplace** (inspired by PakWheels) using advanced Object-Oriented Programming concepts in C++. The system models real-world entities like Buyers, Sellers, Admins, Vehicles (Cars & Bikes), Listings, Payments, Reviews, and Messages.

---

## 🖼️ Website Screenshots

> <img width="975" height="451" alt="image" src="https://github.com/user-attachments/assets/0ec07f55-b805-49bb-a504-7e6d2feb9506" />
<img width="363" height="829" alt="image" src="https://github.com/user-attachments/assets/394362d9-02fd-4bbf-86e6-8e065778ea4f" />
<img width="386" height="671" alt="image" src="https://github.com/user-attachments/assets/96e884ff-8247-470e-a7e8-2434ee46dd26" />




---

## 1️⃣ Inheritance

**Requirement:** At least 5–6 inheritance relationships.

This project implements **6 inheritance relationships:**

| #  | Base Class         | Derived Class | Type                    |
|----|--------------------|---------------|-------------------------|
| 1  | `User` (abstract)  | `Buyer`       | Public Inheritance      |
| 2  | `User` (abstract)  | `Seller`      | Public Inheritance      |
| 3  | `User` (abstract)  | `Admin`       | Public Inheritance      |
| 4  | `Vehicle` (abstract) | `Car`       | Public Inheritance      |
| 5  | `Vehicle` (abstract) | `Bike`      | Public Inheritance      |
| 6  | `IReviewable` (interface) | `Admin` | Interface Realization |

### Code Snippet — User → Buyer

```cpp
class User {
protected:
    const string userID;
    string name, email, phoneNumber, address;
public:
    virtual void displayDetails() = 0; // pure virtual
};

class Buyer : public User {
    Listing* savedlistings[10];
public:
    void displayDetails() override {
        cout << "Buyer ID: " << userID << endl;
        cout << "Name: " << name << endl;
    }
};
```

### Code Snippet — Vehicle → Car

```cpp
class Vehicle {
protected:
    string VehicleID, brand, model;
    int year;
    float price, mileage;
public:
    virtual void updateMileage(float) = 0;
    virtual void updatePrice(float)   = 0;
    virtual void getDetails() const   = 0;
};

class Car : public Vehicle {
    Engine engine;
public:
    void getDetails() const override {
        cout << "Brand: " << brand << " | Model: " << model << endl;
    }
};
```

**Justification:** Inheritance eliminates code duplication — `Buyer`, `Seller`, and `Admin` all share common user attributes (`userID`, `name`, `email`) from `User` without rewriting them. Similarly, `Car` and `Bike` inherit shared vehicle properties from `Vehicle`.

---

## 2️⃣ Polymorphism

**Requirement:** Function overloading and overriding using `virtual` functions.

### Runtime Polymorphism — Vehicle pointers

```cpp
Vehicle* vehicles[3];
vehicles[0] = &car1;
vehicles[1] = &car2;
vehicles[2] = &car3;

for (int i = 0; i < 3; i++) {
    vehicles[i]->getDetails(); // calls Car::getDetails() at runtime
}
```

### Runtime Polymorphism — User pointers

```cpp
User* users[3];
users[0] = &buyer1;
users[1] = &seller1;
users[2] = &admin1;

for (int i = 0; i < 3; i++) {
    users[i]->displayDetails(); // different output per type
}
```

### Function Overloading — Search class

```cpp
// Same function name, different parameter types
void searchByBrand(Car cars[], int size, string brand);
void searchByBrand(Bike bikes[], int size, string brand);
```

**Justification:** Polymorphism allows the marketplace to handle any vehicle type uniformly through base class pointers. Adding a new vehicle type (e.g., `Truck`) would require no changes to the display loop — only a new derived class.

---

## 3️⃣ Abstraction

**Requirement:** 3–4 abstract classes with pure virtual functions, separate `.h` files.

This project has **3 abstract classes:**

### Abstract Class 1 — `User` (User.h)

```cpp
class User {
protected:
    const string userID;
    string name, email, phoneNumber, address;
public:
    virtual void displayDetails() = 0; // pure virtual → User is abstract
};
```

### Abstract Class 2 — `Vehicle` (Vehicle.h)

```cpp
class Vehicle {
protected:
    string VehicleID, brand, model;
    int year;
    float price, mileage;
public:
    virtual void updateMileage(float newMileage) = 0; // pure virtual
    virtual void updatePrice(float newPrice)     = 0; // pure virtual
    virtual void getDetails() const              = 0; // pure virtual
};
```

### Abstract Class 3 — `IReviewable` (IReviewable.h)

```cpp
class IReviewable {
public:
    virtual void addReview(float rating, string comment) = 0;
    virtual void displayReviews() const                  = 0;
    virtual float getAverageRating() const               = 0;
    virtual ~IReviewable() {}
};
```

`Admin` implements `IReviewable` because admins in a marketplace can receive feedback ratings from users, while `Buyer` and `Seller` do not need this interface.

**Justification:** Abstract classes enforce a contract — any class deriving from `Vehicle` *must* implement `getDetails()`, `updateMileage()`, and `updatePrice()`. This hides implementation details and exposes only the essential interface to the rest of the system.

---

## 4️⃣ Operator Overloading

**Requirement:** Overload at least 3–4 operators with reasoning.

| Operator | Class    | Purpose |
|----------|----------|---------|
| `==`     | `Car`    | Compare two cars by brand, model, and year |
| `==`     | `Bike`   | Compare two bikes by brand, model, and year |
| `+`      | `Review` | Average the ratings of two reviews |

### Code Snippet — `==` for Car

```cpp
bool operator==(const Car &c1, const Car &c2) {
    return c1.brand == c2.brand &&
           c1.model == c2.model &&
           c1.year  == c2.year;
}

// Usage
if (car1 == testCar1) {
    cout << "Same car (brand/model/year match)" << endl;
}
```

**Reasoning:** Two cars are "equal" if they have the same brand, model, and year — regardless of price or mileage. This is useful when checking for duplicate listings.

### Code Snippet — `+` for Review

```cpp
Review operator+(const Review &other) {
    float avgRating = (rating + other.rating) / 2;
    Review temp;
    temp.rating = avgRating;
    return temp;
}

// Usage
Review combined = review1 + review2; // averages ratings
```

**Reasoning:** The `+` operator on two reviews produces a combined review with an averaged rating, which is useful for aggregating seller feedback.

---

## 5️⃣ Friend Functions

**Requirement:** At least 3–4 friend functions with justification.

| Friend Function | Declared In | Accesses Private Members Of |
|-----------------|-------------|------------------------------|
| `operator==(Car&, Car&)` | `Car` | `brand`, `model`, `year` |
| `operator==(Bike&, Bike&)` | `Bike` | `brand`, `model`, `year` |
| `comparePrices(Car&, Car&)` | `Car` | `price` |
| `comparePrices(Bike&, Bike&)` | `Bike` | `price` |
| `transferListing(Seller&, Seller&, int)` | `Seller` + `Listing` | `activeListings[]` |

### Code Snippet — `comparePrices`

```cpp
// Declared as friend inside Car class
friend void comparePrices(const Car &c1, const Car &c2);

// Definition
void comparePrices(const Car &c1, const Car &c2) {
    if (c1.price > c2.price)
        cout << c1.brand << " is more expensive" << endl;
    else if (c1.price < c2.price)
        cout << c2.brand << " is more expensive" << endl;
    else
        cout << "Both cars have the same price!" << endl;
}
```

**Justification:** `price` is a private member of `Vehicle`. A non-member function cannot access it directly. Making `comparePrices` a friend allows it to compare prices without adding a public getter, keeping the interface clean.

### Code Snippet — `transferListing`

```cpp
void transferListing(Seller &fromSeller, Seller &toSeller, int listingIndex) {
    // Accesses private activeListings[] of both Sellers
    if (fromSeller.activeListings[listingIndex] == nullptr) {
        cout << "No listing at this index!" << endl;
        return;
    }
    toSeller.addListing(*fromSeller.activeListings[listingIndex]);
    fromSeller.removeListing(listingIndex);
    cout << "Listing Transferred!" << endl;
}
```

**Justification:** `activeListings[]` is a private array inside `Seller`. Transfer logic requires reading *and* modifying both sellers' private arrays simultaneously. A friend function is the cleanest solution — it avoids exposing the array publicly while still enabling cross-object operations.

---

## ⚙️ Composition & Association

| Relationship | Type | Description |
|---|---|---|
| `Car` → `Engine` | Composition | Car owns its Engine; Engine is destroyed with Car |
| `Bike` → `Engine` | Composition | Same as above |
| `Listing` → `Car` / `Bike` | Composition | Listing stores the vehicle being listed |
| `Buyer` → `Listing*` | Association | Buyer holds pointers to saved listings |
| `Seller` → `Listing*` | Association | Seller holds pointers to active listings |

---

## 👨‍💻 Author

**Haris Muhammad Farooque**  
Roll No: 25K-0038 | Section BAI-2C  
