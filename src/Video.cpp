/*
  Video.cpp

  Definition file for Video class
*/

#include "Video.hpp"

// constructor
Video::Video(const std::string& title, int price_code)
    : title(title), price_code(price_code)
{ }

// movie title
const std::string& Video::getTitle() const {

    return title;
}

// movie price code
int Video::getPriceCode() const {

    return price_code;
}

// set movie price code
void Video::setPriceCode(int new_price_code) {

    price_code = new_price_code;
}
