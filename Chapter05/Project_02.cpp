#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <iomanip>

struct Time24 {
    int day = 0;
    int hour = 0;
    int minute = 0;
};

struct TimePeriod {
    int hour = 0;
    int minute = 0;
};

static int read_int_between_a_and_b(const std::string& name, int a, int b) {
    int value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if (std::cin >> value && value >= a && value <= b) {
            return value;
        }
        std::cerr << "Invalid input for " << name
                  << ". Please input an integer between "
                  << a << " and " << b << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

static Time24 read_time_24(const std::string& name) {
    Time24 the_time;
    the_time.hour = read_int_between_a_and_b(name + " hour", 0, 23);
    the_time.minute = read_int_between_a_and_b(name + " minute", 0, 59);

    return the_time;
}

static TimePeriod read_time_period(const std::string& name) {
    TimePeriod the_time;
    constexpr int max_hour = 1000000;
    the_time.hour = read_int_between_a_and_b(name + " hour", 0, max_hour-1);
    the_time.minute = read_int_between_a_and_b(name + " minute", 0, 59);

    return the_time;
}

static Time24 time_addition(const Time24& current_time, const TimePeriod& time_period) {
    Time24 new_time;

    long long total_minutes = current_time.hour * 60 + current_time.minute
                      + time_period.hour * 60 + time_period.minute;

    new_time.day = total_minutes / (24 * 60);
    new_time.hour = (total_minutes % (24 * 60)) / 60;
    new_time.minute = total_minutes % 60;

    return new_time;
}

static void show_output(const Time24& new_time) {
    std::cout << "The new time is " // Format HH:MM
              << std::setw(2) << std::setfill('0') << new_time.hour
              << ':'
              << std::setw(2) << std::setfill('0') << new_time.minute;

    if (new_time.day) {
        std::cout << " after " << new_time.day << (new_time.day == 1 ? " day" : " days") << ".\n";
    } else {
        std::cout << " on the same day.\n";
    }
}

static bool read_yes_no() {
    while (true) {
        std::cout << "Play again? (y/n): ";
        char c;
        if (!(std::cin >> c)) return false;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        if (c == 'y') return true;
        if (c == 'n') return false;
        std::cerr << "Please enter 'y' or 'n'.\n";
    }
}

int main() {
    do {
        Time24 current_time = read_time_24("current time");
        TimePeriod time_past = read_time_period("time past");

        Time24 new_time = time_addition(current_time, time_past);

        show_output(new_time);
    } while (read_yes_no());

	return 0;
}
