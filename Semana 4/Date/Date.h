#include<string>
#include<iostream>

class Date {
public:
    explicit Date(int d, int m, int y) : day{d}, year{y} {
        setMonth(m);
        setYear(y);
        setDay(d);
    }
    
    void setDay(int d) {
        if (isValidDay(d, month, year)) {
            day = d;
        } else {
            day = 1;
        }
    }
    
    void setMonth(int m) {
        if (m >= 1 && m <= 12) {
            month = m;
        } else {
            month = 1;
        }
    }
    
    void setYear(int y) {
        if (y >= 1900 && y <= 2050) {
            year = y;
        } else {
            year = 1900;
        }
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
    
    bool isLeapYear() const {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return true;
        }
        return false;
    }
    
    bool isValidDay(int day, int month, int year) const {
        if (month < 1 || month > 12) {
            return false;
        }
        
        if (day < 1 || day > 31) {
            return false;
        }
        
        if (month == 2) {
            if (isLeapYear()) {
                return day <= 29;
            } else {
                return day <= 28;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return day <= 30;
        } else {
            return true;
        }
    }
private:
    int day;
    int year;
    int month{1};
    
 
};