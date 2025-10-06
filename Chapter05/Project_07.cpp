#include <iostream>
#include <string>
#include <limits>
#include <array>
#include <cassert>

struct Date {
    int year = 0;
    int month = 0;
    int day = 0;
};

static int read_int_in_range(const std::string& name, int a, int b) {
    assert(a <= b);
    int value = 0;

    while (true) {
        std::cout << "Input the value of " << name
                  << " in [" << a << ", " << b << "]: ";

        if (std::cin >> value && value >= a && value <= b) {
            return value;
        }
        std::cerr << "Invalid input for " << name
                  << ". Please input an integer in ["
                  << a << ", " << b << "].\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

static bool is_leap_year(int year) {
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

static int max_day(int y, int m) {
    if (m == 2) return is_leap_year(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

static Date read_date(const std::string& name) {
    Date the_date;
    the_date.year = read_int_in_range(name + " (year)", 0, 9999);
    the_date.month = read_int_in_range(name + " (month)", 1, 12);
    the_date.day = read_int_in_range(name + " (day)", 1,
                                            max_day(the_date.year, the_date.month));
    return the_date;
}

static int get_century_value(int year) {
    int century = year / 100;
    int remainder = century % 4;
    return (3 - remainder) * 2;
}

static int get_year_value(int year) {
    year %= 100;
    return (year + (year / 4));
}

static int get_month_value(int month, int year) {
    if (month == 1) return is_leap_year(year) ? 6 : 0;
    if (month == 2) return is_leap_year(year) ? 2 : 3;
    
    static const std::array<int, 10> mv = {3,6,1,4,6,2,5,0,3,5};
    return mv[month-3];
}

// 0=Sunday, 1=Monday, ....
static int calculate_day_of_week(const Date& d) {
    return (get_century_value(d.year) + get_year_value(d.year) +
            get_month_value(d.month, d.year) + d.day) % 7;
}

static void show_output(int day_of_week) {
    static const std::array<std::string, 7> names = {"Sunday","Monday", 
                    "Tuesday","Wednesday","Thursday","Friday","Saturday"};
    
    std::cout << names[day_of_week] << '\n';
}

int main() {
	Date the_date = read_date("any date");
	show_output(calculate_day_of_week(the_date));
	return 0;
}
