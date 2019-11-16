/*
  Rental.cpp

  Definition file for Rental class.
*/

#include "Rental.hpp"

// constructor
Rental::Rental(const Movie& movie, int days_rented)
    : movie(movie), days(days_rented)
{ }

// days rented
int Rental::getDaysRented() const {

    return days;
}

// movie rented
const Movie& Rental::getMovie() const {

    return movie;
}

// calculate the amount for a rental
double Rental::getCharge() const {

    double thisAmount = 0;

    //determine amounts for each line
    switch (getMovie().getPriceCode()) {
    case Movie::REGULAR:
	thisAmount += 2;
	if (getDaysRented() > 2)
	    thisAmount += (getDaysRented() - 2) * 1.5;
	break;
    case Movie::NEW_RELEASE:
	thisAmount += getDaysRented() * 3;
	break;
    case Movie::CHILDRENS:
	thisAmount += 1.5;
	if (getDaysRented() > 3)
	    thisAmount += (getDaysRented() - 3) * 1.5;
	break;

    }

    return thisAmount;
}

int Rental::getFrequentRenterPoints() const {

    // add frequent renter points
    int frequentRenterPoints = 1;
    // add bonus for a two day new release rental
    if ((getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
	getDaysRented() > 1) frequentRenterPoints ++;

    return frequentRenterPoints;

}
