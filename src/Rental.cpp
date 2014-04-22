/*
  Rental.cpp

  Definition file for Rental class.
*/

#include "Rental.hpp"

// constructor
Rental::Rental(const Video& movie, int days_rented)
    : movie(movie), days(days_rented)
{ }

// days rented
int Rental::getDaysRented() const {

    return days;
}

// movie rented
const Video& Rental::getVideo() const {

    return movie;
}

double Rental::getCharge() const {

    double thisAmount = 0;
    switch(getVideo().getPriceCode()) {

    case Video::REGULAR:
        thisAmount += 2;
        if (getDaysRented() > 2)
            thisAmount += (getDaysRented() - 2) * 1.5;
        break;

    case Video::NEW_RELEASE:
        thisAmount += getDaysRented() * 3;
        break;

    case Video::CHILDRENS:
        thisAmount += 1.5;
        if (getDaysRented() > 3)
            thisAmount += (getDaysRented() - 3) * 1.5;
        break;
    }

    return thisAmount;
}

