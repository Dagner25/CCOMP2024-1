#include <iostream>

class Date {
    public:
        explicit Date(int d, int m, int y) 
                : day{d}, year{y} {
            if(m >= 1 && m <= 12) {
                month = m;
            }
        }

        void setDay(int d) {
            day = d;
        }
        void setMonth(int m) {
            if(m >= 1 && m <= 12) {
                month = m;
            }
        }
        void setYear(int y) {
            year = y;
        }
        int getDay() const {
            return day;
        }
        int getMonth() const {
            return month;
        }
        int getYear() const {
            return year;
        }

        void displayDate() const {
            std::cout << day << " / " << month << " / " << year << std::endl;
        }

    private:
        int day;
        int year;
        int month{1};
};