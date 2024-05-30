#include <sstream>
#include <string>
#include "Date.h"

using namespace std;

Date::Date(unsigned int m, unsigned int d, unsigned int y)
        : month{m}, day{d}, year{y} {}

string Date::toString() const {
    ostringstream output;
    output << month << '/' << day << '/' << year;
    return output.str();
}