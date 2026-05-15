#pragma once
#include <iostream>
#include <string>
using namespace std;

class IReviewable {
public:
    virtual void addReview(float rating, string comment) = 0;
    virtual void displayReviews() const = 0;
    virtual float getAverageRating() const = 0;

    virtual ~IReviewable() {}
};