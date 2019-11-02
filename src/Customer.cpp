/*
  Customer.cpp

  Definition file for Customer class
*/

#include "Customer.hpp"
#include "Movie.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// constructor
Customer::Customer(const std::string& name)
    : name(name)
{ }

// add a rental to this customer
void Customer::addRental(const Rental& rental) {

    rentals.push_back(rental);
}

// customer name
std::string Customer::getName() const {

    return name;
}

// calculate the amount for a rental
double Customer::amountFor(const Rental & aRental) const {

    double thisAmount = 0;

    //determine amounts for each line
    switch (aRental.getMovie().getPriceCode()) {
    case Movie::REGULAR:
	thisAmount += 2;
	if (aRental.getDaysRented() > 2)
	    thisAmount += (aRental.getDaysRented() - 2) * 1.5;
	break;
    case Movie::NEW_RELEASE:
	thisAmount += aRental.getDaysRented() * 3;
	break;
    case Movie::CHILDRENS:
	thisAmount += 1.5;
	if (aRental.getDaysRented() > 3)
	    thisAmount += (aRental.getDaysRented() - 3) * 1.5;
	break;

    }

    return thisAmount;
}

// customer rental statement
std::string Customer::statement() const {

    double totalAmount = 0;
    int frequentRenterPoints = 0;
    std::string result = "Rental Record for " + getName() + "\n";
    for(std::vector<Rental>::const_iterator it = rentals.begin(); it != rentals.end(); ++it) {

        Rental each = (Rental) *it;
	double thisAmount = amountFor(each);

        // add frequent renter points
        ++frequentRenterPoints;
        // add bonus for a two day new release rental
        if ((each.getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
            each.getDaysRented() > 1) frequentRenterPoints ++;

        //show figures for this rental
        result += "\t" + each.getMovie().getTitle()+ "\t";
        std::ostringstream amount_stream;
        amount_stream << thisAmount;
        result +=  amount_stream.str();
        result += "\n";
        totalAmount += thisAmount;

    }

    //add footer lines
    // total amount owed
    result += "Amount owed is: ";
    std::ostringstream owed_stream;
    owed_stream << totalAmount;
    result += owed_stream.str();
    result += "\n";

    // frequent renter points earned
    result += "You earned: ";
    std::ostringstream frequent_stream;
    frequent_stream << frequentRenterPoints;
    result += frequent_stream.str();
    result += " frequent renter points\n";

    return result;
}
