#include <iostream>
#include <string>
#include <limits>
#include <cctype>

struct Time_12 {
    int hour;
    int minute;
    bool is_am;
};

struct Time_24 {
    int hour;
    int minute;
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

// true for am, false for pm
static bool read_am_pm(const std::string& name) {
    while (true) {
        std::cout << "AM or PM for " << name << ": ";
        char c;
        if (!(std::cin >> c)) return false;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard leftovers
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        if (c == 'a') return true;
        if (c == 'p') return false;
        std::cerr << "Please enter AM or PM.\n";
    }
}

static Time_12 read_time_12(const std::string& name) {
    Time_12 the_time;
    the_time.hour = read_int_between_a_and_b(name + " hour", 1, 12);
    the_time.minute = read_int_between_a_and_b(name + " minute", 0, 59);
    the_time.is_am = read_am_pm(name + " time");

    return the_time;
}

static Time_24 time_12_to_24(const Time_12& ori_time) {
    Time_24 new_time;

    new_time.hour = ori_time.hour;
    new_time.minute = ori_time.minute;

    if (ori_time.hour == 12 && ori_time.is_am) new_time.hour -= 12;
    if (ori_time.hour != 12 && !ori_time.is_am) new_time.hour += 12;

    return new_time;
}

static int diff_time_24_in_minutes(const Time_24& t1, const Time_24& t2) {
    int minutes = (t2.hour - t1.hour) * 60 + (t2.minute - t1.minute);

    if (minutes >= 0) return minutes;
    return minutes + 1440; // 1440 = 24 * 60
}

int main() {
	Time_12 time_1 = read_time_12("start");
    Time_12 time_2 = read_time_12("future");

    int diff = diff_time_24_in_minutes(time_12_to_24(time_1),
                                       time_12_to_24(time_2));
    
    std::cout << "Difference: " << diff << " minutes.\n";

	return 0;
}
