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
