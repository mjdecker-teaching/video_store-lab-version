/*
  Video_t.cpp

  Test program for class Video
*/

#include <cassert>

#include "Video.hpp"

int main() {

  // regular movie
  {
    Video movie("A", Video::REGULAR);

    assert(movie.getTitle() == "A");
    assert(movie.getPriceCode() == Video::REGULAR);
  }

  // new release
  {
    Video movie("A", Video::NEW_RELEASE);

    assert(movie.getTitle() == "A");
    assert(movie.getPriceCode() == Video::NEW_RELEASE);
  }

  // childrens
  {
    Video movie("A", Video::CHILDRENS);

    assert(movie.getTitle() == "A");
    assert(movie.getPriceCode() == Video::CHILDRENS);
  }

  // longer title
  {
    Video movie("A B", Video::REGULAR);

    assert(movie.getTitle() == "A B");
    assert(movie.getPriceCode() == Video::REGULAR);
  }

  // change price
  {
    Video movie("A", Video::NEW_RELEASE);

    assert(movie.getTitle() == "A");
    assert(movie.getPriceCode() == Video::NEW_RELEASE);

    movie.setPriceCode(Video::REGULAR);
    assert(movie.getPriceCode() == Video::REGULAR);
  }

  return 0;
}
