/*
  Video.hpp

  Include file for Video class
*/

#ifndef VIDEO_H
#define VIDEO_H

#include <string>

class Video {
public:

    static const int REGULAR      = 0;
    static const int NEW_RELEASE  = 1;
    static const int CHILDRENS    = 2;

    // constructor
    Video(const std::string& title, int price_code);

    // movie title
    const std::string& getTitle() const;

    // movie price code
    int getPriceCode() const;

    // set movie price code
    void setPriceCode(int new_price_code);

private:
    std::string title;
    int price_code;
};

#endif
