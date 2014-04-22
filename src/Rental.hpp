/*
  Rental.hpp

  Include file for Rental class
*/

#ifndef RENTAL_H
#define RENTAL_H

#include "Video.hpp"

class Rental {
public:

    // constructor
    Rental(const Video& movie, int days_rented);

    // days rented
    int getDaysRented() const;

    // movie rented
    const Video& getVideo() const;

    // charge for the movie
    double getCharge() const;

private:
    Video movie;
    int days;
};

#endif
