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
    assert(movie.getCode() == Video::REGULAR);
  }

  // new release
  {
    Video movie("A", Video::NEW_RELEASE);

    assert(movie.getTitle() == "A");
    assert(movie.getCode() == Video::NEW_RELEASE);
  }

  // childrens
  {
    Video movie("A", Video::CHILDRENS);

    assert(movie.getTitle() == "A");
    assert(movie.getCode() == Video::CHILDRENS);
  }

  // longer title
  {
    Video movie("A B", Video::REGULAR);

    assert(movie.getTitle() == "A B");
    assert(movie.getCode() == Video::REGULAR);
  }

  // change price
  {
    Video movie("A", Video::NEW_RELEASE);

    assert(movie.getTitle() == "A");
    assert(movie.getCode() == Video::NEW_RELEASE);

    movie.setPriceCode(Video::REGULAR);
    assert(movie.getCode() == Video::REGULAR);
  }

  return 0;
}
